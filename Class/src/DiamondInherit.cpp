#include <iostream>

using namespace std;
// 菱形继承，钻石继承问题
// 菱形继承导致了数据有两份，资源浪费
// 当两个子类继承了同一个父类，然后这两个子类又同时被另一个子类继承，存在重复定义，调用二义性
/*
                   Base
                    |
            child1      child2
                    |
                    child3
*/
// 使用虚继承解决
// 虚继承是会创建一个vptr，指向vtable的某个偏移量，多个虚继承都只会指向一个vtable的偏移值，就只会创建一份数据
class Base
{
private:
    /* data */
public:
    Base(/* args */);
    ~Base();

    int Age = 0;
};

Base::Base(/* args */)
{
}

Base::~Base()
{
}

// 直接继承，存在菱形问题
class Child1 : public Base {};
class Child2 : public Base {};
class Child3 : public Child1, public Child2 {};

// 菱形继承导致了数据有两份，资源浪费，使用虚继承解决，virtual
class Child4 : virtual public Base {};
class Child5 : virtual public Base {};
class Child6 : public Child4, public Child5 {};



int main()
{
    Child3 p1;
    // p1.Age = 10;  // 指向不明，可能来自Child1和Child2
    p1.Child1::Age = 10;
    p1.Child2::Age = 20;
    cout << p1.Child1::Age << "\t" << p1.Child2::Age << endl;  // 用作用域区分

    Child6 p2;
    p2.Age = 30;
    cout << p2.Age << endl;

    
    return 0;
}