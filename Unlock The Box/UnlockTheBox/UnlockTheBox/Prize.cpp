#include "Prize.h"



Prize::Prize(string prize, string value, bool beenWon)
{
    _value = value;
    _prize = prize;
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

bool Prize::getBeenWon()
{
    return _beenWon;
}


Prize::~Prize()
{
}
