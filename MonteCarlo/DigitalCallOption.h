#include "PathIndependentOption.h"

class DigitalCallOption: public virtual PathIndependentOption
{
    public:
        DigitalCallOption(double T, double K) {SetMaturity(T);SetStrike(K);};
        ~DigitalCallOption(){};
        virtual double price(const BlackScholes &bs) const {return 0;};
        virtual double payoff(double z) const;
};