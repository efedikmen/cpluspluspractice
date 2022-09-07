#include "EuropeanOption.h"
#include <vector>

double EuropeanOption::PriceByCRR(const BinomialModel &b) const
{
    double q = b.RiskNeutProb();
    int N = GetN();
    std::vector<double> price(N+1);
    for (int i=0; i<=N; i++)
    {
        price[i]= payoff(b.S(N,i)); // setting boundary values
    }
    for (int i=N-1; i>=0; i--)
    {
        for (int j=0; j<=i; j++)
        {
            price[i] = (q*price[i+1]+(1-q)*price[i])/(1+b.GetR());
        }
    }
    return price[0];
};