#pragma once
#include "PathDependentOption.h"

class ArithmeticAsianCall:public virtual PathDependentOption
{
    public:
        ArithmeticAsianCall(double T, double K){SetMaturity(T);SetStrike(K);};
        virtual double payoff(std::vector<double> z) const;
};      