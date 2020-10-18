#include <iostream>
#include "LinkList.hpp"
using namespace std;

LinkList::LinkList()
{
    LinkList::next = nullptr;
}

LinkList::LinkList(int inData, LinkList *inNext)
{
    LinkList::data = inData;
    LinkList::next = inNext;
}

LinkList::~LinkList()
{

}