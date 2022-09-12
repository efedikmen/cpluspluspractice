#include "BlackScholes.h"
#include "RandomGenerator.h"

BlackScholes::BlackScholes(double s, double mu, double sigma, double r, double time)
{
    S0=s;
    drift=mu;
    vol=sigma;
    rate=r;
    t=time;
};

std::vector<double> BlackScholes::GeneratePricePath(double toDate, int Nsteps, double mu) const
{
    std::vector<double> path(Nsteps+1);
    path[0] = S0;
    std::vector<double> normal=randn(Nsteps);
    double dt = (toDate-t)/Nsteps;
    double alpha = (mu - vol*vol/2)*dt;
    double b = vol*sqrt(dt);
    double lnS0 = log(S0);
    double currentlogS = lnS0;
    for (int i=0; i<Nsteps; i++)
    {
        double dlnS = alpha + b*normal[i];
        double lnS = dlnS + currentlogS;
        path[i+1] = exp(lnS);
        currentlogS = lnS;
    }
    return path;
};

std::vector<double> BlackScholes::GeneratePricePath(double toDate, int Nsteps) const
{
    return GeneratePricePath(toDate, Nsteps, drift);
};

std::vector<double> BlackScholes::GenerateRiskNeutralPricePath(double toDate, int Nsteps) const
{
    return GeneratePricePath(toDate, Nsteps, rate); // drift=risk free rate under the risk neutral measure
};
