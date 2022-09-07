#include "BinomialModel.h"
#include <iostream>
#include <cmath>
#include <vector>

void BinomialModel::SetR(double r)
{ R = r; };
void BinomialModel::SetD(double d)
{ D = d; }; 
void BinomialModel::SetU(double u)
{ U = u; };
void BinomialModel::SetStock(double s)
{ S0 = s; };
double BinomialModel::GetR() const
{ return R; };
double BinomialModel::GetD() const
{ return D; };
double BinomialModel::GetU() const
{ return U; }; 
double BinomialModel::GetStock() const
{ return S0; };
void BinomialModel::CheckData() const
{
    if (S0<=0)
    {
        std::cout << "Initial value is nonnegative. Should be positive" << std::endl;
        exit(1);
    };
    if (U<=-1)
    {
        std::cout << "Illegal value: up move return is less than -100%. Should be greater than -100%." << std::endl;
        exit(1);
    };
    if (R<=-1)
    {
        std::cout << "Illegal value: down move return is less than -100%. Should be greater than -100%." << std::endl;
        exit(1);
    };
    if (U<=D)
    {
        std::cout << "Illegal value: down move return is more than or equal to the up move. Should be less than the up move." << std::endl;
        exit(1);
    };
    if (R>=U)
    {
        std::cout << "The model admits arbitrage because risk free rate is higher than up move return." << std::endl;
        exit(1);
    };
    if (R<=D)
    {
        std::cout << "The model admits arbitrage because risk free rate is lower than down move return." << std::endl;
        exit(1);
    };
};
double BinomialModel::RiskNeutProb() const
{ return (R-D)/(U-D); };
double BinomialModel::S(int n, int i) const
{ 
    if (i > n || i < 0 || n < 0) exit(1);
    return S0*pow(1+U, i)*pow(1+D, n-i); 
};