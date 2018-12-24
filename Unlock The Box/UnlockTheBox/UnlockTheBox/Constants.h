#pragma once
#include <string>

using namespace std;

class Constants
{
private:    
    const static bool _withReplacement = false;

public:
    static string getCustFilename()
    {
        return "customerFile.csv";
    }

    static string getPrizeFilename()
    {
        return "prizeFile.csv";
    }

    static bool getWithReplacement()
    {
        return _withReplacement;
    }
};