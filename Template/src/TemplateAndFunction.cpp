#include <iostream>

using namespace std;

// 普通函数和函数模板
void Func1(int a, int b)
{
    cout << "Call for ordinary Func" << endl;
}

template<class T1, class T2>
void Func1(T1 a, T2 b)
{
    cout << "Call for template Func" << endl;
}

// 函数模板重载
template<class T1, class T2>
void Func1(T1 a, T2 b, T2 c)
{
    cout << "Call for reload template Func" << endl;
}

int main()
{
    int a = 10;
    int b = 20;
    Func1(a, b);   // 优先调用了普通函数

    Func1<>(a, b);  // 使用空模板强行调用模板函数

    Func1(a, b, b);  // 调用重载模板函数
    return 0;
}