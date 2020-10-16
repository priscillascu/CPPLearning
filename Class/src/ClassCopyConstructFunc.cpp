#include <iostream>

using namespace std;
// 拷贝函数调用：
// 1.使用一个已经创建好了的对象来初始化一个新对象
// 2.值传递的方式给函数参数传值
// 3.值方式返回局部对象

class Person
{
private:
    /* data */
public:
    int Age;
    Person(/* args */);
    Person(int age);
    Person(const Person &p);
    ~Person();
};

Person::Person(/* args */)  // 默认构造函数
{
    cout << "Default construct function" << endl;
}

Person::Person(int age)  // 有参构造函数
{
    Age = age;
    cout << "Parameter construct function" << endl;
}

Person::Person(const Person &p)  // 拷贝构造函数
{
    Age = p.Age;
    cout << "Copy construct function" << endl;
}

Person::~Person()
{
    cout << "Destruct function" << endl;
}

// 2.值传递的方式给函数参数传值
void CopyConstruct(Person p)
{

}

// 3.值方式返回局部对象
Person ReturnCopy()
{
    Person p1;
    return p1;  // 以值的方式返回局部对象，会复制一份
}

int main()
{
    // 1.使用一个已经创建好了的对象来初始化一个新对象
    Person p1(20);  // 调用有参构造函数
    Person p2(p1);  // 调用拷贝构造函数
    cout << p2.Age << endl;

    // 2.值传递的方式给函数参数传值
    CopyConstruct(p1);  // 将对象以值传递的方式给函数传值，会自动复制一份对象，调用拷贝构造，如果没写拷贝构造，编译器会自动写一个空实现的
    // 因为是匿名对象，所以在这句话结束后会调用析构

    // 3.值方式返回局部对象
    Person p3 = ReturnCopy();
    return 0;
}