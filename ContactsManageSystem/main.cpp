#include "ShowMenu.hpp"


int main()
{
    int keyPress = 0;
    while(true)
    {
        ShowMenu();
        cout << "Please enter the number:" << endl;
        cin >> keyPress;

    }

    system("pause");
    return 0;
}