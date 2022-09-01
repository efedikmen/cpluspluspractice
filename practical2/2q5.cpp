#include <iostream>

/*
    Write a function swap which interchanges two real numbers.
*/

// Version 1
void swap1(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Version 2
void swap2(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1;
    int b = 2;
    swap1(&a, &b);
    std::cout << "After swap1, a:" << a << " and b:" << b << std::endl;
    swap2(a, b);
    std::cout << "After swap2, a:" << a << " and b:" << b << std::endl;
    return 0;
}