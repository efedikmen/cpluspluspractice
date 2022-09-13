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
    CallOption c(2, 109);
    BlackScholes bsm(107,0, 0.15, 0.05, 0);
    MonteCarloPricer m;
    std::cout << "Pricing call with analytic formula: " << c.price(bsm) << std::endl;
    std::cout << "Pricing call with Monte Carlo: " << m.price(bsm, c) << "| Delta:" << m.delta(bsm, c) << std::endl;
    PutOption p(2, 109);
    std::cout << "Pricing put with analytic formula: " << p.price(bsm) << std::endl;
    std::cout << "Pricing put with Monte Carlo: " << m.price(bsm, p) << "| Delta:" << m.delta(bsm, p)  << std::endl;
    DigitalCallOption dc(2, 109);
    std::cout << "Pricing digital call with Monte Carlo: " << m.price(bsm, dc) << "| Delta:" << m.delta(bsm, dc) << std::endl;
    DigitalPutOption dp(2, 109);
    std::cout << "Pricing digital put with Monte Carlo: " << m.price(bsm, dp) << "| Delta:" << m.delta(bsm, dp) << std::endl;
    UpAndOutOption uo(2, 109, 200);
    std::cout << "Pricing up and out option with Monte Carlo: " << m.price(bsm, uo) << "| Delta:" << m.delta(bsm, uo)  << std::endl;
    ArithmeticAsianCall aac(2, 109);
    std::cout << "Pricing Arithmetic Asian Call option with Monte Carlo: " << m.price(bsm, aac) << "| Delta:" << m.delta(bsm, aac) << std::endl;
    ArithmeticAsianPut aap(2, 109);
    std::cout << "Pricing Arithmetic Asian Put option with Monte Carlo: " << m.price(bsm, aap) << "| Delta:" << m.delta(bsm, aap) << std::endl;
    return 0;
}