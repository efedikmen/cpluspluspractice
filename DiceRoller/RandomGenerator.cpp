#include "RandomGenerator.h"

static std::mt19937 mersenneTwister{ std::random_device{}() };
// algorithm that generates random 32-bit integers

std::vector<int> randuniform(int n, int k)
{
    std::vector<int> dice(k);
    for (int i=0; i<k; i++)
    {
        dice[i] = mersenneTwister()%n+1;
    }
    return dice;
};

std::vector<int> randuniformPrint(int n, int k)
{
    std::vector<int> dice(k);
    for (int i=0; i<k; i++)
    {
        dice[i] = mersenneTwister()%n+1;
        std::cout << dice[i] << " ";
    }
    std::cout << std::endl;
    return dice;
};