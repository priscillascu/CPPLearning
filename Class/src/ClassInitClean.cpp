#include <iostream>

using namespace std;

// 对象的初始化和清理，C++利用构造函数和析构函数来进行初始化和清理
// 如果不写构造和析构，编译器会自动写，只不过是空实现
// 构造：初始化，对象的成员属性赋值，编译器自动调用
// 析构：清理

class Person
{
private:
    /* data */
public:
    string Name;
    int Age;
    Person(int a);  // 在公共权限声明构造和析构
    Person(string name, int age);
    ~Person();
};
// 构造函数，函数名与类一样，无返回值不需要写void，有参数可以重载，创建对象时自动调用一次构造函数
// 如果不写，编译器也会自动生成，只不过是空函数了
Person::Person(int a)
{
    cout << "Call for Constructed function" << endl;
}

Person::Person(string name, int age): Name(name), Age(age)  // 定义了一个使用列表初始化对象的构造函数
{
    cout << "Call for list" << endl;
}
// 析构函数名与类一样，前面加一个~，不可以有参数，不能重载，不需要写void
Person::~Person()  
{
    cout << "Call for Destructor" << endl;
}


int main()
{
    Person p1 = Person(10);  // 创建对象之后，会自动调用一次构造函数，不需要去手动调用，类释放时自动调用一次析构函数来清除对象
    Person p2 = Person("Tom", 20);
    cout << p2.Age << "\t" << p2.Name << endl;
    return 0;
}