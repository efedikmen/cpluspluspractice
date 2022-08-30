#include <iostream>

/*
Write a function sum that which takes a pointer to a function int funct(int) and returns their sum
*/

int sum(int (*funct)(int), int n)
{
    int res = 0;
    for (int i = 0; i < n + 1; i++)
    {
        res += funct(i);
    }
    return res;
}

int cb(int a)
{
    return a * a * a;
}

int main()
{
    std::cout << sum(&cb, 3) << std::endl;
    return 0;
}