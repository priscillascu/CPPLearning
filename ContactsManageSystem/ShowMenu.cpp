#include "ShowMenu.hpp"

// 使用函数文件时，g++编译要把函数文件加到一起进行编译
void ShowMenu(void)
{
    cout << "1.Add contacts" << endl;
    cout << "2.Show all contacts" << endl;
    cout << "3.Delete contact" << endl;
    cout << "4.Search contact" << endl;
    cout << "5.Change contact" << endl;
    cout << "6.*Delete ALL contacts" << endl;
    cout << "0.Exit" << endl;
}