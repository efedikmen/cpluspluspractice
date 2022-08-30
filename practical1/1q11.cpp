#include <iostream> 
#include <complex>
#include <cmath>

/*  
    Part 2 Problem 6:
    Write a function which prints the square roots 
    of the equation ax^2 + bx + c = 0
*/

void roots(double a, double b, double c)
{
    double disc = b * b - 4.0 * a * c;
    if (disc > 0)
    {
        std::cout << (-b - sqrt(disc)) / (2 * a) << std::endl;
        std::cout << (-b + sqrt(disc)) / (2 * a) << std::endl;
        return;
    }
    if (disc == 0)
    {
        std::cout << -b / (2 * a) << std::endl;
        return;
    }
    std::complex<double> neg(-b / (2 * a), -sqrt(-disc) / (2 * a));
    std::complex<double> pos(-b / (2 * a), sqrt(-disc) / (2 * a));
    std::cout << neg << std::endl;
    std::cout << pos << std::endl;
    return;
}

int main()
{
    double a = 1.0;
    double b = 0.0;
    double c = 1.0;
    roots(a, b, c);
    return 0;
}