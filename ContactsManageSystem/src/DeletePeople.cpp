#include "SearchAndDeleteContact.hpp"

void DeletePeople(ContactBuild *contact, string delName)
{
    char delCmd;
    int tarPos = SearchContact(contact, delName);

    if(tarPos == -1)
    {
        return;
    }

    else
    {
        cout << "Are you sure to delete" << " " << delName << " ?    Y/N" <<endl;
        cin >> delCmd;

        if(delCmd == 'Y' || delCmd == 'y')
        {
            for (int movPos = tarPos; movPos < contact->addedNum - tarPos - 1; ++movPos)
            {
                contact->peopleArray[movPos] = contact->peopleArray[movPos + 1];
            }
            contact->addedNum--;
            cout << "Delete completed" << endl;
            system("pause");
            system("cls");
            return;
        }
        else
        {
            cout << "Nothing to delete, press to return" << endl;
            system("pause");
            system("cls");
            return;
        }
    }   
}