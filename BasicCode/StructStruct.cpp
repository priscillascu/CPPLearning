#include <iostream>

using namespace std;

struct StudentInfo
{
    // 结构的成员列表
    string stuName;
    int stuAge;
    int finalScore;
};

struct TeacherInfo
{
    // 结构的成员列表
    string teaName;
    int teaAge;
    StudentInfo stu;  // 结构体嵌套另一个结构体
};

int main()
{
    TeacherInfo tea1;
    tea1.teaName = "Tom";
    tea1.teaAge = 50;
    tea1.stu.stuName = "Bob";  // 嵌套赋值，结构体中的结构体，层层递进
    cout << "Teacher name: " << tea1.teaName << endl;
    cout << "Student name: " << tea1.stu.stuName << endl;

    return 0;
}