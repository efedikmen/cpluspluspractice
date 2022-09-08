#include "DoubleDigitalOption.h"

void DoubleDigitalOption::SetK(double k1, double k2)
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

double DoubleDigitalOption::payoff(double z) const
{
    if (z>K1 && z<K2) return 1;
    return 0;
};