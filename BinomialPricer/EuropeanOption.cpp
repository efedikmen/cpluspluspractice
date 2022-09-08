#include "EuropeanOption.h"
#include <vector>
#include "BinomialLattice.h"

double EuropeanOption::PriceByCRR(const BinomialModel &b) const
{
    double q = b.RiskNeutProb();
    double R = b.GetR();
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
            price[j] = (q*price[j+1]+(1-q)*price[j])/(1+R);
        }
    }
    return price[0];
};

double EuropeanOption::PriceByCRR(const BinomialModel &b, BinomialLattice<double> &prices, 
        BinomialLattice<double> &strategy, BinomialLattice<double> &rates) const
{
    double q = b.RiskNeutProb();
    double R = b.GetR();
    int N = GetN();
    prices.SetN(N);
    strategy.SetN(N-1);
    rates.SetN(N-1);
    for (int i=0; i<=N; i++)
    {
        prices.SetNode(N,i,payoff(b.S(N,i))); // setting boundary values
    }
    for (int i=N-1; i>=0; i--)
    {
        for (int j=0; j<=i; j++)
        {
            strategy.SetNode(i,j,(prices.GetNode(i+1,j+1)-prices.GetNode(i+1,j))/(b.S(i+1,j+1)-b.S(i+1,j)));
            prices.SetNode(i,j,(q*prices.GetNode(i+1,j+1)+(1-q)*prices.GetNode(i+1,j))/(1+R));
            rates.SetNode(i,j, (prices.GetNode(i,j)-strategy.GetNode(i,j)*b.S(i,j))/(1+R));   
        }
    }
    prices.Display();
    strategy.Display();
    rates.Display();
    return prices.GetNode(0, 0);
};