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

指针也可以用`const`来进行修饰，根据`const`后接内容的不同，按照实现不同的功能分为：
**常量指针：**`const int * p;`用`const`修饰`int`，故指针所指向的内存所存储的内容是不可更改的，但是指针指向哪个内存是可以修改的。
**指针常量：**`int * const p;`用`const`修饰`p`，即指针指向的地址不可修改，但是该地址存储的内容可以更改。

指针还可以用来表示数组，**数组名就是地址**，只需将数组名直接赋值给指针变量即可，不需要再加上`&`符号。
```
int arr[];
int *p = arr;
```
如果要使用指针来进行对数组的遍历，只需要解引用，然后再将指针变量自增即可。
```
for(int i; i < 5; ++I)
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
- **堆区：** 由用户分配和释放，也可以在程序结束时自动回收。使用`new` `delete`来进行堆区地址开辟和释放。可以用`new`来开辟新数组
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
- 引用必须初始化，即必须给定其引用的原名，不能`int &b；` `int &a = 10`，如果不想初始化，直接赋值给引用，则可以`const int &a = 10`
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

顺便测试一下我的Ｌｉｎｕｘ能不能传这个库

