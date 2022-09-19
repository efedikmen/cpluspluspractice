#include "RandomGenerator.h"

static std::mt19937 mersenneTwister{ std::random_device{}() };
// algorithm that generates random 32-bit integers

int RandUniformInt(int n)
{
    if (n<0) 
    {
        std::cout << "Can only generate positive integers, please enter a positive n" << std::endl;
        exit(1);
    }
    return mersenneTwister()%n;
};