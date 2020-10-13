// 内存的全局区，存放全局变量、静态变量、常量
// 只要是在函数外声明的都是全局变量，不管有没有const，都放在全局区
// 在函数内的就是局部变量，不在全局区中
// 如果是静态变量，static，则放在全局区

#include <iostream>

using namespace std;

// 函数体外定义的变量为全局变量
int aGlobal = 10;
int bGlobal = 10;

int main()
{
    // 局部变量：写在函数体内的变量都是局部变量
    int aLocal = 10;
    int bLocal = 10;

    // 静态变量，也放在全局区
    static int aStatic = 10;
    static int bStatic = 10;

    // 常量：字符串常量、const修饰的变量，取决于其修饰的变量是局部还是全局
    string str1 = "Hello";


    cout << "Local variable a address is " << &aLocal << endl;  // 两个相邻的变量地址相差4
    cout << "Local variable b address is " << &bLocal << endl;

    cout << "Global variable a address is " << &aGlobal << endl;  // 全局变量存放位置与局部变量不一样，全局变量在全局区中
    cout << "Global variable b address is " << &bGlobal << endl;

    cout << "Static variable a address is " << &aStatic << endl;  // 静态变量也放在全局区中，与全局变量地址很接近
    cout << "Static variable b address is " << &bStatic << endl;

    cout << "String constant address is " << &str1 << endl;  // 局部变量字符串常量地址放在局部区

    return 0;
}