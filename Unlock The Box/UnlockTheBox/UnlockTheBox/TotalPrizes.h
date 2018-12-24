#pragma once
#include <vector>
#include "Prize.h"

using namespace std;

class TotalPrizes
{
private:
    Prize _firstLargestPrize;
    Prize _secondLargestPrize;
    Prize _thirdLargestPrize;
    Prize _foundPrize;
    int _sum;
    int _numRemainingPrizes;
    double _average;
    vector<vector<Prize>> _prizeList;

public:
    TotalPrizes();
    Prize getFirstLargestPrize();
    void setFirstLargestPrize(Prize first);
    Prize getSecondLargestPrize();
    void setSecondargestPrize(Prize second);
    Prize getThirdLargestPrize();
    void setThirdLargestPrize(Prize third);
    int getSum();
    void setSum(int sum);
    int getNumRemainingPrizes();
    void setNumRemainingPrizes(int numRemainingPrizes);
    double getAverage();
    void setAverage(double average);
    int getTotalPrizeListSize();
    vector<Prize> getTierPrizeList(int tierNum);
    void setTierPrizeList(int tierNum, vector<Prize> tierPrizeList);
    bool findPrize(string prize);
    ~TotalPrizes();
};

