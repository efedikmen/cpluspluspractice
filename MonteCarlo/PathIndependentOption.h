#pragma once
#include "Option.h"
#include "BlackScholes.h"

class PathIndependentOption:public virtual Option
{
    public:
        virtual double payoff(double z) =0;
        virtual double price(const BlackScholes &bsm) const=0;
        virtual ~PathIndependentOption(){};
};