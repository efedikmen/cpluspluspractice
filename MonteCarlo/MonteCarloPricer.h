#pragma once
#include "BlackScholes.h"
#include "PathDependentOption.h"
#include "PathIndependentOption.h"


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
};