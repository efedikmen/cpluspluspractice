#include <iostream>
#include <typeinfo>

/*
Write a function sumDoubles which takes a pointer to a list of doubles
and the length of the list and returns the total.
*/

double sumDoubles(double *p, int len)
{
    double res = 0.0;
    for (int i = 0; i < len; i++)
    {
        res += *(p + i);
    }
    return res;
}

int main()
{
    double test[5] = {2.34, 234.2, 23443.1, 32.34, 45.66};
    double *p = &test[0];
    int len = 5;
    std::cout << sumDoubles(p, len) << std::endl;
    return 0;
}