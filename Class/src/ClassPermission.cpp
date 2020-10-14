#include <iostream>
using namespace std;

// struct和class都可以表现一个类，但是struct默认权限为公共，class默认为私有
// 访问权限有三种：
// 公共public，class成员类内、外都可以访问
// 保护protected，类内可以访问，外不可以，子类可以访问父类
// 私有private，类内可以访问，外不可以，子类不可以访问父类
// 类内即为在class的{}内的代码

class Person
{
public:  // 公共权限
	string myName;

protected:  // 保护权限
	string myCar;

private:    // 私有权限
	string myCode;

public:    // 可以访问类内的成员变量
	void PrintPro()
	{
		myName = "Bob";
		myCar = "Far";
		myCode = "12345";
		cout << "In the class " << myName << "	" << myCar << "    " << myCode << endl;	
	}
};
int main()
{
	Person p1;
	p1.PrintPro();  // 该函数是public，所以在类外可以访问
	// p1.myCar;  // 无法访问，会报错，无法访问类里的非公共属性
	p1.myName = "Tom";
	cout << "Out the class" << p1.myName << endl;

	return 0;
}
