#include <iostream>
#include <cmath>
#include <functional>

// Trapezoidal approximation of definite integral

class DefInt
{
    private:
        double a;
        double b;
        std::function<double(double)> f;

    public:
        DefInt(double lower, double upper, std::function<double(double)> func)
        {
            a = lower;
            b = upper;
            f = func;
        };
        ~DefInt()
        {};
        double ByTrapezoid(int n)
        {
            double res = 0.0;
            double h = (a + b) / n;
            double xi = 0.0;
            for (int i = 0; i <= n; i++)
            {
                xi = a + h * i;
                (i == 0 || i == n) ? (res += f(xi)) : (res += 2.0 * f(xi));
            }
            return res * h / 2;  
        };
        // based on cubic interpolation composite rule
        double BySimpson(int n)
        {
            double h = (b - a) / n;
            double xi;
            double res = f(a) + f(b);
            for (int i = 1; i < n; i++)
            {
                xi = a + i * h;
                (i%3 == 0) ? (res += 2 * f(xi)) : (res += 3 * f(xi));
            }
            return 3 * h / 8 * res;
        }
};

double f(double a)
{
    return log(a + 1) + a * a;
}

int main()
{
    double a = 0.0;
    double b = 15.0;
    DefInt myint(a,b,f);
    const int N = 10000000;
    std::cout << myint.ByTrapezoid(N) << std::endl;
    std::cout << myint.BySimpson(N) << std::endl;
    return 0;
}