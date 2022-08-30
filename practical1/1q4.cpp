#include <iostream>
#include <cmath>
#include <string>

/*
 Problem 4: Write a program where the user enters a decimal number
 and the code prints out the nearest integer. You should use cast 
 as part of your solution. Write a second version using the cmath library.
 */

int main()
{
    std::string entry;
    std::cin >> entry; 

    float num = std::stof(entry);
    std::cout << round(num) << std::endl;
    
}