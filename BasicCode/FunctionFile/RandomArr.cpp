#include "RandomArr.hpp"

void RandomArr(int arr[])
{
    int end = sizeof(arr) / sizeof(arr[0]) - 1;  // 定义最后一个数的位置
    for (int i = 0; i <= end; ++i)
    {
        int pos = rand()%(end - i);
        int temp = arr[end - i];
        arr[end - i] = arr[pos];
        arr[pos] = temp;
        cout << arr[i] << endl;
    }
    
}