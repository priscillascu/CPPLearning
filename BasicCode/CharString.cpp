#include <iostream>
//可以不用#include <string>，因为iostream中已经include了string
using namespace std;

int main()
{
    char ch1 = 'a';
    // 不能char一个字符串，如char ch2 = 'adfa';
    char str1[] = "Hello Char\n";
    // char str[]就可以用"""来表示字符串了

    string str2 = "Hello String\n";
    cout << str1 << str2;
    return 0;
}