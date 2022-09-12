#include "ArithmeticAsianPut.h"

double ArithmeticAsianPut::payoff(std::vector<double> z) const
{
    double avg = 0;
    for (double a:z) {avg+=a;};
    avg/=z.size();
    if (GetStrike()-avg>0) return GetStrike()-avg;
    return 0;
};