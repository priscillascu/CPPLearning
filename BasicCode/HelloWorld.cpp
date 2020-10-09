#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "Hello World";
    for (int i = 0; i < sizeof(str1); ++i)
    {
        cout << i << endl;
    }
    
}