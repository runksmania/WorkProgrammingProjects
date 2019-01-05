#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Customer.h"
#include "TotalPrizes.h"
#include "OfferGenerator.h"
#include "Constants.h"

using namespace std;

class PromotionManager
{
public:
    
    static void runUnlockTheBox(unordered_map<string, Customer> &custHash, TotalPrizes &totalPrizes)
    {
        Customer customer;
        string winner, id, custDecision, prize, boxPrize;
        bool offerTaken = false;
        
        cout << "Enter the winners name: ";
        getline(cin, winner);
        
        if (custHash.find(winner) == custHash.end())
        {
            cout << "\nEnter " << winner << "'s player id number: ";
            getline(cin, id);

            customer = Customer(winner, id);
        }
        else
        {
            customer = custHash[winner];
        }

        string offer = OfferGenerator::generateOffer(totalPrizes);
        cout << "\n\nThe offer is: " << "$" << offer << ".\n\n"
            << "Did they take the offer (Y)es or (N)o: ";
        getline(cin, custDecision);

        cout << "Enter the prize that was in the box: ";
        getline(cin, boxPrize);
        prize = boxPrize;

        vector<string> prizesWonList = customer.getPrizesWonList();

        if (custDecision == "y" || custDecision == "Y")
        {
            prize = "Offer: " + offer;
            offerTaken = true;
        }
        
        if (!offerTaken || !Constants::getWithReplacement())
        {
            if (!totalPrizes.findPrize(boxPrize))
            {
                while (!totalPrizes.findPrize(boxPrize))
                {
                    cout << "\nPrize was not found.  Please re-enter the prize name: ";
                    getline(cin, boxPrize);
                }

            }
            
            if (!offerTaken)
            {
                prize = boxPrize;
            }
        }

        prizesWonList.push_back(prize);
        customer.setPrizesWonList(prizesWonList);
        customer.setNumPrizesWon(customer.getNumPrizesWon() + 1);
        custHash[winner] = customer;

    }
};

