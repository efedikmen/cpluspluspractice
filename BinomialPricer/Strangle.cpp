#include "Strangle.h"

void Strangle::SetK(double k1, double k2)
{
    if (k1 > k2)
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

double Strangle::payoff(double z) const
{
    if (K1>z) return K1-z;
    if (K2<z) return z-K2;
    return 0;
};