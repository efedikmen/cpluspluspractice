#pragma once
#include <iostream>

class MyVector
{
    private:
        int n;
        double* x;

    public:
        MyVector();
        MyVector(int size);
        MyVector(int size, double* nums);
        MyVector(const MyVector &v);
        ~MyVector();
        double max();
        double min();
        double sum();
        int get_size();
        void push_back(double a);
        MyVector extract(int i, int j);
        MyVector operator= (const MyVector &v);
        MyVector& operator+= (const MyVector &v);
        MyVector& operator*= (double k);
        double operator[] (int i) const;
        double& operator[] (int i);
        MyVector& operator- ();
};