// 堆区，由程序员分配、释放，系统也可以程序结束后自动回收
// 主要利用new来在堆区开辟内存

#include <iostream>

using namespace std;

int *HeapFunc()
{
    // 指针仍是局部变量，存放在栈区，但其存放的地址是指向堆区的
    int *pHeap = new int(10);  // new开辟堆区，返回新内存的地址，用()来创建数据，该地址存放的数据为10
    return pHeap;
}

int main()
{
    int *p = HeapFunc();
    cout << p << "\t" << *p << endl;  // 输出正确，输出了堆中新开辟的地址，以及该地址存放的值10

    // new在堆区开辟数组
    int *pArr = new int[10];  // 用[]来创建堆区数组，返回值是地址
    for (int i = 0; i < 10; ++i)
    {
        pArr[i] = i;  // 直接把该指针当作数组来进行操作即可
    }
    for (int j = 0; j < 10; ++j)
    {
        cout << pArr[j] << endl;
    }
    
    
    // 释放堆区内存，delete 内存地址
    delete p;  // 释放该堆区地址的数据，无法再次访问
    delete [] pArr;  // []释放堆区数组
    return 0;
}