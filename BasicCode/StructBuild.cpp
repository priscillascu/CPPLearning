#include <iostream>
#include <string>

using namespace std;

// 定义结构体的时候，struct不可省略
// 创建结构体变量的时候，struct可以省略
struct StudentInfo
{
    // 结构的成员列表
    string stuName;
    int stuAge;
    int finalScore;
}boy3;  // 第三种，顺便创建了一个结构体变量，但是需要后面进行赋值操作

int main()
{
    // 3种方法创建结构体变量，少用第三种，多用1、2种
    // 第一种，一个一个赋值
    StudentInfo boy1;  // 可以省略关键字struct
    boy1.stuName = "Bob";
    boy1.stuAge = 10;
    boy1.finalScore = 100;

    cout << "Name: " << boy1.stuName << endl;
    cout << "Age: " << boy1.stuAge << endl;
    cout << "Score: " << boy1.finalScore << endl;

    // 第二种，创建时按顺序赋值
    struct StudentInfo boy2 = {"Tom", 20, 80};  // 也可以不省略struct关键字
    cout << "Name: " << boy2.stuName << endl;
    cout << "Age: " << boy2.stuAge << endl;
    cout << "Score: " << boy2.finalScore << endl;

    boy3.stuName = "Alice";
    boy3.stuAge = 12;
    boy3.finalScore = 70;
    cout << "Name: " << boy3.stuName << endl;
    cout << "Age: " << boy3.stuAge << endl;
    cout << "Score: " << boy3.finalScore << endl;
    return 0;
}