#include "MyVector.h"
#include <iostream>

MyVector::MyVector()
{
    n = 0;
    x = NULL;
};
MyVector::MyVector(int size)
{
    n = size;
    x = new double[n];
};
MyVector::MyVector(int size, double *nums)
{
    n = size;
    x = new double[n];
    for (int i = 0; i < n; i++)
    {
        x[i]= *(nums+i);
    }
};
MyVector::MyVector(const MyVector &v)
{
    n = v.n;
    x = new double[n];
    for (int i = 0; i < n; i++)
    {
        x[i]= *(v.x+i);
    }
};
MyVector::~MyVector()
{
    delete[] x;
};
double MyVector::max()
{
    double max = *x;
    for (int i = 1; i < n; i++)
    {
        if (max < *(x+i)) max = *(x+i);
    }
    return max;
};
double MyVector::min()
{
    double min = *x;
    for (int i = 1; i < n; i++)
    {
        if (min > *(x+i)) min = *(x+i);
    }
    return min;
};
double MyVector::sum()
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum+= *(x+i);
    }
    return sum;
};
int MyVector::get_size()
{
    return n;
};
void MyVector::push_back(double a)
{
    *(x+n) = a;
};
MyVector MyVector::extract(int i, int j)
{
    int newn = j-i+1;
    double *newx = new double[j-i+1];
    for (int k=i; k<j; k++)
    {
        newx[i] = *(x+k);
    }
    MyVector vec(newn, newx);
    return vec;
};
MyVector MyVector::operator= (const MyVector &v)
{
    return v;
};
MyVector& MyVector::operator+= (const MyVector &v)
{
    if (n>=v.n) 
    {
        for (int i=0; i<v.n; i++)
        { *(x+i) += *(v.x+i); }
    }
    else
    {
        x = new double[v.n];
        for (int i=0; i<n; i++)
        { x[i] += *(v.x+i); }
        for (int i=n; i<v.n; i++)
        { x[i] = *(v.x+i); }
        n = v.n;
    }
    return *this;
};
MyVector& MyVector::operator*= (double k)
{
    for (int i=0; i<n; i++)
    {
        *(x+i) *= k;
    }
    return *this;
};
double MyVector::operator[] (int i) const
{
    return *(x+i);
};

double& MyVector::operator[] (int i)
{
    return *(x+i);
};
MyVector& MyVector::operator- ()
{
    for (int i=0; i<n; i++)
    {
        *(x+i) *= -1;
    }
    return *this;
};