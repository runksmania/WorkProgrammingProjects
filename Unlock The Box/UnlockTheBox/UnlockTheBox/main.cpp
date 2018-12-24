#include <iostream>
#include <string>
#include <unordered_map>
#include "Constants.h"
#include "FileManager.h"
#include "TotalPrizes.h"
#include "DisplayManager.h"
#include "PromotionManager.h"

using namespace std;

int main() 
{
    FileManager *fileManager = new FileManager(Constants::getCustFilename(), Constants::getPrizeFilename());
    
    unordered_map<string, Customer> custHash = fileManager->loadCustomerFile();
    TotalPrizes totalPrizes = fileManager->loadPrizeFile();
    
    //The following code is for debugging, and writing the files to the screen.
    //fileManager->writeCustomerFile(custHash);    
    //fileManager->writePrizeFile(totalPrizes);

    enum choices { EXIT = 0, PREVIOUS_WINNERS, REMAINING_PRIZES, START_PROMOTION };
    string choice, promotionOver = "n";
    cout << "Welcome. Please the enter number of the option you would like from the following:\n"
        << "1. Display previous winners.\n"
        << "2. Display remaining prizes.\n"
        << "3. Start today's promotion.\n"
        << "Any other option will exit the program.\n";
    getline(cin, choice);
    cout << endl;

    if (choice[0] > '3' || choice[0] < '0')
    {
        choice = "0";
    }

    while (choices(stoi(choice)) != EXIT)
    {
        switch (choices(stoi(choice)))
        {
        case PREVIOUS_WINNERS:
            
            DisplayManager::displayPreviousWinners(custHash);
            break;

        case REMAINING_PRIZES:

            DisplayManager::displayPrizesLeft(totalPrizes);
            break;

        case START_PROMOTION:
            
            DisplayManager::displayTopPrizes(totalPrizes);

            while (promotionOver == "n" || promotionOver == "N")
            {
                PromotionManager::runUnlockTheBox(custHash, totalPrizes);

                cout << "Is the promotion over? (N)o continues, anything else exits.\n";
                getline(cin, promotionOver);
                cout << endl;
            }

            break;

        }

        if (promotionOver == "n" || promotionOver == "N")
        {
            cout << "Please the enter number of the option you would like from the following:\n"
                << "1. Display previous winners.\n"
                << "2. Display remaining prizes.\n"
                << "3. Start today's promotion.\n"
                << "Any other option will exit the program.\n";
            getline(cin, choice);
            cout << endl;

            if (choice[0] > '3' || choice[0] < '0')
            {
                choice = "0";
            }
        }
        else
        {
            cout << "Please the enter number of the option you would like from the following:\n"
                << "1. Display previous winners.\n"
                << "2. Display remaining prizes.\n"
                << "Any other option will exit the program.\n";
            getline(cin, choice);
            cout << endl;

            if (choice[0] > '2' || choice[0] < '0')
            {
                choice = "0";
            }
        }
    }

    fileManager->saveCustomerFile(custHash);
    fileManager->savePrizeFile(totalPrizes);

    delete fileManager;
    return 0;
}