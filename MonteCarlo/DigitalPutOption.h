#include "PathIndependentOption.h"

class DigitalPutOption: public virtual PathIndependentOption
{
    public:
        DigitalPutOption(double T, double K) {SetMaturity(T);SetStrike(K);};
        ~DigitalPutOption(){};
        virtual double price(const BlackScholes &bs) const {return 0;};
        virtual double payoff(double z) const;
};