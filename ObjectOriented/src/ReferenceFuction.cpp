#include <iostream>

using namespace std;

/* 函数参数有3中传递方式
1.值传递，不修改实参
2.地址传递，可以修改实参
3.引用传递，可以修改实参
*/

// 使用引用传递的交换函数，直接修改地址储存的值
void Swap(int &a, int &b)  // 传入的是变量的地址，赋值给了两个引用
{
    int temp = a;
    a = b;
    b = temp;
}

// 引用可以作为函数的返回值，但是不能返回局部变量引用，因为会释放
int &RefTest()  // 函数类型为 int&，返回引用类型
{
    int a = 10; // 局部变量
    // return a;  // 无法返回局部变量引用

    static int b = 20;
    return b;   // 用static改为了静态变量，可以返回其引用了，在程序结束后才释放
}

int main()
{
    int a = 1;
    int b = 2;
    Swap(a, b);  // 将变量的地址传递给引用别名
    cout << "a = " << a << "\t" << "b = " << b << endl;  // 修改了实参

    int &ref = RefTest();
    cout << "ref = " << ref << endl;

    RefTest() = 100;  // 引用返回值可以作为左值，在等号左边进行赋值，所以ref变量也是100，因为它是这个函数返回值的别名
    //将原名赋值，修改了别名
    cout << "ref = " << ref << endl;

    return 0;
}