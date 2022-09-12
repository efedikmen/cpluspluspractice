#pragma once
#include "BlackScholes.h"

class PathIndependentOption
{
    private:
        double T; // maturity time
        double K; // strike
    public:
        double GetMaturity() const {return T;};
        double GetStrike() const {return K;};
        void SetMaturity(double time) {T=time;}
        void SetStrike(double strike) {K=strike;}
        virtual double payoff(double z) const=0;
        virtual double price(const BlackScholes &bsm) const=0;
        virtual ~PathIndependentOption(){};
};