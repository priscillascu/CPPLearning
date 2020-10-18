#include <iostream>

using namespace std;

// 使用继承，使用公共部分，减少重复代码，实际上子类还是会创建一下父类
// 允许一个类继承多个类，但是不推荐，class 子类 : 继承方式 父类1, 继承方式2 父类2
// 继承有3种方式，对应于三种权限，public，private，protected
// 1.public继承，则父类的除private，public和protected权限原封不动继承
// 2.protected继承，还是不能继承父类的private，但是其他权限全部继承，但是全部继承为protected
// 3.private继承，还是不能继承父类的private，会将其他权限继承为private
// 继承其实把父类的所有属性，包括私有，复制给了子类，只不过编译器把私有属性隐藏了
// 继承创建的类，会先构造父类，再构造子类，先析构子类，再析构父类，先进后出
// 当子类和父类有同名成员时，子类的可以直接访问，父类的需要加一个作用域：对象.父类::成员，包括重载，也要加作用域

// 父类，也称基类
class BaseClass
{
private:
    int PrivateNum = 1;
public:
    BaseClass(/* args */);
    ~BaseClass();

    int PublicNum = 2;
    void ShowMenu();
    void ShowEnd();
protected:
    int ProtNum = 3;
};

BaseClass::BaseClass(/* args */)
{
}

BaseClass::~BaseClass()
{
}

void BaseClass::ShowMenu()
{
    cout << "This is the Menu that every program has." << endl;
}

void BaseClass::ShowEnd()
{
    cout << "This is the End part" << endl;
}

// 1.public继承，将会把除了private以外的内容原封不动继承
// 子类，也称为派生类
class ChildClassPublic : public BaseClass  
{       
private:
    /* data */
public:
    ChildClassPublic(/* args */);
    ~ChildClassPublic();
    void ShowMenu();
    void ShowChild();
};      

ChildClassPublic::ChildClassPublic(/* args */)
{       
}

ChildClassPublic::~ChildClassPublic()
{       
}

void ChildClassPublic::ShowMenu()
{
    cout << "Show menu from child" << endl;
}

void ChildClassPublic::ShowChild()
{
    cout << "This function is from child class" << endl;
}

// 2.private继承，将父类的public和protected继承到子类的private
class ChildClassPrivate : private BaseClass
{
private:
    /* data */
public:
    ChildClassPrivate(/* args */);
    ~ChildClassPrivate();
};

ChildClassPrivate::ChildClassPrivate(/* args */)
{
    ShowMenu();  // 私有继承父类的公共、保护都成了私有，只能在类内访问
}

ChildClassPrivate::~ChildClassPrivate()
{
}

// 3.protected继承，将父类的public和protected继承到子类的protected
class ChildClassProt : protected BaseClass
{
private:
    /* data */
public:
    ChildClassProt(/* args */);
    ~ChildClassProt();
};

ChildClassProt::ChildClassProt(/* args */)
{
    ShowMenu();  // 可以在类内访问保护权限，保护继承来的都成了保护
}

ChildClassProt::~ChildClassProt()
{
}



int main()
{
    ChildClassPublic p1;
    cout << "Public inherit size is " << sizeof(p1) << endl;
    p1.ShowChild();
    p1.ShowMenu();
    p1.ShowEnd();
    p1.BaseClass::ShowMenu();

    ChildClassPrivate p2;
    // p2.ShowChild();  // 无法访问私有权限
    cout << "Private inherit size is " << sizeof(p2) << endl;

    ChildClassProt p3;
    // p3.ShowMenu();  // 无法在类外访问保护权限
    cout << "Protected inherit size is " << sizeof(p3) << endl;
    return 0;
}