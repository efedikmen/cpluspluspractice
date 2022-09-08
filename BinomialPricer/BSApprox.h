#include "Call.h"
#include "Put.h"
#include "BinomialLattice.h"

double EUCallBSApprox(double S0, double K, double r, double T, double sigma, int N);
double EUPutBSApprox(double S0, double K, double r, double T, double sigma, int N);
double AmericanCallBSApprox(double S0, double K, double r, double T, double sigma, int N);
double AmericanPutBSApprox(double S0, double K, double r, double T, double sigma, int N);
double EUCallBSApprox(double S0, double K, double r, double T, double sigma, int N, 
        BinomialLattice<double> &prices, BinomialLattice<double> &strategy, BinomialLattice<double> &rates);