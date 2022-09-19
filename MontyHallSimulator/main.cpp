#include "Experiment.h"
/*
For details on the Monty Hall Problem:
https://en.wikipedia.org/wiki/Monty_Hall_problem
Simulates the probability of having a car behind the unchosen door
after the other unchosen door is shown to be empty.
*/

int main()
{
    int N = 6e7; // number of simulations
    int trials[2] = {0};
    for (int i = 0; i<N; i++)
    {
        Experiment a;
        trials[a.Run()]++;
    }
    std::cout << "Failure: " << trials[0] << std::endl;
    std::cout << "Success: " << trials[1] << std::endl;
    std::cout << "Success ratio: " << (double)trials[1]/(double)N *100 << '%' << std::endl;
    return 0;
}