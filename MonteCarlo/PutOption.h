#pragma once
#include "PathIndependentOption.h"

class PutOption: public virtual PathIndependentOption
{
    public:
        PutOption(double t, double s) {SetMaturity(t); SetStrike(s);};
        virtual double payoff(double z);
        virtual double price(const BlackScholes &bsm) const;
        virtual ~PutOption(){};
};
