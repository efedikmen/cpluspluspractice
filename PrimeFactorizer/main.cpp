#include <iostream>
#include <vector>

/*
Finds the prime factorization of the input positive integer.
Also has functions to calculate LCM and GCD of two positive integers.
*/

std::vector<int> PrimeFactors(int x)
{
    int upper = x/2;
    std::vector<int> factors;
    while (x%2==0 && x/2>0)
        {
            x/=2;
            factors.push_back(2);
        };
    for (int i=3; i<upper;i+=2)
    {
        while (x%i==0 && x/i>0)
        {
            x/=i;
            factors.push_back(i);
        }
    }
    int s = factors.size();
    for (int i=s-1; i>-1;i--)
    {
        std::cout << factors[i] << " * ";
    }
    std::cout << 1 << std::endl;
    return factors;
};

// recursively implements the Euclidean algorithm
int gcd(int a, int b)
{
    if (a>b)
    {
        if (a%b==0) return b;
        return gcd(a%b, b);
    }
    if (b>a)
    {
        if (b%a==0) return a;
        return gcd(b%a, a);
    }
    return a;
};

// uses the relationship between gcd and lcm
int lcm(int a, int b)
{
    return a*b/gcd(a,b);
};


int main()
{
    int a = 1948646812;
    int b = 89*7*32;
    std::vector<int> factors = PrimeFactors(a);
    std::cout << gcd(a,b) << std::endl;
    std::cout << lcm(a,b) << std::endl;
    return 0;
}