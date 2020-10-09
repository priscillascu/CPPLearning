// 通过指针访问结构体成员
#include <iostream>

using namespace std;

struct StudentInfo
{
    // 结构的成员列表
    string stuName;
    int stuAge;
    int finalScore;
};

int main()
{
    StudentInfo boy1;  // 可以省略关键字struct
    boy1.stuName = "Bob";
    boy1.stuAge = 10;
    boy1.finalScore = 100;

    // 通过指针指向结构体变量
    StudentInfo *pStu = &boy1;  // 通过结构体定义一个指针，指向结构体变量
    // 使用->符号来输出结构体指针的成员
    cout << "Name: " << pStu->stuName;

    return 0;
}