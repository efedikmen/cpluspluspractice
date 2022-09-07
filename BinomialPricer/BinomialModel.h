#pragma once
#include <cmath>
#include <iostream>

class BinomialModel
{
    private:
        double S0;
        double U;
        double D;
        double R;
    public:
        void SetR(double r);
        void SetD(double d); 
        void SetU(double u);
        void SetStock(double s);
        double GetR() const;
        double GetD() const;
        double GetU() const; 
        double GetStock() const;
        void CheckData() const;
        double RiskNeutProb() const;
        double S(int n, int i) const;
        virtual ~BinomialModel(){};
};