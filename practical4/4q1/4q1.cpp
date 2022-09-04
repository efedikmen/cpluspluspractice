#include <iostream>
#include <vector>
#include "Polynomial.h"

/*
Write a class Polynomial
*/

int main()
{
    std::vector<double> v1{1.0, 2.0};
    std::vector<double> v2{1.0, 3.0, 4.0};   
    Polynomial a(v1);
    Polynomial b(v2);
    Polynomial c(b.add(a));
    std::cout << c.evaluate(2.0) << std::endl;
    c.show();
    return 0;
}