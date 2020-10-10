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









