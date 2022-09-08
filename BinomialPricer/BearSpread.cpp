#include "BearSpread.h"

void BearSpread::SetK(double k1, double k2)
{
    if (k1>k2)
    {
        K1 = k2;
        K2 = k1;
    }
    else
    {
        K1 = k1;
        K2 = k2;
    }
};

double BearSpread::payoff(double z) const
{
    if (z > K2)
    {return 0;}
    else if (z < K1)
    {return K2-K1;}
    else
    {return K2-z;}
};