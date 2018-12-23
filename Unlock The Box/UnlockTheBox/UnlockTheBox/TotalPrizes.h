#pragma once
#include <vector>
#include "Prize.h"

using namespace std;

class TotalPrizes
{
private:
    vector<vector<Prize>> _prizeList;

public:
    TotalPrizes();
    int getTotalPrizeListSize();
    vector<Prize> getTierPrizeList(int tierNum);
    void setTierPrizeList(int tierNum, vector<Prize> tierPrizeList);
    ~TotalPrizes();
};

