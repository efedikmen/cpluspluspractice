#include "ArithmeticAsianCall.h"

double ArithmeticAsianCall::payoff(std::vector<double> z) const
{
    double avg = 0;
    for (double a:z) {avg+=a;};
    avg/=z.size();
    if (avg-GetStrike()>0) return avg-GetStrike();
    return 0;
};