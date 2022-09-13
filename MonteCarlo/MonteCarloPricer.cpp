#include "MonteCarloPricer.h"
#include <cmath>

MonteCarloPricer::MonteCarloPricer()
{
    Nsteps=1000;
    Npaths=100;
};

MonteCarloPricer::MonteCarloPricer(int steps, int paths)
{
    Nsteps=steps;
    Npaths=paths;
};

double MonteCarloPricer::price(const BlackScholes &bsm, PathIndependentOption &c) const
{
    double T = c.GetMaturity();
    double res=0.0;
    for (int i=0; i<Npaths; i++)
    {

        res += c.payoff(bsm.GenerateRiskNeutralPricePath(T, Nsteps).back());
    }
    return exp(-bsm.GetRate()*(T-bsm.GetTime()))*res/Npaths;

};

double MonteCarloPricer::price(const BlackScholes &bsm, PathDependentOption &u) const
{
    double T = u.GetMaturity();
    double res=0.0;
    for (int i=0; i<Npaths; i++)
    {
        res += u.payoff(bsm.GenerateRiskNeutralPricePath(T, Nsteps));
    }
    return exp(-bsm.GetRate()*(T-bsm.GetTime()))*res/Npaths;

};

double MonteCarloPricer::delta(BlackScholes &bsm, PathIndependentOption &c)
{
    double S = bsm.GetStock();
    double h = pow(10, -4);
    BlackScholes bsm1(S+h, 0, bsm.GetVol(), bsm.GetRate(), bsm.GetTime());
    BlackScholes bsm2(S-h, 0, bsm.GetVol(), bsm.GetRate(), bsm.GetTime());
    double delta = 0.0;
    for (int i=0; i<Npaths; i++)
    {
        delta += price(bsm1, c)-price(bsm2, c);
    }
    return delta/(2*h*Npaths);
};

double MonteCarloPricer::delta(BlackScholes &bsm, PathDependentOption &c)
{
    double S = bsm.GetStock();
    double h = pow(10, -4);
    BlackScholes bsm1(S+h, 0, bsm.GetVol(), bsm.GetRate(), bsm.GetTime());
    BlackScholes bsm2(S-h, 0, bsm.GetVol(), bsm.GetRate(), bsm.GetTime());
    double delta = 0.0;
    for (int i=0; i<Npaths; i++)
    {
        delta += price(bsm1, c)-price(bsm2, c);
    }
    return delta/(2*h*Npaths);
};
