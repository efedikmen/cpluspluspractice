#include <iostream>

/*
Write a function reverseDoubles which takes a pointer to a list of doubles and the length of the list and reverses it. 
*/
void swap(double *a, double *b)
{
    double temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverseDoubles(double* p, int l)
{
    for (int i = 0; i < l/2; i++)
    {
        swap(p, p + l - 1 - 2 * i);
        p++;
    }
}

int main()
{
    double test[5] = {2.34, 234.2, 23443.1, 32.34, 45.66};
    double *p = &test[0];
    int len = 5;
    reverseDoubles(p, len);
    for (double t:test)
    {
        std::cout << t << std::endl;
    }
    return 0;
}