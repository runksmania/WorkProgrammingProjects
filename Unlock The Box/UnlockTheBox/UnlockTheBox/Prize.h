#pragma once
#include <string>

using namespace std;

class Prize
{
private:
    string _value;
    string _prize;
    string _tier;
    bool _beenWon;

public:
    Prize();
    Prize(string prize, string value, string tierNum, bool beenWon);
    string getValue();
    string getPrize();
    string getTier();
    bool getBeenWon();
    void setBeenWon(bool beenWon);
    ~Prize();
};

