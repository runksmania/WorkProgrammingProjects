#include "Prize.h"

Prize::Prize()
{
    //Deliberately left empty.
}

Prize::Prize(string prize, string value, string tierNum, bool beenWon)
{
    _value = value;
    _prize = prize;
    _tier = tierNum;
    _beenWon = beenWon;
}

string Prize::getValue()
{
    return _value;
}

string Prize::getPrize()
{
    return _prize;
}

string Prize::getTier()
{
    return _tier;
}

bool Prize::getBeenWon()
{
    return _beenWon;
}

void Prize::setBeenWon(bool beenWon)
{
    _beenWon = beenWon;
}


Prize::~Prize()
{
}
