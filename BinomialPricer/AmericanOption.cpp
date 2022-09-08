#include "AmericanOption.h"
#include <vector>

double AmericanOption::PriceBySnell(const BinomialModel &b) const
{
    double q = b.RiskNeutProb();
    int N = GetN();
    int R = b.GetR();
    std::vector<double> price(N+1);
    // first setting up the boundary values

    for (int i = 0; i<=N; i++)
    {
        price[i] = payoff(b.S(N,i));

    }
    double otherVal;

    // propagating backwards

    for (int n = N-1; n>=0; n--)
    {
        for (int i = 0; i<=n; i++)
        {
            otherVal = (q*price[i+1]+(1-q)*price[i])/(1+R);
            price[i] = payoff(b.S(n,i));
            if (price[i] < otherVal) price[i]=otherVal;
        }
    }
    return price[0];
};