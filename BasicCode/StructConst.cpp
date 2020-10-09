#include <iostream>

using namespace std;

struct StudentInfo
{
    // 结构的成员列表
    string stuName;
    int stuAge;
    int finalScore;
};

// 对于结构体，地址传递更优
// 地址传递，只用传递一个地址，比较省空间
// 值传递会复制一次结构体实参给形参，如果实参庞大，则会很占空间
// 为了防止在函数中对结构体数据误操作，建议使用const struct
void NamePrint(const StudentInfo *pStu1)  
{
    cout << pStu1->stuName << endl;
    // 无法修改结构体数据
    // pStu1->stuAge = 20;  // 无法执行
}

int main()
{
    StudentInfo stu1;
    stu1.stuName = "Bob";
    stu1.stuAge = 10;
    NamePrint(&stu1);

    return 0;
}