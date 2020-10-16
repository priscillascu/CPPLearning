#include <iostream>

using namespace std;

class Person
{
private:
    /* data */
public:
    int Age;
    Person(int Age);
    ~Person();
    Person PersonAdd(Person &p);
    Person &PersonAddRef(Person &p);
};

Person::Person(int Age)
{
    this->Age = Age;  // 当成员属性和传入的参数同名了，就需要使用this，否则名称冲突，结果错误
    cout << "Call for constructor" << endl;
}

Person::~Person()
{
    cout << this->Age << endl;
    cout << "Call for destructor" << endl;
}

// 不使用引用，直接返回一个对象，则会创建一个新对象，真正调用的对象只进行了一次加法
// 后面的几次加法都是在接受返回值的新对象上进行的，因为是匿名对象，所以加法结束后全部析构
// 形参用引用的方式可以省去复制实参，节约空间，可以改变实参
Person Person::PersonAdd(Person &p)  
{
    this->Age += p.Age;  // 让调用这个函数的对象的Age属性加上传入的对象的age
    return *this;  // 返回对象本体
}

// 用引用来接受返回的对象，即改变了实参的值，执行完之后对象不会被析构
Person &Person::PersonAddRef(Person &p)
{
    this->Age += p.Age;
    return *this;
}

int main()
{
    Person p1(10);
    cout << "p1 age is " << p1.Age << endl;  // this将会指向p1

    // 没有使用引用，则只进行了第一次的p2.PersonAdd(p1)
    // 后面的.PersonAdd(p1)都是在上一次调用后返回的新对象的基础上进行
    // 因为是匿名对象，所以结束后被析构，p2还是就是第一次调用的值
    Person p2(10);
    p2.PersonAdd(p1).PersonAdd(p1);
    cout << "p2 age is " << p2.Age << endl;  

    // 使用引用，相当于直接修改了p3，中间不存在新对象
    Person p3(10);
    p3.PersonAddRef(p1).PersonAddRef(p1);
    cout << "p3 age is " << p3.Age << endl;
    return 0;
}