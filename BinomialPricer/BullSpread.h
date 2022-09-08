#include "EuropeanOption.h"

class BullSpread: public EuropeanOption
{
    private:
        double K1;
        double K2;
    public:
        void SetK(double k1, double k2);
        double GetK1() const {return K1;};
        double GetK2() const {return K2;};
        virtual double payoff(double z) const;
        ~BullSpread(){};
};