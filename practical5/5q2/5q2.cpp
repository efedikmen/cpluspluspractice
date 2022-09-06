#include <iostream>
#include <cmath>
#include "Functions.h"

// basic numerical integration class

double integral(RealFunction & f, double a, double b, int n)
{
    double res = 0.0;
    double h = (a + b) / n;
    double xi = 0.0;
    for (int i = 0; i <= n; i++)
    {
        xi = a + h * i;
        (i == 0 || i == n) ? (res += f.evaluate(xi)) : (res += 2.0 * f.evaluate(xi));
    }
    return res * h / 2;  
};

int main()
{
    Sin s;
    std::cout << integral(s, 0.0, 3.1415926, 1000);
};