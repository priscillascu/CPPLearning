#include <iostream>

using namespace std;

int main()
{
    int Mat1[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7 ,8, 9}
    };

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << Mat1[i][j] << endl;
        }
    }
    cout << sizeof(Mat1) << endl;
    return 0;
}