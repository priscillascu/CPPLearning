#include <iostream>

using namespace std;

// 冒泡排序，输入为一个数组，故可以使用指针来存放数组开头地址，*arr
void BubbleSort(int *arr, int arrLength)
{
    for (int readyNum = 0; readyNum < arrLength - 1; ++readyNum)
    {
        for (int selectNum = 0; selectNum < arrLength - 1 - readyNum; ++selectNum)
        {
            if(arr[selectNum] > arr[selectNum + 1])
            {
                int temp = arr[selectNum];
                arr[selectNum] = arr[selectNum + 1];
                arr[selectNum + 1] = temp;
            }
        }   
    }
}

int main()
{
    int arr[10] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int arrLength = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, arrLength);    // 因为数组名就是数组第一个元素的地址，故不需要&符号，直接写数组名就是传入地址了
    for (int pos = 0; pos < arrLength - 1; ++pos)
    {
        cout << arr[pos] << endl;
    }
    
    return 0;
}