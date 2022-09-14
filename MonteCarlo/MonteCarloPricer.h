#pragma once
#include "BlackScholes.h"
#include "PathDependentOption.h"
#include "PathIndependentOption.h"
#include "PriceAndSE.h"


class MonteCarloPricer
{
    private:
        int Nsteps;
        int Npaths;
    public:
        MonteCarloPricer();
        MonteCarloPricer(int steps, int paths);
        ~MonteCarloPricer(){};
        double price(const BlackScholes &bsm, PathIndependentOption &c) const;
        double price(const BlackScholes &bsm, PathDependentOption &k) const;
        PriceAndSE priceWithSE(const BlackScholes &bsm, PathIndependentOption &c) const;
        PriceAndSE priceWithSE(const BlackScholes &bsm, PathDependentOption &c) const;
        double delta(BlackScholes &bsm, PathIndependentOption &c);
        double delta(BlackScholes &bsm, PathDependentOption &k);
};