#pragma once
#include "BlackScholes.h"
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
        double price(const BlackScholes &bsm, const PathIndependentOption &c) const;
};