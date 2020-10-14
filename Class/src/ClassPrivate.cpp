#include <iostream>
using namespace std;

class Person
{
public:
	// 写姓名，为私有属性Name设置了类外的可读可写接口
	void SetName(string inName)
	{
		Name = inName;
	}
	// 读姓名
	string GetName()
	{
		return Name;
	}

	// 年龄Age只有只读接口
	int GetAge()
	{
		return Age;
	}

	// Num只有只写接口
	void SetNum(int inNum)
	{
		Num = inNum;	
	}

private:  // private中的成员可以通过public设计一个接口来赋予权限
	string Name;  // 赋予可读可写权限
	int Age = 10;  // 赋予只读权限
	int Num;  // 赋予只写权限
};

int main()
{
	Person p1;
	p1.SetName("Bob");
	cout << "Name is " << p1.GetName() << endl;	
	cout << "Age is " << p1.GetAge() << endl;
	p1.SetNum(123);
	return 0;
}
