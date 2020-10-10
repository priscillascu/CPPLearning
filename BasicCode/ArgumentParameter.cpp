#include <iostream>

using namespace std;

void SwapNum(int num1, int num2);
void SwapArrayNum(int arr[]);

int main()
{
    int a = 1;
    int b = 2;
    SwapNum(a, b);
    cout << a << " " << b << endl;

    int arr[2] = {1, 2};
    SwapArrayNum(arr);
    cout << arr[0] << "  " << arr[1];
    return 0;
}

void SwapNum(int num1, int num2)  // 值传递，实参复制一份给形参，实参值不会改变
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}

void SwapArrayNum(int arr[])  // 数组都是地址传递，因为数组名就是地址，实参会改变
{
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}