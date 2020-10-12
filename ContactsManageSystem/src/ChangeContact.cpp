#include "ChangeContact.hpp"

void ChangeContact(ContactBuild *contact, string tarName)
{
    int findPos = SearchContact(contact, tarName);
    if(findPos == -1)
    {
        return;
    }

    else
    {
        int changeInfo;
        cout << "Which one do you want to change?    " << "1.Name\t" << "2.Sex\t" << "3.Age" << "0.Exit" <<endl;
        cin >> changeInfo;

        while (true)
        {
            if(changeInfo != 1 && changeInfo != 2 && changeInfo != 3 && changeInfo != 0)
            {
                cout << "Please enter 1 2 3 0" << endl;
                cin >> changeInfo;
            }

            else
            {
                switch (changeInfo)
                {
                case 1:
                {
                    cout << "Please enter new name: " ;
                    cin >> contact->peopleArray[findPos].name;
                    cout << "Change complete!" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
                case 2:
                {
                    cout << "Please enter new sex: " ;
                    cin >> contact->peopleArray[findPos].sex;
                    cout << "Change complete!" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
                case 3:
                {
                    cout << "Please enter new age: " ;
                    cin >> contact->peopleArray[findPos].age;
                    cout << "Change complete!" << endl;
                    system("pause");
                    system("cls");
                    return;
                }

                default:
                    break;
                }
                cout << "Change complete!" << endl;
                system("pause");
                system("cls");
                return;
            }
            
        }
    }
}