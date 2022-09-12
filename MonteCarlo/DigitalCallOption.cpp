#include "DigitalCallOption.h"

double DigitalCallOption::payoff(double z) const
{
    if (GetStrike() < z) return 1;
    return 0;
};