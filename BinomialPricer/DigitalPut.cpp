#include "DigitalPut.h"

double DigitalPut::payoff(double z) const
{
    if (K>z) return 1;
    return 0;
};