#include <algorithm>
#include <iostream>
#include "FileManager.h"
#include "StringSplitter.h"
#include "TotalPrizes.h"

FileManager::FileManager(string custFileName, string prizeFileName)
{
    _custFileName = custFileName;
    _prizeFileName = prizeFileName;
}

unordered_map<string, Customer> FileManager::loadCustomerFile()
{
    unordered_map<string, Customer> custHash;
    ifstream inputFile;

    inputFile.open(_custFileName);

    if (inputFile.good())
    {
        while (inputFile.good())
        {
            string currentLine, prizesWonLine;

            getline(inputFile, currentLine);
            vector<string> lineSplit = StringSplitter::split(currentLine, ",");
            getline(inputFile, prizesWonLine);
            vector<string> prizesWonSplit = StringSplitter::split(prizesWonLine, ",");

            if (currentLine != "")
            {
                Customer customer = Customer(lineSplit[0], lineSplit[1], stoi(lineSplit[2]), prizesWonSplit);
                custHash[customer.getName()] = customer;
            }
        }
    }
    else
    {
        cout << "Error reading file.\n";
    }

    inputFile.close();

    return custHash;
}

void FileManager::saveCustomerFile(unordered_map<string, Customer> custHash)
{
    vector<string> custNames;
    ofstream outputFile;
    outputFile.open(_custFileName);

    //Alphabatize customers.
    for (auto cust : custHash)
    {
        custNames.push_back(cust.second.getName());
    }

    sort(custNames.begin(), custNames.end());

    if (outputFile.good())
    {
        for (auto cust : custNames)
        {
            Customer customer = custHash[cust];
            vector<string> prizesWon = customer.getPrizesWonList();

            outputFile << customer.getName() << ","
                << customer.getId() << ","
                << customer.getNumPrizesWon() << endl;

            for (auto prize : prizesWon)
            {
                if (prize == prizesWon[prizesWon.size() - 1])
                {
                    outputFile << prize << endl;
                }
                else
                {
                    outputFile << prize << ",";
                }
            }
        }
    }
    else
    {
        cout << "Error writing file.\n";
    }
}

void FileManager::writeCustomerFile(unordered_map<string, Customer> custHash)
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

        cout << customer.getName() << ","
            << customer.getId() << ","
            << customer.getNumPrizesWon() << endl;

        for (auto prize : prizesWon)
        {
            if (prize == prizesWon[prizesWon.size() - 1])
            {
                cout << prize;
            }
            else
            {
                cout << prize << ",";
            }
        }
        cout << endl;
    }
    cout << endl;
}

TotalPrizes FileManager::loadPrizeFile()
{
    TotalPrizes totalPrizes = TotalPrizes();
    ifstream inputFile;
    inputFile.open(_prizeFileName);

    if (inputFile.good())
    {
        //The line number in file = tier number of prize.
        //Count is the number of prizes not won.
        //Sum is the total value of all prizes not yet won.
        //Average is the average of all prizes not yet won.
        int lineNum = 1, count = 0, sum = 0;
        double average = 0.0;

        while (inputFile.good())
        {
            vector<Prize> tierPrizes;
            string currentLine;

            getline(inputFile, currentLine);

            if (currentLine != "")
            {
                vector<string> lineSplit = StringSplitter::split(currentLine, ",");

                for (int i = 0; i < lineSplit.size(); i += 3)
                {
                    bool beenWon = false;
                    Prize prize(lineSplit[i], lineSplit[i + 1], to_string(lineNum), beenWon);

                    if (lineSplit[i + 2] == "1")
                    {
                        beenWon = true;
                        prize.setBeenWon(beenWon);
                    }
                    else
                    {
                        count++;
                        int newPrizeValue = stoi(prize.getValue());
                        sum += newPrizeValue;

                        int firstPrizeValue = stoi(totalPrizes.getFirstLargestPrize().getValue());
                        int secondPrizeValue = stoi(totalPrizes.getSecondLargestPrize().getValue());
                        int thirdPrizeValue = stoi(totalPrizes.getThirdLargestPrize().getValue());

                        if (newPrizeValue > firstPrizeValue)
                        {
                            totalPrizes.setThirdLargestPrize(totalPrizes.getSecondLargestPrize());
                            totalPrizes.setSecondargestPrize(totalPrizes.getFirstLargestPrize());
                            totalPrizes.setFirstLargestPrize(prize);
                        }
                        else if (newPrizeValue > secondPrizeValue)
                        {
                            totalPrizes.setThirdLargestPrize(totalPrizes.getSecondLargestPrize());
                            totalPrizes.setSecondargestPrize(prize);
                        }
                        else if (newPrizeValue > thirdPrizeValue)
                        {
                            totalPrizes.setThirdLargestPrize(prize);
                        }

                    }

                    tierPrizes.push_back(prize);
                }

                totalPrizes.setTierPrizeList(lineNum, tierPrizes);
                lineNum++;
            }
        }

        totalPrizes.setNumRemainingPrizes(count);
        totalPrizes.setSum(sum);
        average = sum / (double)count;
        totalPrizes.setAverage(average);
    }
    else
    {
        cout << "Error reading file.\n";
    }

    return totalPrizes;
}

void FileManager::savePrizeFile(TotalPrizes totalPrizes)
{
    ofstream outputFile;
    outputFile.open(_prizeFileName);

    if (outputFile.good())
    {
        for (int i = 0; i < totalPrizes.getTotalPrizeListSize(); i++)
        {
            vector<Prize> tierPrizeList = totalPrizes.getTierPrizeList(i);

            for (int j = 0; j < tierPrizeList.size(); j++)
            {
                Prize prize = tierPrizeList[j];
                string beenWon = "0";

                if (prize.getBeenWon())
                {
                    beenWon = "1";
                }

                if (j == tierPrizeList.size() - 1)
                {
                    outputFile << prize.getPrize() << ","
                        << prize.getValue() << ","
                        << beenWon;

                    if (i != totalPrizes.getTotalPrizeListSize() - 1)
                    {
                        outputFile << endl;
                    }
                }
                else
                {
                    outputFile << prize.getPrize() << ","
                        << prize.getValue() << ","
                        << beenWon << ",";
                }

            }
        }
    }
    else
    {
        cout << "Error writing file.\n";
    }
}

void FileManager::writePrizeFile(TotalPrizes totalPrizes)
{
    for (int i = 0; i < totalPrizes.getTotalPrizeListSize(); i++)
    {
        vector<Prize> tierPrizeList = totalPrizes.getTierPrizeList(i);

        for (int j = 0; j < tierPrizeList.size(); j++)
        {
            Prize prize = tierPrizeList[j];
            string beenWon = "0";

            if (prize.getBeenWon())
            {
                beenWon = "1";
            }

            if (j == tierPrizeList.size() - 1)
            {
                cout << prize.getPrize() << ","
                    << "$" << prize.getValue() << ","
                    << beenWon << endl;
            }
            else
            {
                cout << prize.getPrize() << ","
                    << "$" << prize.getValue() << ","
                    << beenWon << ",";
            }

        }
    }
    cout << endl;
}

FileManager::~FileManager()
{
}
