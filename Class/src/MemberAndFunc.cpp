#include <iostream>

using namespace std;

class PersonEmpty  // 一个空类
{
private:
    /* data */
public:
    PersonEmpty(/* args */);
    ~PersonEmpty();
};

PersonEmpty::PersonEmpty(/* args */)
{
}

PersonEmpty::~PersonEmpty()
{
}

class PersonNonEmpty
{
private:
    /* data */
public:
    int Name;  // 非静态成员变量
    char Age;

    static int Num;

    void func1() {}
    static void func2() {}
    PersonNonEmpty(/* args */);
    ~PersonNonEmpty();
};

PersonNonEmpty::PersonNonEmpty(/* args */)
{
}

PersonNonEmpty::~PersonNonEmpty()
{
}

int main()
{
    PersonEmpty p1;  // 空类定义的对象大小是1个字节，空对象
    cout << "Size of object p1 is " << sizeof(p1) << endl;

    PersonNonEmpty p2;  // 类定义的对象大小只与类内的非静态成员变量有关
    cout << "Size of object p2 is " << sizeof(p2) << endl;
    return 0;
}