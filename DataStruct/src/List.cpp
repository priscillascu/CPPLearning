// 在源文件中包含所有需要的头文件和作用域
#include <iostream>
#include "List.hpp"
using std::cout;
using std::endl;

List::List(/* args */)
{
}

List::~List()
{
}

// 打印列表所有元素
void List::ListShow()
{
    cout << "******Your list******" << endl;
    for (int i = 0; i < List::length; ++i)
    {
        cout << List::data[i] << "  " << endl;
    }
    
}

// 在列表末尾插入元素
void List::ListInsert(int inData)
{
    cout << "****Insert " << inData << " at last****" << endl;
    List::data[length] = inData;
    List::length++;
}

// 在列表末尾删除元素
void List::ListPopLast()
{
    if(List::length == 0)
    {
        cout << "******Nothing to delete******" << endl;
        return;
    }
    else
    {
        cout << "******Delete the last one******" << endl;
        List::length--;
    }
    
}