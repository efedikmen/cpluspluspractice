#include <iostream>

int main()
{

    // Problem 1: Print five different datatypes with how many bytes each uses

    std::cout << "Problem 1 " << std::endl;
    std::cout << "Short int:" << sizeof(short int)<< std::endl;
    std::cout << "Int: " << sizeof(int) << std::endl;
    std::cout << "Double: " << sizeof(double) << std::endl;
    std::cout << "Float: " << sizeof(float) << std::endl;
    std::cout << "Long long: " << sizeof(long long) << std::endl;

    
    return 0;
}
