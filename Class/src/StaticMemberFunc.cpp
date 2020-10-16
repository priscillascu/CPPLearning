#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    Person(/* args */);
    ~Person();
    static void func1();  // 声明一个静态成员函数，通过类名调用可以直接修改类定义里的静态成员变量
    static int Age;  // 静态成员变量，数据是共享的，可以被调用
    int Num;  // 非静态变量，使用时需要先声明一个对象才能访问其所在的内存
    void func2();  // 非静态成员函数，需要通过对象调用
};

int Person::Age;  // 静态成员类内定义，类外赋值

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void Person::func1()  // 在类外定义一个静态成员函数，此时不用声明static
{
    // Person::Num = 123;  // 非静态变量不能调用，因为没有声明类，函数不知道改变哪个内存
    Person::Age = 20;  // 静态成员函数可以访问静态成员属性
    cout << "Call for static function" << endl;
}

void Person::func2()  // 在类外定义一个非静态成员函数，可以调用静态、非静态变量，但是只能通过对象名使用
{
    Person::Num = 123;
    Person::Age = 456;
    cout << "Call for nonstatic function" << endl;
}


int main()
{
    Person::func1();  // 通过类名调用成员函数
    Person p1;
    cout << p1.Age << endl;  // 此时p1的Age被定义成了20，这是因为调用func1()的时候，修改了类里的成员变量，再用这个类声明的对象就会变成一样的

    p1.func2();  // 非静态成员函数则需要先声明一个对象，才能通过对象名调用
    cout << p1.Num << "\t" << p1.Age << endl;
    return 0;
}