#include <iostream>

using namespace std;

class Person
{
    // 声明一个友元函数，让这个函数可以访问私有成员
    friend void FriendFun(Person &p1);
private:
    int passWord;
public:
    Person(/* args */);
    ~Person();

    int age;
};

Person::Person(/* args */)
{
    Person::passWord = 123;
    Person::age = 10;
}

Person::~Person()
{
}

// 定义一个全局函数，可以访问Person类的私有成员
void FriendFun(Person &p1)
{
    cout << "I can access the private : " << p1.passWord << endl;
}

int main()
{
    Person p1;
    FriendFun(p1);
    return 0;
}