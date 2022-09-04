#pragma once
#include <vector>


class Polynomial
{
    private:
        std::vector<double> coefs;
    public:
        double evaluate(double x);
        Polynomial();
        Polynomial(std::vector<double> coef);
        Polynomial(const Polynomial &p);
        Polynomial(double c);
        ~Polynomial();
        Polynomial add(const Polynomial &p);
        void show();
};