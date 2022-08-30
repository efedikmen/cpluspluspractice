#include <iostream>

/*
    Part 2 Problem 1: write three functions to compute n!,
    a for loop a while loop and a do-while loop.
*/

int fac_f(int a)
{
    int res = 1;
    for (int i = 1; i < a + 1; i++)
    {
        res *= i;
    }
    return res;
}

int fac_w(int a)
{
    int res = 1;
    while (a > 0)
    {
        res *= a;
        a--;
    }
    return res;
}

int fac_dw(int a)
{
    int res = 1;
    if (a > 0) 
    {
        do
        {
            res *= a;
            a--;
        }
        while (a > 0);
    }
    return res;
}
int main()
{
    int a = 23;
    std::cout << "Using a for loop " << a << "!= " << fac_f(a) << std::endl;
    std::cout << "Using a while loop " << a << "!= " << fac_w(a) << std::endl;
    std::cout << "Using a do while loop " << a << "!= " << fac_dw(a) << std::endl;

}