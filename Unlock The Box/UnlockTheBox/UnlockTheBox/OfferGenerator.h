#pragma once
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "TotalPrizes.h"

class OfferGenerator
{
public:
    
    static string generateOffer(TotalPrizes totalPrizes)
    {
        string offerType = "Cash";
        string offer = "0";
        
        double offerDouble = totalPrizes.getAverage() * .7;
        offer = to_string((int)ceil(offerDouble));

        srand(time(NULL));


        if (rand() % 2 == 1)
        {
            offerType = "FreePlay";
            offer = to_string((int)ceil(offerDouble * 1.5));
        }

        return (offer + " " + offerType);
    }
};

