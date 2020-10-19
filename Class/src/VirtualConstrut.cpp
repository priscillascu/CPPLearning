#include <iostream>

using namespace std;
// 虚析构和纯虚析构函数
// 虚析构可以释放由父类指针指向的子类对象，纯虚析构需要有具体实现代码，不能只=0

class Base
{
private:
    /* data */
public:
    Base(/* args */);
    virtual ~Base();  // 定义一个虚析构，可以释放父类指针指向的子类对象
    
    // 定义一个纯虚函数
    virtual void VirFunc1() = 0;
};

Base::Base(/* args */)
{
}

Base::~Base()
{
}

class Child : public Base
{
private:
    /* data */
public:
    string *Name;

    Child (string name);
    ~Child ();

    void VirFunc1();
};

Child::Child (string name)
{
    cout << "Call for construct of CHILD" << endl;
    Name = new string(name);
}

Child::~Child ()
{
    if(Name != nullptr)
    {
        delete Name;  // 释放堆区
        Name = nullptr;
        cout << "Call for destruct of CHILD" << endl;
    }
}

void Child::VirFunc1()
{
    cout << *Name << " Call for the CHILD" << endl;
}

void test1()
{
    // 定义一个指针子类的父类对象
    Base *base = new Child("Tom");
    // 此时会发生多态，调用子类的重写函数
    base->VirFunc1();
    delete base;  // 父类指针指向子类对象，当delete的时候是不会去析构子类的，如果子类有new堆区，则会内存泄漏，此时需要虚析构
}

int main()
{
    test1();
    return 0;
}