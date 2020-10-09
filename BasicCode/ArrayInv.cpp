#include <iostream>

using namespace std;

int main()
{
    int arr[5] = {1, 3, 2, 5, 4};
    int invArr[5];
    for (int i = 0; i < 5; ++i)
    {
        invArr[i] = arr[4 - i];
    }
    
    for (int j = 0; j < 5; ++j)
    {
        cout << invArr[j] << endl;
    }
    
       
    return 0;
}