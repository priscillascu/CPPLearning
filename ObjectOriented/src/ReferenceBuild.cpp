// 引用（reference）是C++对C语言的重要扩充，推荐使用，可以简化指针
/*
注意事项：
1.引用必须初始化，即必须给定其引用的原名，不能 int &b； int &a = 10
2.引用在初始化后不可修改指向的地址，但可以更改地址存储的值
*/
// 引用的本质是指针常量，int * const ref

#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int c = 20;

    // 引用：给变量起别名，语法：数据类型 &别名 = 原名
    int &b = a;
    // int &d;  // 报错，引用没有初始化
    // &b = c;  //报错，引用不可更改
    b = 20;  // 可以更改该地址存放的数据
    cout << a << endl;  // b将a的地址存放的数据修改了，故a的值也变了，因为a只是这个地址存放的数据的代号
    cout << &a << "\t" << &b << endl;  // a与b地址相同
    return 0;
}