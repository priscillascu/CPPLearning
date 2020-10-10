#include <iostream>

using namespace std;

struct HeroInfo
{
    string heroName;
    short heroAge;
};

void HeroAgeSort(HeroInfo heroArray[], int heroNum)  // 直接传入数组名，相当于是地址传递了，所以数组会改变
{
    for (int inposNum = 0; inposNum < heroNum - 1; ++inposNum)
    {
        for (int selectNum = 0; selectNum < heroNum - 1 - inposNum; ++selectNum)
        {
            if(heroArray[selectNum].heroAge < heroArray[selectNum + 1].heroAge)
            {
                HeroInfo temp;
                temp = heroArray[selectNum];
                heroArray[selectNum] = heroArray[selectNum + 1];
                heroArray[selectNum + 1] = temp;
            }
        }
        
    }
    
}

void HeroPrint(HeroInfo hero[], int heroNum)
{
    for (int i = 0; i < heroNum; ++i)
    {
        cout << hero[i].heroName << "    " << hero[i].heroAge << endl;
    }
    
}

int main()
{
    HeroInfo heroArray[5] = 
    {
        {"Bob", 10},
        {"cli", 5},
        {"Tom", 12},
        {"Jay", 7},
        {"Pup", 1}
    };
    HeroAgeSort(heroArray, 5);
    HeroPrint(heroArray, 5);
    return 0;
}