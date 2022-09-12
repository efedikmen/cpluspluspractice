#include "DigitalCallOption.h"

double DigitalCallOption::payoff(double z)
{
    if (GetStrike() < z) return 1;
    return 0;
};