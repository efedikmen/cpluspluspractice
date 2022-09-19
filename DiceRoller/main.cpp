#include "RandomGenerator.h"

/*
Simulates k many dice rolls with n sides each 
as many times as the user wants.
Press the y key and then hit enter to reroll.
*/

int main()
{
    char again;
    int n = 6, k = 2; // chose parameters accordingly for backgammon dices
    do
    {
        randuniformPrint(n, k);
        std::cout << "Want to roll again?(y/n)\n";
        std::cin >> again;
    }
    while (again=='y');
    
    // randomness check below, run it if you want to see a large sample
    /*
    int distribution[6] = {0}; 
    int N = 10000000;
    for (int i = 0; i<N; i++)
    {
        std::vector current = randuniform(n, k);
        for (int j = 0; j<k; j++)
        {
            distribution[current[j]-1]++;
        }
    }
    for (int i = 0; i<n; i++)
    {
        std::cout << "Rolled " << i+1 << ": " << distribution[i] << "out of 20000000 dice rolls" << std::endl;
    }
    */
    return 0;
}