#include "AddContact.hpp"

void AddContact(ContactBuild *contact)  // 地址传递，修改实参
{
    bool addFlag = 1;  // 循环添加标志位，1继续添加，0停止添加
    char addCmd;

    while(addFlag)
    {
        int addNum;  // 本次添加通讯录的个数
        int curNum = contact->addedNum;  // 当前通讯录已存个数
        if(curNum == MAX)
        {
            cout << "Contact is FULL, can not add anymore." << endl;
        }
        else
        {
            cout << "The number of contact you wanted add is : ";
            cin >> addNum;
            for (int add = curNum; add < curNum + addNum; ++add)  // 接着当前通讯录总数后面接着添加
            {
                cout << "Name of " << add - curNum + 1 << " is : ";
                cin >> contact->peopleArray[add].name;

                cout << "Sex, 1 for male, 2 for female : ";       
                while(true)  //  判断输入是否为1 or 2
                {
                    int sexTemp;
                    cin >> sexTemp;
                    if(sexTemp == 1 || sexTemp == 2)
                    {
                        contact->peopleArray[add].sex = sexTemp;   
                        break; 
                    }
                    else
                    {
                        cout << "Please enter 1 or 2" << endl;
                    }
                    
                }

                cout << "Age : ";
                cin >> contact->peopleArray[add].age;

                contact->addedNum++;  // 增加通讯录已存总数
                cout << "Total number of contacts is " << contact->addedNum << " / " << MAX << endl;
            }
        }

        cout << "Done!" << endl;
        cout << "Continue add?   Y/N" << endl;  // 是否循环添加
        cin >> addCmd;
        (addCmd == 'y' || addCmd == 'Y') ? addFlag = 1 : addFlag = 0;  // 三目运算符根据输入字符判断是否继续添加
        system("cls");   // 清屏
    }
    
}