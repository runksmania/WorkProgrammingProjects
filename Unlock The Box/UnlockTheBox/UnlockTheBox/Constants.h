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
        return "Resource Files/customerFile.csv";
    }

    static string getPrizeFilename()
    {
        return "Resource Files/prizeFile.csv";
    }

    static string defaultcustomerFile()
    {
        return "Customer Name, Id number, number prizes won\n"
            "List of Prizes\n";

    }

    static string defaultPrizeFile()
    {
        return "Prize name,Value, Each line is a prize tier.\n"
            "TV Pkg 1, 750, 0\n"
            "TV Pkg 2, 500, 0\n"
            "TV1, 250, 0, Roomba, 250, 0\n"
            "Cash 150, 150, 0, Cash 150, 150, 0\n"
            "Cash 125, 125, 0, Cash 125, 125, 0\n"
            "Free Play 80, 80, 0, Free Play 80, 80, 0, Cash 80, 80, 0, Cash 80, 80, 0\n"
            "Cash 25,0, Cash 25,0, Cash 25,0, Cash 25,0, Cash 25,0, Cash 25,0, Cash 25,0, Cash 25,0, Cash 25,0, Cash 25,0, Cash 25,0\n"
            "Cash 15, 15, 0\n";
    }

    static bool getWithReplacement()
    {
        return _withReplacement;
    }
};
