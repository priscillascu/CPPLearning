#include "SwapNum.hpp"
#include "AddNums.hpp"
#include "RandomArr.hpp"

int main()
{
    int a = 1;
    int b = 2;
    swapnum(a, b);
    int c = AddNums(a, b);
    cout << a << " " << b << endl;
    cout << "c = " << c << endl;

    int arr[5] = {1, 4, 5, 3, 2};
    RandomArr(arr);
    return 0;
}