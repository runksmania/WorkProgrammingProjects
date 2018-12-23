#pragma once
#include <string>
#include <unordered_map>
#include <fstream>
#include "Customer.h"
#include "TotalPrizes.h"

using namespace std;

class FileManager
{
private:
    string _custFileName;
    string _prizeFileName;

    //Disable default constructor
    FileManager();

public:
    FileManager(string custFileName, string prizeFileName);
    unordered_map<string, Customer> loadCustomerFile();
    void saveCustomerFile(unordered_map<string, Customer> custHash);
    void writeCustomerFile(unordered_map<string, Customer> custHash);
    TotalPrizes loadPrizeFile();
    void savePrizeFile(TotalPrizes totalPrizes);
    void writePrizeFile(TotalPrizes totalPrizes);    
    ~FileManager();
};

