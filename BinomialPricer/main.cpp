#include <iostream>
#include "BSApprox.h"

int main()
{
    BinomialLattice<double> prices, rates, strategy;
    BinomialLattice<bool> stop;

    // first displaying the lattices

    //std::cout << EUCallBSApprox(100.,100., 0.05, 0.083, 0.5, 30, prices, rates, strategy) << std::endl;
    std::cout << EUPutBSApprox(100.,100., 0.05, 0.083, 0.5, 30, prices, rates, strategy) << std::endl;
    //std::cout << AmericanCallBSApprox(100.,100., 0.05, 0.083, 0.5, 100, prices, stop) << std::endl;
    //std::cout << AmericanPutBSApprox(100.,100., 0.05, 0.083, 0.5, 100, prices, stop) << std::endl;

    // without the lattices

    //std::cout << EUCallBSApprox(100.,100., 0.05, 0.083, 0.5, 30) << std::endl;
    std::cout << EUPutBSApprox(100.,100., 0.05, 0.083, 0.5, 30) << std::endl;
    //std::cout << AmericanCallBSApprox(100.,100., 0.05, 0.083, 0.5, 100) << std::endl;
    //std::cout << AmericanPutBSApprox(100.,100., 0.05, 0.083, 0.5, 150) << std::endl;
    return 0;
}