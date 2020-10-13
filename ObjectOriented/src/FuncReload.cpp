#include <iostream>

using namespace std;

// 函数名可以相同：函数重载
/*
1.同一个作用域下：全局、局部
2.函数名相同
3.函数参数类型或者个数或者顺序不同
*/

/*
注意事项
1.引用作为重载条件
2.默认参数
*/

void func()
{
    cout << "call for func" << endl;
}

void func(int a)  // 作用域都为全局，函数名相同，多了一个int a的参数，重载
{
    cout << "call for reload func" << endl;
}

void func(char b)  // 参数类型不同
{
    cout << "call for another func" << endl;
}

// 1.引用作为重载条件
void RefFunc(int &a)
{
    cout << "call for func by reference" << endl;
}

void RefFunc(const int &a)  // const引用和引用两者参数类型不同
{
    cout << "call for func by const reference" << endl;
}

// 2.重载遇到默认参数，此时调用时如果只传递一个值，则无法重载，二义性
// 尽量避免默认参数
void RefFunc2(int a, int b = 10)
{
    cout << "call for func2 with default value" << endl;
}

void RefFunc2(int a)
{
    cout << "call for func2" << endl;
}

int main()
{
    func();
    func(10);  // 调用了重载函数
    func('a'); 

    int a = 10;
    RefFunc(a);  // 因为a是变量，没有const，所以调用没有加const的

    const int b = 20;
    RefFunc(b);  // b是const，故调用加了const的
    RefFunc(1);  // 直接传常数也是调用了const的，因为int &a = 10;不合法，const int &a = 10合法

    return 0;
}