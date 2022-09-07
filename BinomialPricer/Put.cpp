#include "Put.h"

double Put::payoff(double z) const
{
    return (z<K) ? (K-z):(0.0);
};