#include <iostream>
#include <cmath>

/*  
    Part 2 Problem 2:
    Write a program which will raise any number x to a positive power n using for loop.
    Write a second version using the cmath library.
*/

template <class T> 
T power(T a, int b)
{
    T res = a;
    while (b > 1)
    {
        res *= a;
        b--;
    }
    return res;
}

int main()
{

    double a = 3.123313;

    std::cout << power(a, 5) << std::endl;
    std::cout << pow(a, 5) << std::endl;

    return 0;
}