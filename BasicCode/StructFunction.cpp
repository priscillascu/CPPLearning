#include <iostream>

using namespace std;

struct StudentInfo
{
    // 结构的成员列表
    string stuName;
    int stuAge;
    int finalScore;
};

// 值传递的结构体函数
void NamePrint(StudentInfo stu)  
{
    cout << "name: " << stu.stuName << endl;
}

// 地址传递的结构体函数，地址传递会改变实参
void ChangeAge(StudentInfo *pStu, int newAge)
{
    pStu->stuAge = newAge;
}

int main()
{
    StudentInfo stu1;
    stu1.stuName = "Bob";
    stu1.stuAge = 10;
    NamePrint(stu1);
    ChangeAge(&stu1, 20);
    cout << "New age is " << stu1.stuAge << endl;

    return 0;
}