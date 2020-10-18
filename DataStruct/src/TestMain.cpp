#include <iostream>
#include "List.hpp"

using namespace std;

int main()
{
    List L1;
    L1.ListPopLast();
    for (int i = 0; i < 5; ++i)
    {
        L1.ListInsert(i);
    }
    L1.ListShow();
    L1.ListPopLast();
    L1.ListShow();
    
    return 0;
}