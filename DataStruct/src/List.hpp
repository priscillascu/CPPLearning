/*
顺序表的实现
包含成员属性：
    Data[]                       列表元素
    Length                       列表元素个数
包含成员函数：
    void ListInsert(int inData)  在列表末尾插入元素
    void ListPopLast()           在列表末尾删除元素
    void ListShow();             打印列表
*/

// 在头文件中不要包括其他文件的include，也不要写函数的定义，包括构造函数，只用写声明
#ifndef LIST_HPP
#define LIST_HPP
#define MAX 1000

class List
{
private:
    int data[MAX] = {0};
    int length = 0;

public:
    List(/* args */);
    ~List();

    void ListInsert(int inData);
    void ListPopLast();
    void ListShow();
};

#endif