#include <iostream>

// Part 2 Problem 5: Fibonacci

int fibo(int a)
{
    if (a < 0)
    {
        return 0;
    }
    else if (a == 0)
    {
        return 0;
    }
    else if (a == 1)
    {
        return 1;
    }

    return fibo(a-1) + fibo(a - 2);
}

int main()
{
    for (int a = 0; a < 11; a++)
    {
        std::cout << a << "th number of the Fibonacci sequence is: " << fibo(a) << std::endl;
    }
    return 0;
}