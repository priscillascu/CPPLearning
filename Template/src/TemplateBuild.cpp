#include <iostream>

using namespace std;

// template声明创建一个模板
// 声明一个模板，告诉编译器typename/class的T是一个通用数据类型，T名称可以替换，一般为大写
template<typename T>  
// 创建一个函数模板，不指定数据类型，用传引用的方式来修改实参
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 声明一个模板类，直接在template后面加类
template<class NameType, class AgeType>
class Person
{
private:
    /* data */
public:
    Person(NameType inName, AgeType inAge);
    ~Person();

    NameType name;
    AgeType age;
};

// 在类外定义成员函数时，需要再次声明一些模板，并将类模板参数列表写出，每一个函数前都要加一句模板声明
template<class NameType, class AgeType>
Person<NameType, AgeType>::Person(NameType inName, AgeType inAge)
{
    name = inName;
    age = inAge;
}

template<class NameType, class AgeType>
Person<NameType, AgeType>::~Person()
{
}

int main()
{
    int a1 = 10;
    int b1 = 20;
    // 使用模板有两种方式，必须要确定出模板数据类型才能使用
    // 1.自动类型推导，直接写实参，自动推导形参类型，必须推导出一致的数据类型
    mySwap(a1, b1);
    cout << a1 << "\t" << b1 << endl;

    // 2.显示指定类型
    mySwap<int>(a1, b1);  // 直接告诉T=int类型
    cout << a1 << "\t" << b1 << endl;

    Person<string, int> p1("Tom", 20);
    cout << p1.name << "\t" << p1.age << endl;
    return 0;
}