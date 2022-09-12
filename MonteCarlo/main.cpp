#include <iostream>
#include "RandomGenerator.h"
#include "CallOption.h"
#include "PutOption.h"
#include "MonteCarloPricer.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"

int main()
{   
    CallOption c(0.0833, 100);
    BlackScholes bsm(100,0, 0.5, 0.05, 0);
    MonteCarloPricer m;
    std::cout << "Pricing call with analytic formula: " << c.price(bsm) << std::endl;
    std::cout << "Pricing call with Monte Carlo: " << m.price(bsm, c) << std::endl;
    PutOption p(0.0833, 100);
    std::cout << "Pricing put with analytic formula: " << p.price(bsm) << std::endl;
    std::cout << "Pricing put with Monte Carlo: " << m.price(bsm, p) << std::endl;
    DigitalCallOption dc(0.0833, 100);
    std::cout << "Pricing digital call with Monte Carlo: " << m.price(bsm, dc) << std::endl;
    DigitalPutOption dp(0.0833, 100);
    std::cout << "Pricing digital put with Monte Carlo: " << m.price(bsm, dp) << std::endl;
    return 0;
}