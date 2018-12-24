#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include "Customer.h"
#include "TotalPrizes.h"

using namespace std;

class DisplayManager
{
public:
    
    static void displayPreviousWinners(unordered_map<string, Customer> custHash)
    {
        vector<string> custNames;

        //Alphabatize customers.
        for (auto cust : custHash)
        {
            custNames.push_back(cust.second.getName());
        }

        sort(custNames.begin(), custNames.end());

        for (auto cust : custNames)
        {
            Customer customer = custHash[cust];
            vector<string> prizesWon = customer.getPrizesWonList();

            cout << "Name: " << customer.getName() 
                << "\nPlayer id: " << customer.getId() 
                << "\nPrizes won:";

            for (auto prize : prizesWon)
            {
                if (prize == prizesWon[prizesWon.size() - 1])
                {
                    cout << " " << prize << ".";
                }
                else
                {
                    cout << " " << prize << ",";
                }
            }
            cout << endl << endl;
        }
    }

    static void displayPrizesLeft(TotalPrizes totalPrizes)
    {
        cout << "Remaining prize List:\n";
        for (int i = 0; i < totalPrizes.getTotalPrizeListSize(); i++)
        {
            vector<Prize> tierPrizeList = totalPrizes.getTierPrizeList(i);

            if (tierPrizeList.size() > 0)
            {
                cout << "Tier " << i << ": ";

                for (int j = 0; j < tierPrizeList.size(); j++)
                {
                    Prize prize = tierPrizeList[j];

                    if (!prize.getBeenWon())
                    {
                        if (j == tierPrizeList.size() - 1)
                        {
                            cout << " " << prize.getPrize() << ": "
                                << "$" << prize.getValue() << "." << endl;
                        }
                        else
                        {
                            cout << " " << prize.getPrize() << ": "
                                << "$" << prize.getValue() << ",";
                        }
                    }
                }
            }
        }
        cout << endl << endl;
    }

    static void displayTopPrizes(TotalPrizes totalPrizes)
    {
        Prize first = totalPrizes.getFirstLargestPrize();
        Prize second = totalPrizes.getSecondLargestPrize();
        Prize third = totalPrizes.getThirdLargestPrize();

        if (first.getPrize() != "")
        {
            cout << "Largest Prize: Tier " << first.getTier() << " "
                << first.getPrize() << " "
                << "$" << first.getValue() << "." << endl;

            if (second.getPrize() != "")
            {
                cout << "Seoncd largest Prize: Tier " << second.getTier() << " "
                    << second.getPrize() << " "
                    << "$" << second.getValue() << "." << endl;

                if (third.getPrize() != "")
                {
                    cout << "Third largest Prize: Tier " << third.getTier() << " "
                        << third.getPrize() << " "
                        << "$" << third.getValue() << ".\n\n";
                }
                else
                {
                    cout << "No third largest prize.\n\n";
                }
            }
            else
            {
                cout << "No second largest prize.\nNo third largest prize.\n\n";
            }
        }
        else
        {
            cout << "No prizes found.\n\n";
        }
    }
};

