#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p;
    p = &a;  // 将a的地址赋值给指针p

    cout << "address of a is " << &a << endl;
    cout << "value of p is " << p << endl;

    // 指针前面加*，为解引用，找到指针指向的内存中的数据，即*p = a
    cout << "p pointed value is " << *p <<endl;

    // 通过解引用来修改指针指向的内存的数据，因为这个内存的数据被修改了，所以a的值也会变
    *p = 20;
    cout << "new p pointed value is " << *p << endl;
    cout << "after that, a value is " << a << endl;

    // 指针也是一种数据类型，其占用内存为8个字节（64位系统），32位系统为4字节
    cout << "size of pointer p is " << sizeof(p) << endl;

    // 空指针：指向0内存，用于初始化指针变量，该内存是不可访问的，不可修改该内存的数据
    int *pn = NULL;
    cout << "null pointer is " << pn << endl;

    // 野指针，指针指向非法的内存空间，即随便指向一个内存，应避免出现野指针
    //int *p2 = (int *)0x1100;   // 把内存中的随便一个0x1100通过(int *)强行转为指针内存，野指针
    
    return 0;
}