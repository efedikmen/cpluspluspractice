#include "BullSpread.h"

void BullSpread::SetK(double k1, double k2)
{
    if (k1>k2)
    {
        K2=k1;
        K1=k2;
    }
    else
    {
        K1=k1;
        K2=k2;
    }
};

double BullSpread::payoff(double z) const
{
    if (z < K1)
    {return 0;}
    else if (z > K2)
    {return K2-K1;}
    else
    {return z-K1;}
};