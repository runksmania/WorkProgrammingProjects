#pragma once
#include <string>

using namespace std;

class Prize
{
private:
    string _value;
    string _prize;
    bool _beenWon;

    //Disable default constructor.
    Prize();

public:
    Prize(string prize, string value, bool beenWon);
    string getValue();
    string getPrize();
    bool getBeenWon();
    ~Prize();
};

