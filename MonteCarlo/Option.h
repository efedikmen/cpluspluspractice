#pragma once

class Option
{
    private:
        double T; // maturity time
        double K; // strike
    public:
        virtual ~Option(){};
        double GetMaturity() const {return T;};
        double GetStrike() const {return K;};
        void SetMaturity(double time) {T=time;}
        void SetStrike(double strike) {K=strike;}  
};