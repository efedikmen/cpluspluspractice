#include "Call.h"

double Call::payoff(double z) const
{
    return (z>K) ? (z-K):(0.0);
};