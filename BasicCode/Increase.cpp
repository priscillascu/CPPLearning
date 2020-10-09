#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    int b = a++;  // 先进行表达式运算，后让变量+1，即先让b = a = 2，再让a = a + 1 = 3
    int c = ++a;  // 先进行变量+1，后表达式运算，即先让a = a + 1 = 4，再c = a = 4
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    // 对于for循环，虽然前置++和后置++效果都是一样的，但是性能不同
    for(int i = 0; i < 5; i++)  // 在使用当前值之后再+1，所以需要一个临时的变量来转存
    {
        cout << i << endl;
    }
    for (int j = 0; j < 5; ++j)  // 直接+1，省去了对内存的操作的环节，相对而言能够提高性能
    {
        cout << j << endl;
    }
    
    return 0;
}