#pragma once
#include <vector>

class BlackScholes
{
    private:
        double S0;
        double drift;
        double vol;
        double rate;
        double t;
        std::vector<double> GeneratePricePath(double toDate, int Nsteps, double mu) const; // for simulating purposes
    public:
        double GetStock() const {return S0;};
        double GetDrift() const {return drift;};
        double GetVol() const {return vol;};
        double GetRate() const {return rate;};
        double GetTime() const {return t;};
        BlackScholes(double s, double mu, double sigma, double r, double time);
        ~BlackScholes(){};
        std::vector<double> GeneratePricePath(double toDate, int Nsteps) const;
        std::vector<double> GenerateRiskNeutralPricePath(double toDate, int Nsteps) const;
};