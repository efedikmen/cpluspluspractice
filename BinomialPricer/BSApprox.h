#include "Call.h"
#include "Put.h"
#include "BinomialLattice.h"

// these functions can be extended to other options where the payoffs are defined in the headers and their source codes

double EUCallBSApprox(double S0, double K, double r, double T, double sigma, int N);
double EUPutBSApprox(double S0, double K, double r, double T, double sigma, int N);
double AmericanCallBSApprox(double S0, double K, double r, double T, double sigma, int N);
double AmericanPutBSApprox(double S0, double K, double r, double T, double sigma, int N);
double EUCallBSApprox(double S0, double K, double r, double T, double sigma, int N, 
        BinomialLattice<double> &prices, BinomialLattice<double> &strategy, BinomialLattice<double> &rates);
double EUPutBSApprox(double S0, double K, double r, double T, double sigma, int N, 
        BinomialLattice<double> &prices, BinomialLattice<double> &strategy, BinomialLattice<double> &rates);
double AmericanCallBSApprox(double S0, double K, double r, double T, double sigma, int N, 
        BinomialLattice<double> &prices, BinomialLattice<bool> &stop);
double AmericanPutBSApprox(double S0, double K, double r, double T, double sigma, int N, 
        BinomialLattice<double> &prices, BinomialLattice<bool> &stop);