#include "PathDependentOption.h"

class ArithmeticAsianPut:public virtual PathDependentOption
{
    public:
        ArithmeticAsianPut(double T, double K) {SetMaturity(T);SetStrike(K);};
        double payoff(std::vector<double> z) const;
};