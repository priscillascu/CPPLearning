#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    int Age;
    mutable int Num;  // 加上mutable(可变的)之后，可以在常函数中修改

    Person(/* args */);
    ~Person();

    void ShowPerson();
    void ShowConst() const;  // 常函数
};

Person::Person(/* args */)
{
}

Person::~Person()
{
}

void Person::ShowPerson()
{
    Age = 100;  // 可以在成员函数中修改非const的数据
}

// 常量成员函数，在声明后加一个const，这个const相当于修饰了一个 const Person * const this
void Person::ShowConst() const  // 常函数
{
    // Age = 100;  // 无法修改this指针的指向值
    Num = 100; // 可以修改mutable变量
}

int main()
{
    const Person p1;  // 常对象
    p1.Num = 100;  // 常对象的mutable也可以修改，常对象只能调用常函数
    // p1.ShowPerson();  // 常对象不能调用非常函数
    p1.ShowConst();
    return 0;
}