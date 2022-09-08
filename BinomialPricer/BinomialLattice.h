#pragma once
#include <vector>
#include <iostream>

template<typename Type> class BinomialLattice
{
    private:
        int N; // number of time steps in the lattice
        std::vector<std::vector<Type>> lattice;
    public:
        void SetN(int n)
        {
            N = n;
            lattice.resize(N+1);
            for (int i=0; i<= N; i++)
            {lattice[i].resize(i+1);}
        };
        void SetNode(int n, int i, Type val)
        {
            {lattice[n][i] = val;};
        };
        double GetNode(int n, int i) const
        {
            return lattice[n][i];
        };
        void Display() const
        {
            for (int n = N; n>=0; n--)
            {
                for (int i = n; i>=0; i--)
                {
                    std::cout << GetNode(n, i) << " ";
                }
                std::cout << std::endl;
            }
        };
        ~BinomialLattice(){};
};