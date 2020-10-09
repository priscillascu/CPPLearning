#include <iostream>

using namespace std;

void swappointer( int *p1, int *p2 )  // 将指针作为形参，可以改变实参的值，因为是直接对地址内存进行的操作
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    // 地址传递会改变实参
    swappointer(&a, &b);   // 因为函数输入是指针，所以需要将变量的地址传给指针
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}