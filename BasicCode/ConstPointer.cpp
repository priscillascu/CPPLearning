#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    cout << "address of a is " << &a << endl;
    cout << "address of b is " << &b << endl;

    //常量指针和指针常量可以通过看const后面跟的是什么来决定
    // 常量指针：指针的指向可以改，但是所指的内存存放的数据不可修改
    const int *p1 = &a;
    cout << "p1 value is " << p1 << endl;
    // *p1 = 20;  // 常量指针所指的内存存放的数据不可修改，会报错
    p1 = &b;  // 修改常量指针的指向是可以的
    cout << "new p1 value is " << p1 << endl;

    // 指针常量，const放在*后面，指针的指向不可以改，但是指向的内存存放的值是可以改的
    int * const p2 = &a;
    cout << "p2 pointed value is " << *p2 <<endl;
    *p2 = 100;  // 指针常量指向的内存存放的值可以修改，即a = 100
    // p2 = &b;  // 指针常量的指向不可修改，报错
    cout << "new p2 pointed value is " << *p2 << endl;

    // const即修饰指针，又修饰常量，指针的指向和指向的内存存放的值都不可改
    const int * const p3 = &a;
    // *p3 = 100;
    // p3 = &b;   // 都会报错
    return 0;
}