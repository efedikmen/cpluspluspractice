#include "AmericanOption.h"
#include "EuropeanOption.h"

class Put: public EuropeanOption, public AmericanOption
{
    private:
        double K; //strike 
    public:
        void SetK(double k){K=k;};
        double GetK() const {return K;};
        ~Put(){};
        virtual double payoff(double z) const;
};