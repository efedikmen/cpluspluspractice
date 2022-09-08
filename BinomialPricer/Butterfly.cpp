#include "Butterfly.h"

void Butterfly::SetK(double k1, double k2)
{
    if (k1>k2)
    {K1=k2;K2=k1;}
    else
    {K1=k1;K2=k2;}
};

double Butterfly::payoff(double z) const
{
    if (K1 < z && z <= (K1+K2)/2) return z-K1;
    if ((K1+K2)/2 < z && z <= K2) return K2-z;
    return 0;
}