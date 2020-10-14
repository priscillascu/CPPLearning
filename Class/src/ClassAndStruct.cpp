#include <iostream>
using namespace std;

struct StructTest
{
	string name;
	int age;
	
	void PrintAge()
	{
		cout << "in the struct, age is " << age << endl;
	}
};

class ClassTest
{
// 类默认是私有属性
	string name;
	int age;

	void PrintAge()
	{
		cout << "in the class, age is " << age << endl;
	}
};

int main()
{
	StructTest stu1 = {"Bob", 12};
	ClassTest stu2;
	/* 无法对私有成员属性在类外进行赋值
	stu2.name = "Tom";
	stu2.age = 13;
	*/
	StructTest *pStu = &stu1;
	pStu -> PrintAge();
	// stu2.PrintAge();  //　因为class默认是私有，故无法调用成员函数
	return 0;
}
