#pragma once
#include <vector>
#include <string>

using namespace std;

class Customer
{

private:
    string _id;
    string _name;
    int _numPrizesWon;
    vector<string> _prizesWonList;

public:
    Customer();
    Customer(string name, string id);
    Customer(string name, string id, int numPrizesWon, vector<string> prizesWonList);
    string getId();
    void setId(string id);
    string getName();
    void setName(string name);
    int getNumPrizesWon();
    void setNumPrizesWon(int numPrizesWon);
    vector<string> getPrizesWonList();
    void setPrizesWonList(vector<string> prizesWonList);
    ~Customer();
};

