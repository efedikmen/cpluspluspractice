#include "NormalDistribution.h"

double normcdf(double x)
{
    if (x >= 0)
    {
        double k = 1 / (1 + 0.2316419 * x);
        double coefs[5] = {1.330274429, -1.821255978, 1.781477937, -0.356563782, 0.319381530};
        double res = 0.0;
        for (double a:coefs) 
        {
            res *= k;
            res += a;
        }
        double pdf = 1 - sqrt(1 / (2 * M_PI)) * k * exp(- x * x / 2) * res;
        return pdf;
    }
    return 1.0 - normcdf(-x);
};

double norminv(double x)
{
    if (x < 0 || x > 1)
    {
        return 0;
    }
    double y = x - 0.5;
    if (abs(y) < 0.42)
    {
        double r = y * y;
        double as[4] = {-25.44106049637, 41.39119773534, -18.61500062529, 2.50662823884};
        double res1 = 0;
        for (double a:as)
        {
            res1 *= r;
            res1 += a;
        }
        double bs[5] = {3.13082909833, -21.06224101826, 23.08336743743, -8.47351093090, 1.0};
        double res2 = 0;
        for (double b:bs)
        {
            res2 *= r;
            res2 += b;
        }
        return y * res1 / res2;
    }
    double r;
    (y < 0) ? (r = x) : (r = 1 - x);

    double s = log(-log(r));
    double cs[] = {0.0000003960315187, 0.0000002888167364, 0.0000321767881768, 0.0003951896511919, 
                   0.0038405729373609, 0.0276438810333863, 0.1607979714918209, 0.9761690190917186, 0.3374754822726147};
    double t = 0;
    for (double c:cs)
    {
        t *= s;
        t += c;
    }

    return (x > 0.5) ? t : -t;

};