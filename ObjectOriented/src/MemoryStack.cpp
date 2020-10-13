// 栈区数据由编译器管理开辟和释放
// 存放函数的参数值、局部变量等，不要返回局部变量的地址
// 如果不想被立即释放，可以用static修饰

#include <iostream>

using namespace std;

int *TestFunc()
{
    int aLocal = 10;  // 局部变量，存放在栈区
    // return &aLocal;  // 返回局部变量地址，栈区数据在函数执行完之后自动释放，所以返回的不是真正的局部变量
    // 会报错，程序崩溃
    
    static int bLocal = 20;  // static声明静态变量，不会被立即释放
    return &bLocal;  // 此时可以返回其地址
}

int main()
{
    int *p = TestFunc();
    cout << p << "\t" << *p;
    return 0;
}