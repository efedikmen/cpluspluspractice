#pragma once
#include "Option.h"
#include <vector>

class PathDependentOption:public virtual Option
{
    private:
        double B; // barrier
    public:
        void SetBarrier(double b){B=b;};
        double GetBarrier() const {return B;};
        virtual ~PathDependentOption(){};
        virtual double payoff(std::vector<double>) const=0;
};