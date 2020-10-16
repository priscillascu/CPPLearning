#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    int *Age;
    int *Height;  // 定义一个指针用来接收地址

    Person();
    Person(int a, int height);
    Person(const Person &p);
    ~Person();
};

Person::Person()  // 无参构造，也是默认的情况
{
    cout << "Call for default construct function" << endl;
}

Person::Person(int a, int height)  // 有参构造
{
    *Age = a;
    Height = new int(height);  // 在堆区开辟内存，返回堆区的地址
    cout << "Call for construct function with parameter" << endl;
}

Person::Person(const Person &p)  // 深拷贝，创建一个新的堆区来存储拷贝的数据
{
    Age = new int(*p.Age);
    Height = new int(*p.Height);
    cout << "Call for Copy construct function" << endl;
}


Person::~Person()
{
    if(Height != NULL)  // 释放堆区
    {
        delete &Height;
        delete &Age;
        Height = NULL;
    }
    cout << "Call for Destruct function"  << endl;
}

int main()
{
    Person p1(10, 180);
    cout << "P1 age is " << *p1.Age << endl;  
    cout << "P1 height is " << *p1.Height << endl;  // 解引用要放在对象名前
    Person p2(p1);
    cout << "P2 age is " << *p2.Age << endl;  
    cout << "P2 height is " << *p2.Height << endl;  // 使用深拷贝
    return 0;
}