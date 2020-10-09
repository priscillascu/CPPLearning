#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter a val:";
    cin >> a;
    cout << "Enter b val:";
    cin >> b;

    c = (a > b ? a : b);  // 如果a>b，则返回a，否则返回b，然后赋值给c
    cout << "c = " << c << endl;

    (a > b ? a : b) = 100;  // 三目运算返回的结果是变量，可以继续对返回的变量进行赋值
    cout << "a = " << a << endl << "b = " << b << endl;
    return 0;
}