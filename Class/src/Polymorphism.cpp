#include <iostream>

using namespace std;
/* 多态分为：
1.静态多态：函数重载、运算符重载，编译阶段确定函数地址，早绑定
2.动态多态：派生类和虚函数实现运行时多态，运行阶段确定函数地址，晚绑定

动态多态满足条件：
1.存在继承关系
2.子类重写父类的虚函数，即子类和父类的虚函数所有内容相同，不是重载

动态多态调用：
父类的指针或者引用，指向了子类对象，即
void Func(Base &base1)
{
    base1.Member();
}
Func(Child child1);
*/

class Base
{
private:
    /* data */
public:
    Base(/* args */);
    ~Base();

    void Speak();

    // 使用virtual创建虚函数，让编译器不早绑定该函数地址，父类必须写virtual
    virtual void Sleep();
};

Base::Base(/* args */)
{
}

Base::~Base()
{
}

void Base::Speak()
{
    cout << "Base is speaking." << endl;
}

void Base::Sleep()
{
    cout << "Base is sleeping." << endl;
}

// 创建一个Base的子类
class Child : public Base 
{
private:
    /* data */
public:
    Child(/* args */);
    ~Child();

    void Speak();
    // 子类重写可以不用写virtual
    void Sleep();
};

Child::Child(/* args */)
{
}

Child::~Child()
{
}

void Child::Speak()
{
    cout << "Child is speaking." << endl;
}

void Child::Sleep()
{
    cout << "Child is sleeping." << endl;
}



// 创建一个参数为父类对象的引用的函数
void DoSpeak(Base &base)
{
    // 该函数地址早绑定，在编译阶段就确定了函数的地址，所以子类调用时也是调用的父类函数
    base.Speak();

    // 如果要执行子类的函数，则给函数地址需要晚绑定，在运行阶段确定函数地址
    // 此时虚函数的地址不能确定，需要根据传入的对象来确定是否调用子类的同名函数
    base.Sleep();
}

int main()
{
    Child c1;
    // 将子类传入参数为父类的引用的函数，即父类的引用指向了子类的对象
    // C++允许父类和子类之间的类型转换，父类的引用、指针可以指向子类
    // 此时将会调用父类的成员函数，如果是virtual，则会调用子类的重写函数
    DoSpeak(c1);

    return 0;
}