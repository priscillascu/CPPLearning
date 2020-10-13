#include <iostream>

using namespace std;

// 1.函数默认参数，形参是可以有默认值的，如果某个位置有了默认参数，则其后面的参数都必须有默认值
// 不能 int fun(int a = 1, int b, int c = 2)，b也必须有默认参数
// 函数声明如果有默认参数了，则函数源代码不能有默认参数，声明和实现只能有一个有默认参数
int funcDefault(int a, int b = 10, int c = 10)
{
    return a + b + c;
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;

    int ans1 = funcDefault(a);  // ans1 = 1 + 10 + 10 = 21
    cout << ans1 << endl;

    int ans2 = funcDefault(a, b);  // ans2 = 1 + 2 + 10 = 13
    cout << ans2 << endl;

    int ans3 = funcDefault(a, b, c);  // ans3 = 1 + 2 + 3 = 6
    cout << ans3 << endl;

    return 0;
}