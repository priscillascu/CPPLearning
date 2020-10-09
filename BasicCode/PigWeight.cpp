#include <iostream>

using namespace std;

int main()
{
    short pig[3];
    short weight = 0;
    cout << "The 1st pig weight:";
    cin >> pig[0];
    cout << "The 2nd pig weight:";
    cin >> pig[1];
    cout << "The 3rd pig weight:";
    cin >> pig[2];

    for (int i = 1; i < 3; ++i)
    {       
        if(pig[weight] <= pig[i])
            weight = i;
        else
            weight = weight;
    }
    
    cout << "The most haven is " << weight + 1 << endl;
    return 0;
}