#include <iostream>
using namespace std;

class Cube
{
public:  // 成员属性用私有，再在公共里面提供读写接口
	// 定义立方体长的读写接口函数
	void SetL(int inL)
	{
		cubeL = inL;
	}

	int GetL()
	{
		return cubeL;
	}

	// 定义立方体宽的读写接口函数
	void SetW(int inW)
	{
		cubeW = inW;
	}

	int GetW()
	{
		return cubeW;
	}

	// 定义立方体高的读写接口函数
	void SetH(int inH)
	{
		cubeH = inH;
	}

	int GetH()
	{
		return cubeH;
	}

private:  // 私有的方式创建成员属性
	int cubeL;
	int cubeW;
	int cubeH;
};
int main()
{
	Cube cube1;
	cube1.SetL(1);
	cube1.SetW(2);
	cube1.SetH(3);
	cout << "Length is " << cube1.GetL() << "\t" << "Width is " << cube1.GetW() << "\t" << "High is " << cube1.GetH() << endl;	
	return 0;
}
