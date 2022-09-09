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

double AmericanOption::PriceBySnell(const BinomialModel &b, BinomialLattice<double> &prices,
                            BinomialLattice<bool> &stop) const
{
    double q = b.RiskNeutProb();
    int N = GetN();
    int R = b.GetR();
    prices.SetN(N);
    stop.SetN(N);
    double otherVal;
    for (int i=0; i<=N; i++)
    {
        prices.SetNode(N,i, payoff(b.S(N,i)));
        stop.SetNode(N,i,1);
    }
    for (int n=N-1; n>=0; n--)
    {
        for (int i=0; i<=n; i++)
        {
            otherVal = (q*prices.GetNode(n+1,i+1)+(1-q)*prices.GetNode(n+1,i))/(1+R);
            prices.SetNode(n,i, payoff(b.S(n,i)));
            stop.SetNode(n,i,1);
            if (otherVal>prices.GetNode(n,i))
            {
                prices.SetNode(n,i,otherVal);
                stop.SetNode(n,i,0);
                
            }
            else if (prices.GetNode(n,i) == 0.0)
            {
                stop.SetNode(n,i,0);
            }
        }
    }
    prices.Display();
    stop.Display();
    return prices.GetNode(0,0);

};