#ifndef CONTACTSYSTEM_HPP
#define CONTACTSYSTEM_HPP

#define MAX 1000
#include <iostream>
using namespace std;

struct peopleInfo  // 联系人结构体
{
    string name;
    int sex;  // 用数字表示性别，1.男，2.女
    int age;
};

struct ContactBuild  // 通讯录结构体
{
    peopleInfo peopleArray[MAX];  // 存放联系人结构体数组
    int addedNum = 0;  // 当前记录联系人个数
};

#endif