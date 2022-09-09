#include "Call.h"
#include "Put.h"
#include <iostream>
#include <cmath>

// Approximating the price of a European call 
double EUCallBSApprox(double S0, double K, double r, double T, double sigma, int N)
{
    double h = T/N;
    double U = exp(r*h+sigma*sqrt(h))-1;
    double D = exp(r*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    BinomialModel b;
    b.SetD(D);
    b.SetR(R);
    b.SetU(U);
    b.SetStock(S0);
    Call c;
    c.SetK(K);
    c.SetN(N);
    return c.PriceByCRR(b);
};

// Approximating the price of a European call 
double EUPutBSApprox(double S0, double K, double r, double T, double sigma, int N)
{
    double h = T/N;
    double U = exp(r*h+sigma*sqrt(h))-1;
    double D = exp(r*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    BinomialModel b;
    b.SetD(D);
    b.SetR(R);
    b.SetU(U);
    b.SetStock(S0);
    Put p;
    p.SetK(K);
    p.SetN(N);
    return p.PriceByCRR(b);//S0*pow(1+U, 44)*pow(1+D, 56)*1.05/0.97;
};

// approximating the price of an American Call
double AmericanCallBSApprox(double S0, double K, double r, double T, double sigma, int N)
{
    double h = T/N;
    double U = exp(r*h+sigma*sqrt(h))-1;
    double D = exp(r*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    BinomialModel b;
    b.SetD(D);
    b.SetR(R);
    b.SetU(U);
    b.SetStock(S0);
    Call c;
    c.SetK(K);
    c.SetN(N);
    return c.PriceBySnell(b);
};

// approximating the price of an American Put
double AmericanPutBSApprox(double S0, double K, double r, double T, double sigma, int N)
{
    double h = T/N;
    double U = exp(r*h+sigma*sqrt(h))-1;
    double D = exp(r*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    BinomialModel b;
    b.SetD(D);
    b.SetR(R);
    b.SetU(U);
    b.SetStock(S0);
    Put p;
    p.SetK(K);
    p.SetN(N);
    return p.PriceBySnell(b);
};

// approximating the price of a European Call using option price and stopping time lattices
double EUCallBSApprox(double S0, double K, double r, double T, double sigma, int N, 
        BinomialLattice<double> &prices, BinomialLattice<double> &strategy, BinomialLattice<double> &rates)
{
    double h = T/N;
    double U = exp(r*h+sigma*sqrt(h))-1;
    double D = exp(r*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    BinomialModel b;
    b.SetD(D);
    b.SetR(R);
    b.SetU(U);
    b.SetStock(S0);
    Call c;
    c.SetK(K);
    c.SetN(N);
    return c.PriceByCRR(b, prices, strategy, rates);
};

// approximating the price of a European Put using option price and stopping time lattices
double EUPutBSApprox(double S0, double K, double r, double T, double sigma, int N, 
        BinomialLattice<double> &prices, BinomialLattice<double> &strategy, BinomialLattice<double> &rates)
{
    double h = T/N;
    double U = exp(r*h+sigma*sqrt(h))-1;
    double D = exp(r*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    BinomialModel b;
    b.SetD(D);
    b.SetR(R);
    b.SetU(U);
    b.SetStock(S0);
    Call p;
    p.SetK(K);
    p.SetN(N);
    return p.PriceByCRR(b, prices, strategy, rates);
};

// approximating the price of an American Call using option price and stopping time lattices
double AmericanCallBSApprox(double S0, double K, double r, double T, double sigma, int N,
    BinomialLattice<double> &prices, BinomialLattice<bool> &stop)
{
    double h = T/N;
    double U = exp(r*h+sigma*sqrt(h))-1;
    double D = exp(r*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    BinomialModel b;
    b.SetD(D);
    b.SetR(R);
    b.SetU(U);
    b.SetStock(S0);
    Call c;
    c.SetK(K);
    c.SetN(N);
    return c.PriceBySnell(b, prices, stop);
};

// approximating the price of an American Put using option price and stopping time lattices
double AmericanPutBSApprox(double S0, double K, double r, double T, double sigma, int N,
    BinomialLattice<double> &prices, BinomialLattice<bool> &stop)
{
    double h = T/N;
    double U = exp(r*h+sigma*sqrt(h))-1;
    double D = exp(r*h-sigma*sqrt(h))-1;
    double R = exp(r*h)-1;
    BinomialModel b;
    b.SetD(D);
    b.SetR(R);
    b.SetU(U);
    b.SetStock(S0);
    Put p;
    p.SetK(K);
    p.SetN(N);
    return p.PriceBySnell(b, prices, stop);
};