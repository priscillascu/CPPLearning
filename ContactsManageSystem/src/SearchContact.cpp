#include "SearchAndDeleteContact.hpp"

int SearchContact(ContactBuild *contact, string targetName)
{
    for (int pos = 0; pos < contact->addedNum; ++pos)   // 遍历查找
    {
        if(contact->peopleArray[pos].name == targetName)
        {
            cout << "Find target people, at " << pos + 1 << " : " << endl;
            cout << "-----------------------------------------------------------" << endl;
            cout << "Name: " << contact->peopleArray[pos].name << "\t";
            cout << "Sex: " << (contact->peopleArray[pos].sex == 1 ? "Male" : "Female") << "\t";  // 必须加括号，调整优先级
            cout << "Age: " << contact->peopleArray[pos].age << endl;
            cout << "-----------------------------------------------------------" << endl;
                
            cout << "Press any key to RETURN" << endl;
            system("pause");
            system("cls");
            return pos;
        }
    }

    cout << "Not Found. Press any key to RETURN" << endl;
    system("pause");
    system("cls");
    return -1;
}