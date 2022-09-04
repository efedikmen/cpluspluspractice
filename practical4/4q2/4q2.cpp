#include <iostream>
#include "MyVector.h"

/*
writing a vector class
*/

// summing two vectors using the overloaded += operator
MyVector sum2vecs(MyVector a, MyVector b)
{
    int len;
    (a.get_size() > b.get_size()) ? (len = a.get_size()) :(len = b.get_size());
    MyVector vec(len);
    vec+=a;
    vec+=b;
    return vec;
};

MyVector prod2vecs(MyVector a, MyVector b)
{
    int len = a.get_size();
    if (b.get_size() != len)
    {
        exit(1);
    }
    MyVector vec(len);
    for (int i=0; i<len; i++)
    {
        vec[i] = a[i] * b[i];
    }
    return vec;
}
// overloading the << operator as a non member
std::ostream& operator<< (std::ostream &out, MyVector v)
{
    int len = v.get_size();
    for (int i=0; i<len; i++)
    { out << v[i] << ' ';}
    return out;
};

bool operator== (MyVector &v1, MyVector &v2)
{
    int len = v1.get_size();
    if (v2.get_size() != len)
    {return false;}
    for (int i=0; i<len; i++)
    {
        if (v1[i] != v2[i]) return false;
    }
    return true;
};

bool operator!= (MyVector &v1, MyVector &v2)
{
    return !(v1 == v2);
};

double dotprod(MyVector &v1, MyVector &v2)
{
    int len = v1.get_size();
    if (v2.get_size() != len)
    { exit(1); }
    double res;
    for (int i=0; i<len; i++)
    { res += v1[i]*v2[i];}
    return res;
}

int main()
{
    int n1 = 4, n2 = 6;
    double x1[4] = {1.0, 2.0, 3.0, 4.0};
    double x2[6] = {1.0, 2.0, 3.0, 4.0, 5.0, 31.0};
    MyVector a(n1,x1);
    MyVector b(n2,x2);
    MyVector c = sum2vecs(a,b);
    std::cout << a.get_size() << std::endl;
    std::cout << prod2vecs(b,c) << std::endl;
    std::cout << dotprod(b,c) << std::endl;
    return 0;
}