#include <iostream>
#include <vector>
#include <cmath>

// dealing with the vector STL

//function to compute the mean of a vector of doubles 
double mean(std::vector<double> v)
{
    int len = v.size();
    double res = 0.0;
    for (double a:v)
    {
        res += a;
    }
    return res/len;
};

//function to compute the sample standard deviation of the elements in a vector
double stddev(std::vector<double> v)
{
    double avg = mean(v);
    double res = 0.0;
    for (double a:v)
    {
        res += pow(a-avg, 2);
    }
    return sqrt(res/(v.size()-1));
};

//finds the max in a vector
double max(std::vector<double> v)
{
    double top = v[0];
    for (double a:v)
    {
        if (top < a) top = a;
    }
    return top;
};

//finds the min in a vector
double min(std::vector<double> v)
{
    double top = v[0];
    for (double a:v)
    {
        if (top > a) top = a;
    }
    return top;
};

//overloads the output operator to print the elements of a vector
std::ostream & operator<< (std::ostream & out, std::vector<double> v)
{
    for (double a:v)
    {
        out << a << ' ';
    }
    return out;
};
int main()
{
    std::vector<double> v = {1.0,3.0,123.1,4.324,-0.43};
    std::cout << "Vector: " << v << std::endl;
    std::cout << "Mean:" << mean(v) << std::endl;
    std::cout << "Sample Standard Deviation" << stddev(v) << std::endl;
    std::cout << "Max" << max(v) << std::endl;
    std::cout << "Min" << min(v) << std::endl;
    return 0;
}