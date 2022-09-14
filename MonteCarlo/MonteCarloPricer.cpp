#include "MonteCarloPricer.h"
#include <cmath>
#include "RandomGenerator.h"
#include <vector>

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
PriceAndSE MonteCarloPricer::priceWithSE(const BlackScholes &bsm, PathIndependentOption &c) const
{
    PriceAndSE ret;
    std::vector<double> pr;
    double T = c.GetMaturity();
    double t = bsm.GetTime();
    double r = bsm.GetRate();
    double res=0.0;
    for (int i=0; i<Npaths; i++)
    {
        double price = c.payoff(bsm.GenerateRiskNeutralPricePath(T, Nsteps).back())*exp(-r*(T-t));
        res += price;
        pr.push_back(price);
    }
    ret.SetPrice(res/Npaths);
    ret.SetSE(stddev(pr));
    return ret;

};
PriceAndSE MonteCarloPricer::priceWithSE(const BlackScholes &bsm, PathDependentOption &c) const
{
    PriceAndSE ret;
    std::vector<double> pr;
    double T = c.GetMaturity();
    double t = bsm.GetTime();
    double r = bsm.GetRate();
    double res=0.0;
    for (int i=0; i<Npaths; i++)
    {
        double price = c.payoff(bsm.GenerateRiskNeutralPricePath(T, Nsteps))*exp(-r*(T-t));
        res += price;
        pr.push_back(price);
    }
    ret.SetPrice(res/Npaths);
    ret.SetSE(stddev(pr)/sqrt(Npaths));
    return ret;

};
double MonteCarloPricer::delta(BlackScholes &bsm, PathIndependentOption &c)
{
    double S = bsm.GetStock();
    double h = 1e-4;
    double t = bsm.GetTime();
    double vol = bsm.GetVol();
    double r = bsm.GetRate();
    double delta = 0.0;
    double dt = (c.GetMaturity()-t)/Nsteps;
    double alpha = (r-vol*vol/2)*dt;
    double b = vol*sqrt(dt);
    double dlnS, lnSp, lnSm, currentlogSp, currentlogSm;
    std::vector<double> path1(Nsteps+1), path2(Nsteps+1);
    for (int j=0; j<Npaths; j++)
    {
        path1[0] = S+h;
        path2[0] = S-h;
        std::vector<double> normal=randn(Nsteps);
        currentlogSp = log(S+h);
        currentlogSm = log(S-h);
        for (int i=0; i<=Nsteps; i++)
        {
            dlnS = alpha + b*normal[i];
            lnSp = dlnS + currentlogSp;
            lnSm = dlnS + currentlogSm;
            path1[i+1] = exp(lnSp);
            path2[i+1] = exp(lnSm);
            currentlogSp = lnSp;
            currentlogSm = lnSm;
        }
        delta += c.payoff(path1.back()) - c.payoff(path2.back());
    }
    return delta/(Npaths*2*h);
};

double MonteCarloPricer::delta(BlackScholes &bsm, PathDependentOption &c)
{
    double S = bsm.GetStock();
    double h = 1e-4;
    double t = bsm.GetTime();
    double vol = bsm.GetVol();
    double r = bsm.GetRate();
    double delta = 0.0;
    double dt = (c.GetMaturity()-t)/Nsteps;
    double alpha = (r-vol*vol/2)*dt;
    double b = vol*sqrt(dt);
    double dlnS, lnSp, lnSm;
    for (int j=0; j<Npaths; j++)
    {
        std::vector<double> path1(Nsteps+1), path2(Nsteps+1);
        path1[0] = S+h;
        path2[0] = S-h;
        std::vector<double> normal=randn(Nsteps);
        double currentlogSp = log(S+h);
        double currentlogSm = log(S-h);
        for (int i=0; i<Nsteps; i++)
        {
            dlnS = alpha + b*normal[i];
            lnSp = dlnS + currentlogSp;
            lnSm = dlnS + currentlogSm;
            path1[i+1] = exp(lnSp);
            path2[i+1] = exp(lnSm);
            currentlogSp = lnSp;
            currentlogSm = lnSm;
        }
        delta += c.payoff(path1) - c.payoff(path2);
    }
    return delta/(2*h*Npaths);
};
