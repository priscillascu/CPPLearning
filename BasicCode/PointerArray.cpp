#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = arr;   // 数组名就是数组的首地址，不需要&
    cout << "value of p pointed is " << *p << endl;  // 对指针解引用就是数组元素了
    cout << "first address of p is " << p << endl;
    p++;  // 对指针进行地址+1，即可得到数组的第2个元素，实际上地址是+4，增加了一个字节
    cout << "new value of p pointed is " << *p << endl;  // 对指针解引用就是数组元素了
    cout << "new address of p is " << p << endl;

    int *p2 = arr;
    for (int i = 0; i < 10; ++i)  // 利用指针遍历数组
    {
        cout << *p2 << endl;
        ++p2;
    }
    
    return 0;
}