#include <iostream>

int main()
{
    // Problem 2: Cast char values to int values to find codes used for the characters 'a', 'z', 'A', 'Z', '0', and '9'.

    std::cout << "Problem 1 " << std::endl;

    char a[6] = {'a', 'z', 'A', 'Z', '0', '9'};

    for (char i:a)
    {
         std::cout << i << ": " << int(i) << std::endl;
    }
    return 0;
}