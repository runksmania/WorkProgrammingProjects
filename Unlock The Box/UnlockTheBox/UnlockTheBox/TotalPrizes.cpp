#include "TotalPrizes.h"

TotalPrizes::TotalPrizes()
{
    _firstLargestPrize = Prize("", "0", "0", false);
    _secondLargestPrize = Prize("", "0", "0", false);
    _thirdLargestPrize = Prize("", "0", "0", false);
    _prizeList.resize(10);

    for (auto prize : _prizeList)
    {
        prize = vector<Prize>();
    }
}

Prize TotalPrizes::getFirstLargestPrize()
{
    return _firstLargestPrize;
}

void TotalPrizes::setFirstLargestPrize(Prize first)
{
    _firstLargestPrize = first;
}

Prize TotalPrizes::getSecondLargestPrize()
{
    return _secondLargestPrize;
}

void TotalPrizes::setSecondargestPrize(Prize second)
{
    _secondLargestPrize = second;
}

Prize TotalPrizes::getThirdLargestPrize()
{
    return _thirdLargestPrize;
}

void TotalPrizes::setThirdLargestPrize(Prize third)
{
    _thirdLargestPrize = third;
}

int TotalPrizes::getSum()
{
    return _sum;
}

void TotalPrizes::setSum(int sum)
{
    _sum = sum;
}

int TotalPrizes::getNumRemainingPrizes()
{
    return _numRemainingPrizes;
}

void TotalPrizes::setNumRemainingPrizes(int numRemainingPrizes)
{
    _numRemainingPrizes = numRemainingPrizes;
}

void TotalPrizes::setAverage(double average)
{
    _average = average;
}

double TotalPrizes::getAverage()
{
    return _average;
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

bool TotalPrizes::findPrize(string prize)
{
    for (auto &&prizeVector : _prizeList)
    {
        for (auto &&prizes : prizeVector)
        {
            if (prize == prizes.getPrize())
            {
                prizes.setBeenWon(true);
                _sum -= stoi(prizes.getValue());
                _numRemainingPrizes--;
                _average = _sum / (double)_numRemainingPrizes;
                return true;
            }
        }
    }

    return false;
}

TotalPrizes::~TotalPrizes()
{
}
