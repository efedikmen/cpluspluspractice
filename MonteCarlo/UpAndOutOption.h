#pragma once
#include "PathDependentOption.h"

class UpAndOutOption: public virtual PathDependentOption
{
    public:
        UpAndOutOption(double T, double K, double b);
        ~UpAndOutOption(){};
        virtual double payoff(std::vector<double>) const;
};