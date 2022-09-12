#include "CallOption.h"
#include <cmath>
#include "NormalDistribution.h"

double CallOption::payoff(double z)
{
    if (GetStrike()<z) return z-GetStrike();
    return 0;
};

// based on the solution of Black Scholes
double CallOption::price(const BlackScholes &bsm) const
{
    double S=bsm.GetStock();
    double K=GetStrike();
    double time = GetMaturity()-bsm.GetTime();
    double r = bsm.GetRate();
    double vol = bsm.GetVol();
    double d1 = (log(S/K)+r*time)/(vol*sqrt(time))+0.5*vol*sqrt(time);
    double d2 = d1 - vol*sqrt(time);
    return S*normcdf(d1)-K*exp(-r*time)*normcdf(d2);
};