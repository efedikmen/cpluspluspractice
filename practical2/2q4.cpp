#include <iostream>

/*
    Write a C++ program to accept five integer values from the keyboard. 
    The five values will be stored in an array using a pointer. 
    Then print the elements of the array on the screen.
*/


int main()
{
    int a[5];
    int *p = a;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> *(p+i);
    }
    for (int k: a)
    {
        std::cout << k << std::endl;
    }
    return 0;
}