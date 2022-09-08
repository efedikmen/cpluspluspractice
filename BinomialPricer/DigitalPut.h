#include "EuropeanOption.h"

class DigitalPut: public EuropeanOption
{
    private:
        double K;
    public:
        void SetK(double k) {K=k;};
        double GetK() const {return K;};
        virtual double payoff(double z) const;
        ~DigitalPut(){};
};