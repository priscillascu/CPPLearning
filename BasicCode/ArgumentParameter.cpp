#include <iostream>

using namespace std;

void swapnum(int num1, int num2);
int main()
{
    int a = 1;
    int b = 2;
    swapnum(a, b);
    cout << a << " " << b << endl;
    return 0;
}

void swapnum(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
}