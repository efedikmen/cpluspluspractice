#include "EuropeanOption.h"

class Butterfly: public EuropeanOption
{
    public:
        double K1;
        double K2;
    private:
        void SetK(double k1, double k2);
        double GetK1() const {return K1;};
        double GetK2() const {return K2;};
        virtual double payoff(double z) const;
        ~Butterfly(){};
};