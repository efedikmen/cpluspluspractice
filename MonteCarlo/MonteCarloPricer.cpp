#include "MonteCarloPricer.h"
#include <cmath>

MonteCarloPricer::MonteCarloPricer()
{
    Nsteps=100;
    Npaths=10000;
};

MonteCarloPricer::MonteCarloPricer(int steps, int paths)
{
    Nsteps=steps;
    Npaths=paths;
};

double MonteCarloPricer::price(const BlackScholes &bsm, const PathIndependentOption &c) const
{
    double T = c.GetMaturity();
    double res=0.0;
    for (int i=0; i<Npaths; i++)
    {

        res += c.payoff(bsm.GenerateRiskNeutralPricePath(T, Nsteps).back());
    }
    return exp(-bsm.GetRate()*(T-bsm.GetTime()))*res/Npaths;

};
