#include <iostream>

/*
    Part 2 Problem 4:
    Write a function that takes two integer parameters a and b 
    and prints out all the numbers from a to b.
*/

void printer(int a, int b)
{
    if (a > b)
    {
        std::cout << b << std::endl;
        printer(a, ++b);
        return;
    }
    else if (b > a)
    {
        std::cout << a << std::endl;
        printer(++a, b);
        return;
    }

    std::cout << a << std::endl;
    return;
}

int main()
{
    int b = 0;
    int a = 10;
    printer(a, b);
    return 0;
}