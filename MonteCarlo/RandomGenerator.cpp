#include "RandomGenerator.h"
#include "NormalDistribution.h"
#include <random>


// algorithm to generate uniformly distributed random numbers
static std::mt19937 mersenneTwister;

std::vector<double> randuniform(int n)
{
    std::vector<double> a(n);
    for (int i=0; i<n; i++)
    {
        a[i] = (mersenneTwister()+0.5)/(mersenneTwister.max()+1.0);
    }
    return a;
};

std::vector<double> randn(int n)
{
    std::vector<double> a = randuniform(n);
    std::vector<double> b;
    for (double x: a)
    {
        b.push_back(norminv(x));
    }
    return b;
};

std::vector<double> boxmuller(int n)
{
    int a;
    (n%2==0) ? (a=n/2) : (a=(n+1)/2);
    a*=2;
    std::vector<double> unif = randuniform(a);
    std::vector<double> normal;
    for (int i=0;i<a;i+=2)
    {
        normal.push_back(sqrt(-2*log(unif[i]))*cos(2*M_PI*unif[i+1]));
        normal.push_back(sqrt(-2*log(unif[i+1]))*sin(2*M_PI*unif[i]));
    }
    if (n<normal.size()) normal.pop_back();
    return normal;
}; 

// sample standard deviation calculator

double stddev(std::vector<double> a)
{
    double avg = 0;
    for (double x:a)
    {avg+=x;}
    avg/= a.size();
    double sd = 0;
    for (double x:a)
    {
        sd += pow(x-avg, 2);
    }
    return sqrt(sd/(a.size()-1));
};