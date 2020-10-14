#include <iostream>
#define PI 3.1415
using namespace std;

// 类，设计一个圆类，求其周长
// 属性通常是一些变量，行为一般是函数
// 通过一个类，可以创建一个对象，实例化
// 属性也称为成员变量、成员属性
// 行为也称为成员函数
class Circle
{
	// 访问权限
public:
	// 属性
	int radiusM;
	// 行为：用函数来进行，本例为获取圆周长
	double CircleLength()
	{
		return 2*PI*radiusM;
	}
};

class Student
{
// 建立一个学生类
public:
	string stuName;  // 学生属性
	string stuNum;
	void ShowInfo()  // 类的行为
	{
		cout << "student name is " << stuName << endl;
		cout << "student number is " << stuNum << endl;
	}
	
	void SetName(string inName)
	{
		stuName = inName;
	}
};
int main()
{
	//　通过使用圆类，创建一个对象，圆
	Circle c1;
	c1.radiusM = 10;
	cout << "Length of this circle is " << c1.CircleLength() << endl;
	
	Student stu1;
	cout << "Please enter the name and number:" << endl;
	cin >> stu1.stuName;
	cin >> stu1.stuNum;
	stu1.ShowInfo();	
	stu1.SetName("alice");
	stu1.ShowInfo();
	return 0;	
}
