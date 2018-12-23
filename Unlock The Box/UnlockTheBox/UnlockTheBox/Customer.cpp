#include "Customer.h"

Customer::Customer()
{
    //Deliberately left empty.
}

Customer::Customer(string name, string id)
{
    _name = name;
    _id = id;
    _numPrizesWon = 0;
    _prizesWonList = vector<string>();
}

Customer::Customer(string name, string id, int numPrizesWon, vector<string> prizesWonList)
{
    _name = name;
    _id = id;
    _numPrizesWon = numPrizesWon;
    _prizesWonList = prizesWonList;
}

string Customer::getId()
{
    return _id;
}

void Customer::setId(string id)
{
    _id = id;
}

string Customer::getName()
{
    return _name;
}

void Customer::setName(string name)
{
    _name = name;
}

int Customer::getNumPrizesWon()
{
    return _numPrizesWon;
}

void Customer::setNumPrizesWon(int numPrizesWon)
{
    _numPrizesWon = numPrizesWon;
}

vector<string> Customer::getPrizesWonList()
{
    return _prizesWonList;
}

void Customer::setPrizesWonList(vector<string> prizesWonList)
{
    _prizesWonList = prizesWonList;
}


Customer::~Customer()
{
}
