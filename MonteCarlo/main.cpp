#include <iostream>
#include "RandomGenerator.h"
#include "CallOption.h"
#include "PutOption.h"
#include "MonteCarloPricer.h"
#include "DigitalCallOption.h"
#include "DigitalPutOption.h"
#include "UpAndOutOption.h"
#include "ArithmeticAsianCall.h"
#include "ArithmeticAsianPut.h"

int main()
{   
    CallOption c(1, 100);
    BlackScholes bsm(100,0, 0.15, 0.05, 0);
    MonteCarloPricer m;
    std::cout << "Pricing call with analytic formula: " << c.price(bsm) << std::endl;
    std::cout << "Pricing call with Monte Carlo: " << m.price(bsm, c) << "| Delta:" << m.delta(bsm, c) << std::endl;
    PutOption p(1, 100);
    std::cout << "Pricing put with analytic formula: " << p.price(bsm) << std::endl;
    std::cout << "Pricing put with Monte Carlo: " << m.price(bsm, p) << "| Delta:" << m.delta(bsm, p)  << std::endl;
    DigitalCallOption dc(1, 100);
    std::cout << "Pricing digital call with Monte Carlo: " << m.price(bsm, dc) << std::endl;
    DigitalPutOption dp(1, 100);
    std::cout << "Pricing digital put with Monte Carlo: " << m.price(bsm, dp) << std::endl;
    UpAndOutOption uo(1, 100, 200);
    std::cout << "Pricing up and out option with Monte Carlo: " << m.price(bsm, uo) << "| Delta:" << m.delta(bsm, uo)  << std::endl;
    ArithmeticAsianCall aac(1, 100);
    std::cout << "Pricing Arithmetic Asian Call option with Monte Carlo: " << m.price(bsm, aac) << "| Delta:" << m.delta(bsm, aac) << std::endl;
    ArithmeticAsianPut aap(1, 100);
    std::cout << "Pricing Arithmetic Asian Put option with Monte Carlo: " << m.price(bsm, aap) << "| Delta:" << m.delta(bsm, aap) << std::endl;
    return 0;
}