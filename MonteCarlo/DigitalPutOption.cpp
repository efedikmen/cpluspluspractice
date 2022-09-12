#include "DigitalPutOption.h"

double DigitalPutOption::payoff(double z)
{
    if (GetStrike()>z) return 1;
    return 0;
};