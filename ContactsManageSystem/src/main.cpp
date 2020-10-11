#include "ShowMenu.hpp"
#include "ContactSystem.hpp"
#include "AddContact.hpp"
#include "ShowContact.hpp"

int main()
{
    int keyPress = 0;
    ContactBuild contact1;  // 创建通讯录结构体

    while(true)
    {
        ShowMenu();
        cout << "Please enter the number:" << endl;
        cin >> keyPress;
        system("cls");  // 清屏

        switch (keyPress)
        {
        case 1:  // 1.Add contacts
        {
            cout << "****  1.Add contacts          ****" << endl;
            AddContact(&contact1);   // 地址传递，修改实参，即在通讯录结构体中真实的添加
            break;  // switch的break是退出离其最近的switch，而不是外部循环
        }
            
        case 2:  // 2.Show all contacts
            ShowContact(&contact1);
            break;

        case 3:  // 3.Delete contact

            break;

        case 4:  // 4.Search contact

            break;

        case 5:  // 5.Change contact

            break;

        case 6:  // 6.*Delete ALL contacts

            break;

        case 0:  // 0.Exit
            cout << "Thanks for using." << endl;
            system("pause");
            system("cls");
            return 0;
            break;
        
        default:

            break;
        }
    }

    
}