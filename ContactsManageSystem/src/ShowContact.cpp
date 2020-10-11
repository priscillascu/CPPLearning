#include "ShowContact.hpp"

void ShowContact(ContactBuild *contact)
{
    char exitCmd;
    if(contact->addedNum == 0)
    {
        cout << "Empty Contact" << endl;
        return;
    }
    else
    {
        for (int people = 0; people < contact->addedNum; ++people)
        {
            cout << "-----------------------------------------------------------" << endl;
            cout << "Name: " << contact->peopleArray[people].name << "\t";
            cout << "Sex: " << (contact->peopleArray[people].sex == 1 ? "Male" : "Female") << "\t";  // 必须加括号，调整优先级
            cout << "Age: " << contact->peopleArray[people].age << endl;
            cout << "-----------------------------------------------------------" << endl;
        }
        cout << "Press any key to RETURN" << endl;
        system("pause");
        system("cls");
        return;
    }
    
}