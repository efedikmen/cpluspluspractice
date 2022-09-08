#include <iostream>
#include "BSApprox.h"

int main()
{
    BinomialLattice<double> prices, rates, strategy;
    std::cout << EUCallBSApprox(100.,100., 0.05, 0.083, 0.5, 30) << std::endl;
    //std::cout << EUPutBSApprox(100.,100., 0.05, 0.083, 0.5, 150) << std::endl;
    //std::cout << AmericanCallBSApprox(100.,100., 0.05, 0.083, 0.5, 150) << std::endl;
    //std::cout << AmericanPutBSApprox(100.,100., 0.05, 0.083, 0.5, 150) << std::endl;
    std::cout << EUCallBSApprox(100.,100., 0.05, 0.083, 0.5, 30, prices, rates, strategy) << std::endl;
    return 0;
}