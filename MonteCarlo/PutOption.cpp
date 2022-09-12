#include "PutOption.h"
#include "NormalDistribution.h"
#include <cmath>

double PutOption::payoff(double z) const
{
    if (GetStrike()>z) return GetStrike()-z;
    return 0;
};

double PutOption::price(const BlackScholes &bsm) const
{
    double S=bsm.GetStock();
    double K=GetStrike();
    double time = GetMaturity()-bsm.GetTime();
    double r = bsm.GetRate();
    double vol = bsm.GetVol();
    double d1 = (log(S/K)+r*time)/(vol*sqrt(time))+0.5*vol*sqrt(time);
    double d2 = d1 - vol*sqrt(time);
    return K*exp(-r*time)*normcdf(-d2)-S*normcdf(-d1);
};