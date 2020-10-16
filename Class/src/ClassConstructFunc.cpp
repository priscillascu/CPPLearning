#include <iostream>

using namespace std;

// 构造函数的分类以及调用
// 构造函数按参数分为：无参构造和有参构造，可重载
// 按照类型分为：普通构造，拷贝构造
class Person
{
private:
    /* data */
public:
    Person();  // 构造函数可以重载
    Person(int a);
    Person(const Person &p);  // 拷贝构造
    ~Person();
};

Person::Person()  // 无参构造，也是默认的情况
{
    cout << "Call for default construct function" << endl;
}
Person::Person(int a)  // 有参构造
{
    cout << "Call for construct function with parameter" << endl;
}
Person::Person(const Person &p)  // 拷贝构造，写法为参数用const 类名 对象引用，将会把传入的对象属性复制一份
{
    cout << "Call for Copy construct function" << endl;
}

Person::~Person()
{
    cout << "Call for Destruct function"  << endl;
}


int main()
{
    Person p1;  // 默认构造函数，即无参构造
    // 匿名对象，直接使用构造函数声明，但是没有名字，在声明完之后会被立即释放
    Person(10);
    // Person(p1);  // 不能用拷贝构造来定义匿名对象

    // 调用构造函数有3种

    // 1.括号法
    // Person p1();  // 调用无参构造不要写()了，会被认为是函数声明
    Person p2(10);  // 括号法调用有参构造
    Person p3(p2);  // 传入一个对象，调用拷贝构造，还会复制一份p2属性给p3

    // 2.显式法
    Person p4 = Person(10);  // 直接调用有参构造
    Person p5 = Person(p2);  // 直接调用拷贝构造

    // 3.隐式法，把显式法省略了一些
    Person p6 = 10;  // 相当于Person p6 = Person(10);
    Person p7 = p2;  // 拷贝构造

    return 0;
}