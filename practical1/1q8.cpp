#include <iostream>

/* 
    Part 2 Problem 3: 
    Write a recursive function to compute the sum of the numbers between 1 and n.
*/

int sums(int a)
{
    if (a > 1)
    {
        return a + sums(a - 1);
    }

    else if (a < 1)
    {
        return a + sums(a + 1);
    }
    
    return a;
    
}

int main()
{
    int a = 10;
    int b = -10;
    std::cout << "Sum from " << a << " to 1 is: " << sums(a) << std::endl;
    std::cout << "Sum from " << b << " to 1 is: " << sums(b) << std::endl;
    return 0;
}