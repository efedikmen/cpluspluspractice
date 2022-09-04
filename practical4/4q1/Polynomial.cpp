#include <iostream>
#include <vector>
#include "Polynomial.h"
#include <cmath>

Polynomial::Polynomial()
{
    std::vector<double> vec(1);
    coefs = vec;
};

Polynomial::Polynomial(std::vector<double> coef)
{
    coefs = coef;
};
Polynomial::Polynomial(const Polynomial &p)
{
    coefs = p.coefs;
};
Polynomial::Polynomial(double c)
{
    std::vector<double> vec(1, c);
    coefs = vec;
};
Polynomial::~Polynomial()
{
    coefs.clear();
};

Polynomial Polynomial::add(const Polynomial &p)
{
    // add two vectors
    int n1 = coefs.size();
    int n2 = p.coefs.size();
    std::vector<double> vec;
    if (n1 > n2)
    {
        for (int i = 0; i < n2; i++)
        {
            vec.push_back(coefs[i] + p.coefs[i]);
        }
        for (int i = n2; i < n1; i++)
        {
            vec.push_back(coefs[i]);
        }
    }
    else if (n1 == n2)
    {
        for (int i = 0; i < n1; i++)
        {
            vec.push_back(coefs[i]);
        }
    }
    else
    {
        for (int i = 0; i < n1; i++)
        {
            vec.push_back(coefs[i] + p.coefs[i]);
        }
        for (int i = n1; i < n2; i++)
        {
            vec.push_back(coefs[i]);
        }
        
    }
    Polynomial newp(vec);
    return newp;
};

double Polynomial::evaluate(double x)
{
    double res = 0.0;
    for (int i=0; i < coefs.size(); i++)
    {
        res += coefs[i]*pow(x,i);
    }
    return res;
};

void Polynomial::show()
{
    std::cout << coefs[0] << " + ";
    double n = coefs.size();
    for (int i=1; i<n-1; i++)
    {
        std::cout << coefs[i] << "x^" << i << " + ";
    }
    if (n>1) std::cout << coefs[n-1] << "x^" << n-1;
};