#include <iostream>
#include <cmath>

/*
    Part 2 Problem 7:
    Write a function called normcdf to evaluate the cumulative normal function.
*/

double normcdf(double x)
{
    if (x >= 0)
    {
        double k = 1 / (1 + 0.2316419 * x);
        double coefs[5] = {1.330274429, -1.821255978, 1.781477937, -0.356563782, 0.319381530};
        double res = 0.0;
        for (double a:coefs) 
        {
            res *= k;
            res += a;
        }
        double pdf = 1 - sqrt(1 / (2 * M_PI)) * k * exp(- x * x / 2) * res;
        return pdf;
    }
    return 1.0 - normcdf(-x);
}

int main()
{
    double tests[] = {1.959964, -1.959964, 1.645, 0};
    for (double a: tests)
    {
        std::cout << "Given x=" << a << ": Phi(x)=" << normcdf(a) << std::endl;
    }
    return 0;
}