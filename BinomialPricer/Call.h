#include "AmericanOption.h"
#include "EuropeanOption.h"

class Call: public EuropeanOption, public AmericanOption
{
    private:
        double K; //strike 
    public:
        void SetK(double k){K=k;};
        double GetK() const {return K;};
        ~Call(){};
        virtual double payoff(double z) const;
};