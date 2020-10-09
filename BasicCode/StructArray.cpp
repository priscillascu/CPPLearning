// 将结构体放入数组
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
    // 创建结构体数组，并给结构体元素赋值
    StudentInfo stuArray[3] = 
    {
        {"Bob", 18, 100},
        {"Tom", 20, 110},
        {"Jay", 30, 200}
    };

    stuArray[2].stuAge = 40;  // 修改结构体数组的值
    
    // 遍历结构体数组
    for (int num = 0; num < 3; ++num)
    {
        cout << "name: " << stuArray[num].stuName << endl;
    }
    
    return 0;
}