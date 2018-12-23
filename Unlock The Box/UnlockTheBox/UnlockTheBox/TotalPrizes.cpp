#include "TotalPrizes.h"



TotalPrizes::TotalPrizes()
{
    _prizeList.resize(10);

    for (auto prize : _prizeList)
    {
        prize = vector<Prize>();
    }
}

int TotalPrizes::getTotalPrizeListSize()
{
    return _prizeList.size();
}

vector<Prize> TotalPrizes::getTierPrizeList(int tierNum)
{
    return _prizeList[tierNum];
}

void TotalPrizes::setTierPrizeList(int tierNum, vector<Prize> tierPrizeList)
{
    _prizeList[tierNum] = tierPrizeList;
}

TotalPrizes::~TotalPrizes()
{
}
