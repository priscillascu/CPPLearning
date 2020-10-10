#include <iostream>

using namespace std;

struct StudengInfo
{
    string stuName;
    int stuScore;
};

struct TeacherInfo
{
    string teaName;
    StudengInfo stu[3];
};

void TeacherPrint(const TeacherInfo *tea1)
{
    cout << "Teacher name: " << tea1->teaName << endl;
    cout << "Student under this teacher:" << endl;
    cout << tea1->stu[0].stuName << endl;
    cout << tea1->stu[1].stuName << endl;
    cout << tea1->stu[2].stuName << endl;
}

int main()
{
    TeacherInfo tea;
    tea.teaName = "Bob";
    tea.stu[0].stuName = "Alice";
    tea.stu[1].stuName = "Cli";
    tea.stu[2].stuName = "Tom";
    TeacherPrint(&tea);
    return 0;
}