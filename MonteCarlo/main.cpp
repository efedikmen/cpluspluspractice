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
    PriceAndSE c1 = m.priceWithSE(bsm, c);
    std::cout << "Pricing call with Monte Carlo: " << c1.GetPrice() << "(Std Error: " << c1.GetSE() << ')' << "| Delta:" << m.delta(bsm, c) << std::endl;
    PutOption p(1, 100);
    std::cout << "Pricing put with analytic formula: " << p.price(bsm) << std::endl;
    PriceAndSE p1 = m.priceWithSE(bsm, p);
    std::cout << "Pricing put with Monte Carlo: " << p1.GetPrice() << "(Std Error: " << p1.GetSE() << ')'  << "| Delta:" << m.delta(bsm, p)  << std::endl;
    DigitalCallOption dc(1, 100);
    PriceAndSE dc1 = m.priceWithSE(bsm, dc);
    std::cout << "Pricing digital call with Monte Carlo: " << dc1.GetPrice() << "(Std Error: " << dc1.GetSE() << ')' << std::endl;
    DigitalPutOption dp(1, 100);
    PriceAndSE dp1 = m.priceWithSE(bsm, dp);
    std::cout << "Pricing digital put with Monte Carlo: " << dp1.GetPrice() << "(Std Error: " << dp1.GetSE() << ')' << std::endl;
    UpAndOutOption uo(1, 100, 200);
    PriceAndSE uo1 = m.priceWithSE(bsm, dp);
    std::cout << "Pricing up and out option with Monte Carlo: " << uo1.GetPrice() << "(Std Error: " << uo1.GetSE() << ')' << "| Delta:" << m.delta(bsm, uo)  << std::endl;
    ArithmeticAsianCall aac(1, 100);
    PriceAndSE aac1 = m.priceWithSE(bsm, aac);
    std::cout << "Pricing Arithmetic Asian Call option with Monte Carlo: " << aac1.GetPrice() << "(Std Error: " << aac1.GetSE() << ')' << "| Delta:" << m.delta(bsm, aac) << std::endl;
    ArithmeticAsianPut aap(1, 100);
    PriceAndSE aap1 = m.priceWithSE(bsm, aap);
    std::cout << "Pricing Arithmetic Asian Put option with Monte Carlo: " << aap1.GetPrice() << "(Std Error: " << aap1.GetSE() << ')'  << "| Delta:" << m.delta(bsm, aap) << std::endl;
    return 0;
}