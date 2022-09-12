#pragma once
#include "PathIndependentOption.h"

class CallOption: public virtual PathIndependentOption
{
    public:
        CallOption(double t, double s) {SetMaturity(t); SetStrike(s);};
        virtual double payoff(double z);
        virtual double price(const BlackScholes &bsm) const;
        virtual ~CallOption(){};
};