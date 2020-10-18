# C++笔记
*本笔记使用VS Code编写，使用插件为：*

`Markdown All in One`

`Markdown Preview Github Styling`
## 前言
一些诸如for循环、while循环等简单的语法此处就不再赘述了，本笔记主要讲一些以前学习C++的时候没有注意到的一些细节，诸如指针、函数等。
## VS Code编译环境配置
因为Visual Studio太臃肿了，所以我所有的编译都是使用的VS Code + MinGW + GDB的配置，这里简单记录一下，因为网上教程都很多，就不展开来讲了。

安装MinGW可以参考这篇博客：
[MinGW安装教程](https://blog.csdn.net/weixin_43775264/article/details/105711844)
如果出现一直下载不起的情况，可以去[这个网址](https://qa.debian.org/watch/sf.php/mingw)下载单个所需的文件，然后将其放在`$MINGW_ROOT/var/cache/mingw-get/packages`

最后在环境变量中的PATH项添加MinGW即可在VS Code的Terminal直接使用gcc，还可以使用git，非常方便。

此方法无需配置VS Code编译路径什么的，非常高效便捷，换台电脑一样冲，只不过调试啥的用GDB可能没有VS Code自带的debug看着爽，但是**酷**就对了。

# 基础部分
## 指针
指针不要想复杂了，就是一个用来储存地址的变量，根据所储存的地址对应的变量类型来进行定义。

```
int a = 10;
int *p;
p = &a;
cout << *p;
```
使用`*`符号来定义一个指针变量，然后使用`&`符号来取出变量的地址，并将其赋值给指针，也就是说用`&`取出来的地址需要放进一个由`*`定义的指针变量里，那么如何表示指针指向的地址的数据呢？很简单，直接使用`*p`进行解引用，即可表示地址的内容。

如果直接对指针变量赋值，则容易导致`野指针`，此时无法进行解引用操作：
```
int a = 10;
int *b = (int*)a;  // 直接让b指向了地址0XA，即10的内存，野指针
int *c = &a;  // 让指针c指向了a的地址
cout << &a << endl;  
cout << b << "\t" << c << endl;  // 输出b存的地址为0xa，c存的地址为a的地址
// cout << *b << "\t" << *c << endl;  // 无法对野指针解引用
```

指针也可以用`const`来进行修饰，根据`const`后接内容的不同，按照实现不同的功能分为：
**常量指针：**`const int * p;`用`const`修饰`int`，故指针所指向的内存所存储的内容是不可更改的，但是指针指向哪个内存是可以修改的。
**指针常量：**`int * const p;`用`const`修饰`p`，即指针指向的地址不可修改，但是该地址存储的内容可以更改。

指针还可以用来表示数组，**数组名就是地址**，只需将数组名直接赋值给指针变量即可，不需要再加上`&`符号。
```
int arr[];
int *p = arr;
```
如果要使用指针来进行对数组的遍历，只需要解引用，然后再将指针变量自增即可，此时指针会自动根据储存数据类型，移动到下一个数组值：
```
for(int i; i < 5; ++i)
{
    cout << *p;
    p++;
}
```
也可以直接把指针当作一个数组来进行操作，例如冒泡排序
```
// 冒泡排序，输入为一个数组，故可以使用指针来存放数组开头地址，*arr
void BubbleSort(int *arr, int arrLength)
{
    for (int readyNum = 0; readyNum < arrLength - 1; ++readyNum)
    {
        for (int selectNum = 0; selectNum < arrLength - 1 - readyNum; ++selectNum)
        {
            if(arr[selectNum] > arr[selectNum + 1])
            {
                int temp = arr[selectNum];
                arr[selectNum] = arr[selectNum + 1];
                arr[selectNum + 1] = temp;
            }
        }   
    }
}

BubbleSort(arr, arrLength);    // 因为数组名就是数组第一个元素的地址，故不需要&符号，直接写数组名就是传入地址了
```
即用指针遍历数组有两种方式，一种是把指针像数组一样用`[]`进行操作，还有一种则是`*`解引用，然后自增
```
for (int i = 0; i < sizeArr; ++i)
{
    cout << pArr[i] << endl;
}

for (int j = 0; j < sizeArr; ++j)
{
    cout << *pArr << endl;
    pArr++;
}
```
## 函数
函数需要有定义和声明，定义就是完整的把函数功能写出来，需要占用一些内存。
```
void xxx()
{
    .....;
}
```
而函数的声明则不用占用内存，只是告诉编译器有这个函数，它的类型什么什么的，就像变量要先声明一样，写法很简单，就是函数定义的第一句话加上`；`。
```
void xxx();
```
如果把所有函数，包括主函数写在同一个文件里，则需要注意，如果写在主函数之前，则不需要声明，写在主函数之后则需要声明。

函数还是分文件编写比较好，一般来说一个函数需要两个文件：1.源文件`.cpp`，2.头文件`.hpp`。
**源文件**内写函数的详细定义，并在开头时包含对应的头文件
```
#include "SwapNum.hpp"

void swapnum(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}
```
头文件则需要声明该函数，如有必要，需要包含`iostream`和`using namespace std;`，并且，为了防止同一个头文件被多次引用而导致的**重定义**错误，需要将头文件内容放入`#ifndef`和`#endif`块中
```
#ifndef SWAPNUM_HPP
#define SWAPNUM_HPP

#include <iostream>
using namespace std;
void swapnum(int num1, int num2);

#endif
```
函数的类型就是返回值的类型，没有返回值就是`void`，如果返回一个引用，则是`int &`；如果返回一个地址，则是`int *`。调用函数时，需要设置与函数返回类型对应的接收对象，比如对于返回地址的函数，需要定义一个指针来接收函数返回值。这里存在一个关系，定义函数时的数据类型，是用来接收函数的返回值的对应的类型，而调用函数也需要定义一个用于接收函数返回值的变量，所以，**定义函数的类型与调用函数时定义的变量类型一致**，例如：
```
// 定义一个返回值为引用的函数
int &ReturnRef()
{
    static int a = 10;
    return a;
}

// 定义一个返回值为地址的函数
int *ReturnAddress()
{
    static int b = 20;
    return &b;
}

// 调用返回引用的函数
int &Ref = ReturnRef();
cout << "Ref is " << Ref << endl;  // 10

// 调用返回地址的函数    
int *p = ReturnAddress();
cout << "Value in p is " << *p << endl;  // 20
```

函数有个重要概念，**实参和形参**，很好理解，形参就是一个形式上的参数，即定义函数时，函数名后跟的参数，而实参则是调用函数时，所使用的参数。定义函数`void Func(int a)`，其中参数`a`就是形参。调用函数时，`Func(b);`，其中`b`就是实参。函数运行时，将实参**复制**了一份给形参，函数改变形参，对实参没有影响，这种方式也叫做**值传递**，占用空间较多。

那么如果我想在函数中把实参也一起修改了，这就需要使用**地址传递**，显然，此时就需要使用指针来进行地址传递。
```
void swappointer( int *p1, int *p2 )  // 将指针作为形参，可以改变实参的值，因为是直接对地址内存进行的操作
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```
在使用上述定义的地址传递函数时，只需要将变量的地址传入即可实现修改实参的功能，如果使用值传递，则只会修改形参值，实参是不会改变的。
```
int a = 10;
int b = 20;
// 地址传递会改变实参
swappointer(&a, &b);   // 因为函数输入是指针，所以需要将变量的地址传给指针
```
除了用指针以外，还可以使用数组来进行地址传递，直接把数组写为形参，使用时直接写数组名即可
```
void SwapArrayNum(int arr[])  // 数组都是地址传递，因为数组名就是地址，实参会改变
{
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

SwapArrayNum(arr);
```

## 结构体
结构体就是一种自己定义的数据类型，只不过该数据类型内含了很多其他元素，即成员列表。使用`struct`来定义一个结构体，并在里面写入包含的成员列表
```
struct StudentInfo
{
    // 结构的成员列表
    string stuName;
    int stuAge;
    int finalScore;
};
```
定义好了结构体之后，就可以定义结构体变量了，类似于其他变量的定义，`StudentInfo stu`即可定义一个名为`stu`的`StudentInfo`类型的结构体变量，推荐的定义方式有两种，当然，也可以**不先写入成员列表**。
首先是挨个写入结构体变量的成员列表：
```
// 第一种，一个一个赋值
StudentInfo boy1;  // 可以省略关键字struct
boy1.stuName = "Bob";
boy1.stuAge = 10;
boy1.finalScore = 100;
```
第二种则是一次性按顺序写入结构体变量的成员列表：
```
// 第二种，创建时按顺序赋值
struct StudentInfo boy2 = {"Tom", 20, 80};
```
还有一种不推荐的方式，就是在定义结构体时，在最后一个`;`前写下结构体变量的名字。

定义好了结构体变量之后便可以使用`.`来读写相应的成员列表，比如可以在只定义了结构体变量，但是没写入成员列表的情况下，补充成员列表信息。
```
boy3.stuName = "Alice";
boy3.stuAge = 12;
boy3.finalScore = 70;
cout << "Name: " << boy3.stuName << endl;
```

结构体变量和其他变量类似，也有函数、指针、数组操作。
**结构体数组**与数组的定义类似，然后每个结构体变量赋值可以用一次性按顺序赋值的方式，当然也可以先不赋值
```
// 创建结构体数组，并给结构体元素赋值
StudentInfo stuArray[3] = 
{
    {"Bob", 18, 100},
    {"Tom", 20, 110},
    {"Jay", 30, 200}
};

stuArray[2].stuAge = 40;  // 修改结构体数组的值
```

# 面对对象
## 内存
首先一个很基础的概念就是局部变量和全局变量，只要是在函数外声明的都是全局变量，在函数体内声明的就是局部变量。C++程序在执行时，将内存分为**4**个区域：
- **代码区：** 存放函数体的二进制代码，代码区是**共享**以及**只读**的，当需要频繁使用程序时，只需要在内存中有一份代码即可，这就是代码区共享的意义。
- **全局区：** 存放全局变量、静态变量、常量。在全局区中由根据数据类型的不同而分为**常量区**和**静态区**，它们的存储区域是一起的。常量区存放一些`string` `const`修饰的不可更改的量，静态区存放被`static`修饰的局部、全局变量，直到程序全部结束之后才会被释放，但是作用域仍为局部、全局。
- **栈区：** 存放函数的参数值、局部变量，编译器自动分配和释放。栈区中的变量如果没有被`static`修饰，则会在函数结束时释放掉，此时无法返回该变量的地址：
```
int *TestFunc()
{
    int aLocal = 10;  // 局部变量，存放在栈区
    // return &aLocal;  // 返回局部变量地址，栈区数据在函数执行完之后自动释放，所以返回的不是真正的局部变量
    // 会报错，程序崩溃

    static int bLocal = 20;  // static声明静态变量，不会被立即释放
    return &bLocal;  // 此时可以返回其地址
}
```
- **堆区：** 由用户分配和释放，也可以在程序结束时自动回收。使用`new` `delete`来进行堆区地址开辟和释放。可以用`new`来开辟新数组，然后使用`delete 地址`来释放，对于数组则只需`delete [] 数组名`
```
// new在堆区开辟数组
int *pArr = new int[10];  // 用[]来创建堆区数组，返回值是地址
for (int i = 0; i < 10; ++i)
{
    pArr[i] = i;  // 直接把该指针当作数组来进行操作即可
}
for (int j = 0; j < 10; ++j)
{
    cout << pArr[j] << endl;
}

delete [] pArr;  // []释放堆区数组
```
因为堆区地址不会被程序自动释放，所以可以在函数中用`new`创建堆区变量，返回地址
```
int *HeapFunc()
{
    // 指针仍是局部变量，存放在栈区，但其存放的地址是指向堆区的
    int *pHeap = new int(10);  // new开辟堆区，返回新内存的地址，用()来创建数据，该地址存放的数据为10
    return pHeap;
}
```
不同的区域存放不同数据，有着不同的生命周期，更加灵活。

## 引用
引用（reference）是C++对C语言的重要扩充，**推荐使用**，可以简化指针，引用的本质就是**指针常量**`int * const ref`，当我们创建一个引用时，编译器发现是引用，就会自动转换为指针常量：`int &ref = a`变为`int * const ref = &a`，`ref = 10`变为`*ref = 10`，故引用是在进行地址操作。

创建一个引用，可以理解为创建了一个变量的别名：`int &b = a；`，将变量`a`的地址赋给了引用`b`，通过直接修改`b = 10`即可实现将`a`的地址存储的数据改为10的操作。

**注意事项**：
- 引用必须初始化，即必须给定其引用的原名，**不能**`int &b；` `int &a = 10`，如果不想初始化，直接赋值给引用，则可以`const int &a = 10`
- 引用在初始化后不可修改指向的地址，但可以更改地址存储的值，这也是指针常量的特性

## 引用与函数
引用可以作为函数的形参进行引用传递，也可以作为函数的返回值，不能返回**局部变量**的引用。

引用传递也是一种地址传递，所以可以修改实参的值，传递格式为：
- 在函数中使用`数据类型 &a`来声明一个引用参数
- 在调用时直接传递**变量名**，不需要取地址，因为引用的使用格式就是这样
```
// 使用引用传递的交换函数，直接修改地址储存的值
void Swap(int &a, int &b)  // 传入的是变量的地址，赋值给了两个引用
{
    int temp = a;
    a = b;
    b = temp;
}

int a = 1;
int b = 2;
Swap(a, b);  // 将变量的地址传递给引用别名
cout << "a = " << a << "\t" << "b = " << b << endl;  // 修改了实参
```
引用可以作为函数的返回值，只需将函数声明为一个返回值为引用`数据类型&`，然后调用该函数时，需要声明一个引用来接收函数返回值，该返回值还可以作为左值，在等号左边进行赋值，需要注意的是，不能返回局部变量的引用，但是可以通过将局部变量变为`static`，改变生命周期，实现引用返回，这点和前面讲的局部变量地址返回一样
```
int &RefTest()  // 函数类型为 int&，返回引用类型
{
    int a = 10; // 局部变量
    // return a;  // 无法返回局部变量引用

    static int b = 20;
    return b;   // 用static改为了静态变量，可以返回其引用了，在程序结束后才释放
}
int &ref = RefTest();
RefTest() = 100;  // 引用返回值可以作为左值，在等号左边进行赋值，所以ref变量也是100，因为它是这个函数返回值的别名
```
对返回为引用的函数进行左值赋值，可以更改接收其返回值的引用变量，因为它们都是在对同一个地址进行操作。

# 类和对象
类是面对对象的一个重要操作，声明一个类，然后用类创建一个对象，这一步也是C++面对对象的三大特质：
- 封装
- 继承
- 多态

中的**封装**特质。

对象，万事万物都是对象，对象有自己的属性和行为，对应于类的成员变量和成员函数。对象可以用类和结构体创建，区别在于：

**类的成员默认为私有private，结构的成员默认为公有。**

声明类的方法与创建结构体非常类似，类也可以用`new`在堆区进行创建，返回其指针`对象指针 = new 类名`。声明一个类有三个基本元素：
- 访问权限，公共、私有、保护
- 成员变量，也可以称为属性，一般是一些变量
- 成员函数，也称行为，一般是函数的形式
```
// 类，设计一个圆类，求其周长
// 属性通常是一些变量，行为一般是函数
// 通过一个类，可以创建一个对象，实例化
// 属性也称为成员变量、成员属性
// 行为也称为成员函数
class Circle
{
	// 访问权限
public:
	// 属性
	int radiusM;
	// 行为：用函数来进行，本例为获取圆周长
	double CircleLength()
	{
		return 2*PI*radiusM;
	}
};

//　通过使用圆类，创建一个对象，圆
Circle c1;
c1.radiusM = 10;
cout << "Length of this circle is " << c1.CircleLength() << endl;
```
类的权限有三种：
- **公共public：** 类内、外都可访问
- **保护protected：** 类内可以访问，类外不行，子类可以访问父类
- **私有private：** 类内可以访问，类外不行，子类也不行

**类内**指的就是在声明类的`class`中。

**友元**`friend`能够让一个函数或者类，访问另一个类的私有变量，友元有三种实现方法：
- 全局函数做友元，只需要在类的最前面声明一下这个全局函数，然后再正常定义这个函数即可：
```
class Person
{
    // 声明一个友元函数，让这个函数可以访问私有成员
    friend void FriendFun(Person &p1);
    ......

// 定义一个全局函数，可以访问Person类的私有成员
void FriendFun(Person &p1)
{
    cout << "I can access the private : " << p1.passWord << endl;
}
```
- 类做友元，同理让一个类可以访问另一个类的私有成员，声明方法一样，在类的定义最开始，声明一下需要设为友元的类即可：
```
class Person
{
    friend class Friend;
    ......
}
```
- 让另一个类的成员函数做友元，和让全局函数做友元类似，只不过需要在函数声明的时候加上作用域即可
```
class Person
{
    friend void Friend::FriendFunc();
    ......
}
```



一般来说，**成员变量**都写在`private`中，通过在`public`中写接口函数来实现读写操作
```
class Person
{
public:
	// 写姓名，为私有属性Name设置了类外的可读可写接口
	void SetName(string inName)
	{
		Name = inName;
	}
	// 读姓名
	string GetName()
	{
		return Name;
	}

	// 年龄Age只有只读接口
	int GetAge()
	{
		return Age;
	}

	// Num只有只写接口
	void SetNum(int inNum)
	{
		Num = inNum;	
	}

private:  // private中的成员可以通过public设计一个接口来赋予权限
	string Name;  // 赋予可读可写权限
	int Age = 10;  // 赋予只读权限
	int Num;  // 赋予只写权限
};
```
还是建议在**类里只声明函数**，定义函数在类外，此时需要加上作用域，但是函数体内的变量可以不用：
```
class Person
{
public:
    int age;
    void Fun1();
}

// 类外使用作用域定义函数，变量可要可不要作用域
void Person::Fun1()
{
    cout << age << endl;
}
```
## 构造和析构函数
对象的初始化和清除的工作是C++利用构造(Construct)和析构(Destruct)函数实现的，编译器会自动调用构造和析构函数，如果我们不写构造和析构，编译器也会自动帮我们写一个空实现的构造和析构函数。

声明构造和析构函数非常简单，直接`类名()`和`~类名()`，可以直接在`public`中定义，也可以在类外声明，只不过需要加上定义域`类名::`，然后再在`public`中声明函数，通常成员属性的赋值是可以写在构造函数里的。
```
class Person
{
private:
    /* data */
public:
    Person(/* args */);  // 在公共权限声明构造和析构
    ~Person();
};
// 构造函数，函数名与类一样，无返回值不需要写void，有参数可以重载，创建对象时自动调用一次构造函数
// 如果不写，编译器也会自动生成，只不过是空函数了
Person::Person(/* args */)
{
    cout << "Call for Constructed function" << endl;
}
// 析构函数名与类一样，前面加一个~，不可以有参数，不能重载，不需要写void
Person::~Person()  
{
    cout << "Call for Destructor" << endl;
}

Person p1;  // 创建对象之后，会自动调用一次构造函数，不需要去手动调用，类释放时自动调用一次析构函数来清除对象
```
如果一个类A里面调用了另一个类B，则是先构造里面的类B，再构造外面的类A，析构的时候则是**先进后出**，先析构A，再析构B
### 构造函数分类和调用
根据构造函数的参数和类型可以分为
- 无参构造，也是默认的构造函数，因为没有参数，所以不能重载
- 有参构造，可以传入一些参数，因此可以重载
- 拷贝构造，将一个对象的引用作为`const`传入

其中无参构造和有参构造也被称为**普通构造**。如果用户定义了有参构造函数，则编译器不再提供无参构造，但是会提供一个默认的拷贝构造，即**此时只能使用有参调用和拷贝调用**；如果用户定义了拷贝构造，则编译器不会提供其他构造函数即**此时只能使用拷贝调用**。
```
class Person
{
private:
    /* data */
public:
    Person();  // 构造函数可以重载
    Person(int a);
    Person(const Person &p);  // 拷贝构造
    ~Person();
};

Person::Person()  // 无参构造，也是默认的情况
{
    cout << "Call for default construct function" << endl;
}
Person::Person(int a)  // 有参构造
{
    cout << "Call for construct function with parameter" << endl;
}
Person::Person(const Person &p)  // 拷贝构造，写法为参数用const 类名 对象引用，将会把传入的对象属性复制一份
{
    cout << "Call for Copy construct function" << endl;
}

Person::~Person()
{
    cout << "Call for Destruct function"  << endl;
}
```
构造函数的**调用**按照写法可以分为3种
- 括号法
- 显式法
- 隐式法

```
Person p1;  // 默认构造函数，即无参构造

// 1.括号法
// Person p1();  // 调用无参构造不要写()了，会被认为是函数声明
Person p2(10);  // 括号法调用有参构造
Person p3(p2);  // 传入一个对象，调用拷贝构造，还会复制一份p2属性给p3

// 2.显式法
Person p4 = Person(10);  // 直接调用有参构造
Person p5 = Person(p2);  // 直接调用拷贝构造

// 3.隐式法，把显式法省略了一些
Person p6 = 10;  // 相当于Person p6 = Person(10);
Person p7 = p2;  // 拷贝构造
```
需要注意使用无参构造时，不能写`Person p1();`，因为这样会被认为是函数声明

可以通过构造函数**初始化列表**的形式，来为对象赋值，只需要在定义构造函数的时候，在函数名后面依次跟上对象属性赋值，然后将要传递进去的属性值，写为函数的参数传入
```
Person::Person(string name, int age): Name(name), Age(age)  // 定义了一个使用列表初始化对象的构造函数
{
    cout << "Call for list" << endl;
}

Person p2 = Person("Tom", 20);
```
### 拷贝构造注意事项
拷贝构造会在以下三种情况被调用：
- 使用一个已经创建好了的对象来初始化一个新对象
```
Person p1(20);  // 调用有参构造函数
Person p2(p1);  // 调用拷贝构造函数
```

- 将对象以值传递的方式给函数参数
```
void CopyConstruct(Person p)  // 此时，p会被复制一份，调用了拷贝构造
```

- *这一项我实验失败了，将对象作为函数的局部变量，以值的方式返回
```
Person ReturnCopy()
{
    Person p1;
    return p1;  // 以值的方式返回局部对象，会复制一份
}
```
**浅拷贝：** 简单的复制拷贝操作，系统默认的拷贝构造也是浅拷贝

**深拷贝：** 使用`new`在堆区开辟内存来存放拷贝的数据，要注意指针的应用
```
Person::Person(const Person &p)  // 深拷贝，创建一个新的堆区来存储拷贝的数据
{
    Age = new int(*p.Age);
    Height = new int(*p.Height);
    cout << "Call for Copy construct function" << endl;
}
```
### 静态成员
静态成员就是在类里的成员变量和成员函数前加上`static`，静态成员变量类似于将类里的变量赋值，但是在内存里只保存了一份变量值，所有的被这个类声明的对象都将共享这个变量，**类内声明，类外初始化**；静态成员函数也是在内存里只保存了一份，让所有被这个类创建的对象调用，注意，静态成员函数只能访问静态成员变量，但是非静态成员函数都可以访问。
```
class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
    static void func1();  // 声明一个静态成员函数，通过类名调用可以直接修改类定义里的静态成员变量
    static int Age;  // 静态成员变量，数据是共享的，可以被调用
    int Num;  // 非静态变量，使用时需要先声明一个对象才能访问其所在的内存
    void func2();  // 非静态成员函数，需要通过对象调用
};

int Person::Age;  // 静态成员类内定义，类外赋值

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void Person::func1()  // 在类外定义一个静态成员函数，此时不用声明static
{
    // Person::Num = 123;  // 非静态变量不能调用，因为没有声明类，函数不知道改变哪个内存
    Person::Age = 20;  // 静态成员函数可以访问静态成员属性
    cout << "Call for static function" << endl;
}
```
## 对象模型
**成员变量和成员函数分开存储**

类内的成员变量和成员函数是分开存储的，也就是说，无论你类里定义了多少成员变量、成员函数，类定义的对象大小都只和类里的**非静态成员变量**有关，注意空类定义的对象大小为1
```
class PersonNonEmpty
{
private:
    /* data */
public:
    int Name;  // 非静态成员变量
    char Age;

    static int Num;

    void func1() {}
    static void func2() {}
    PersonNonEmpty(/* args */);
    ~PersonNonEmpty();
};

PersonNonEmpty p2;  // 类定义的对象大小只与类内的非静态成员变量有关
cout << "Size of object p2 is " << sizeof(p2) << endl;
```
此时，对象`p2`的大小只等于`int`加上`char`，和`static`成员变量，以及成员函数无关，即他们只用在内存中保存一份，用以对象调用，也就是说多个同类声明的对象会公用一块代码，这一块代码通过`this`指针来区分对象，谁调用，`this`就指向谁

### this指针
`this`指针不需要定义，直接使用即可，指向调用成员函数的对象，需要注意根据应用场景的不同，是否需要判断是否为空指针`this == NULL`，`this`指针还是一个指针常量，其指向不可修改，只能是指向调用成员函数的对象，不能手动修改为`NULL`等。

用途有两种：
- 形参与成员变量重名了，可以用`this`来区分
- 在类的**非静态成员函数**中返回对象本身，可以直接`return *this`
```
class Person
{
private:
    /* data */
public:
    int Age;
    Person(int Age);
    ~Person();
};

Person::Person(int Age)
{
    this->Age = Age;  // 当成员属性和传入的参数同名了，就需要使用this，否则名称冲突，结果错误
}
```
**在返回对象本身的时候，要注意函数返回值是否需要引用**，可以认为返回值有`&`引用就可以直接修改对象的参数，而没有引用的话，则会创建一个匿名对象，会被析构，引起bug
```
// 不使用引用，直接返回一个对象，则会创建一个新对象，真正调用的对象只进行了一次加法
// 后面的几次加法都是在接受返回值的新对象上进行的，因为是匿名对象，所以加法结束后全部析构
// 形参用引用的方式可以省去复制实参，节约空间，可以改变实参
Person Person::PersonAdd(Person &p)  
{
    this->Age += p.Age;  // 让调用这个函数的对象的Age属性加上传入的对象的age
    return *this;  // 返回对象本体
}

// 用引用来接受返回的对象，即改变了实参的值，执行完之后对象不会被析构
Person &Person::PersonAddRef(Person &p)
{
    this->Age += p.Age;
    return *this;
}

int main()
{
    Person p1(10);
    cout << "p1 age is " << p1.Age << endl;  // this将会指向p1

    // 没有使用引用，则只进行了第一次的p2.PersonAdd(p1)
    // 后面的.PersonAdd(p1)都是在上一次调用后返回的新对象的基础上进行
    // 因为是匿名对象，所以结束后被析构，p2还是就是第一次调用的值
    Person p2(10);
    p2.PersonAdd(p1).PersonAdd(p1);
    cout << "p2 age is " << p2.Age << endl;  // p2 = 20

    // 使用引用，相当于直接修改了p3，中间不存在新对象
    Person p3(10);
    p3.PersonAddRef(p1).PersonAddRef(p1);
    cout << "p3 age is " << p3.Age << endl;  // p3 = 30
    return 0;
}
```
### 常函数和常对象
C++在类中声明一个常函数，只需要在函数的声明后面加一个`const`
```
class Person
{
private:
    /* data */
public:
    int Age;
    mutable int Num;  // 加上mutable(可变的)之后，可以在常函数中修改

    Person(/* args */);
    ~Person();

    void ShowPerson();
    void ShowConst() const;  // 常函数
};

void Person::ShowConst() const  // 常函数
{
    // Age = 100;  // 无法修改this指针的指向值
    Num = 100; // 可以修改mutable变量
}
```
`this`指针本来是一个指针`Person * const this`，然后被常函数的const修饰了，就将`this`指针定义成了`const Person * const this`，此时无法修改this指针的指向值。

常对象则是一个被`const`修饰的对象，不能修改属性，也不能调用非常对象函数
```
const Person p1;  // 常对象
p1.Num = 100;  // 常对象的mutable也可以修改，常对象只能调用常函数
// p1.ShowPerson();  // 常对象不能调用非常函数
p1.ShowConst();
```
**但是只要是`mutable`修饰的变量，就可以被常对象和常函数调用、修改**

### 继承
当多个类使用**同样的代码**时，可以通过继承的方式，减少代码量，但是不会减少内存，实际上子类还是会创建一下父类。

C++允许一个类继承多个类，但是**不推荐**这样使用，因为可能会出现数据重复定义的**菱形问题**，继承的语法很简单：

`class 子类 : 继承方式 父类1, 继承方式2 父类2`

继承有3种方式，对应于三种权限，public，private，protected
- 1.public继承，则父类的除private，public和protected权限原封不动继承
- 2.protected继承，还是不能继承父类的private，但是其他权限全部继承，但是全部继承为protected
- 3.private继承，还是不能继承父类的private，会将其他权限继承为private
  
继承其实把父类的所有属性，包括私有，复制给了子类，只不过编译器把私有属性隐藏了，因此继承的子类大小=子类自身成员属性+父类继承属性。继承创建的类，会**先构造父类，再构造子类，先析构子类，再析构父类**，先进后出。

当子类和父类有同名成员时，子类的可以直接访问，父类的需要加一个作用域：对象.父类::成员，包括重载，也要加作用域。

**菱形问题**又称菱形继承、钻石继承，指当两个子类继承了同一个父类，然后这两个子类又同时被另一个子类继承，存在重复定义，调用二义性
```
/*
                   Base
                    |
            child1      child2
                    |
                    child3
*/
```
这时，如果直接调用child3中的继承属性，则会报错，因为编译器不知道这个属性是来自child1还是child2，可以通过指明作用域来解决
```
// 直接继承，存在菱形问题
class Child1 : public Base {};
class Child2 : public Base {};
class Child3 : public Child1, public Child2 {};

Child3 p1;
// p1.Age = 10;  // 指向不明，可能来自Child1和Child2
p1.Child1::Age = 10;
p1.Child2::Age = 20;
cout << p1.Child1::Age << "\t" << p1.Child2::Age << endl;  // 用作用域区分
```
但是系统存储了两份同样含义的属性数据，这是多余的，对于一个对象来说，有一份属性数据就够了，这时就可以使用**虚继承**来解决：
```
// 菱形继承导致了数据有两份，资源浪费，使用虚继承解决，virtual
class Child4 : virtual public Base {};
class Child5 : virtual public Base {};
class Child6 : public Child4, public Child5 {};

Child6 p2;
p2.Age = 30;
cout << p2.Age << endl;
```
**虚继承**的原理很简单，可以通过`gdb`调试打印对象数据得知：
```
(gdb) p p2
$1 = {<Child4> = {<Base> = {Age = 0}, _vptr.Child4 = 0x405628 <vtable for Child6+24>}, <Child5> = {
    _vptr.Child5 = 0x405640 <vtable for Child6+48>}, <No data fields>}
```
虚继承是会创建一个vptr，指向vtable的某个偏移量，多个虚继承都只会指向一个vtable的偏移值，就只会创建一份数据。
