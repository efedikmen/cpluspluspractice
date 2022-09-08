#include "DigitalCall.h"

double DigitalCall::payoff(double z) const
{
    if (GetK() < z) return 1;
    return 0;
};