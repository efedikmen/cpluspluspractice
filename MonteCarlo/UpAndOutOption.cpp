#include "UpAndOutOption.h"

UpAndOutOption::UpAndOutOption(double T, double K, double b)
{
    SetBarrier(b);
    SetMaturity(T);
    SetStrike(K);
    // max payoff initialized as 0
    // knock out status already initialized as false
};

double UpAndOutOption::payoff(std::vector<double> z) const
{
    double B = GetBarrier();
    double K = GetStrike();
    double max_payoff=0;
    for (double a:z)
    {
        if (a>=B) return 0;
        if (a-K>max_payoff) max_payoff=a-K;
    };
    return max_payoff;
};