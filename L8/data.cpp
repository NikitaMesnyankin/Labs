#include "data.h"

double calcFirstFunc(const double x)
{
    return sqrt(log(7.9) + exp(-1.0 * x)  - (pow(x, 2) / 11.0)) - x;
}

double calcFF(const double x)
{
    return sqrt(log(7.9) + exp(-1.0 * x)  - (pow(x, 2) / 11.0));
}

double calcSecondFunc(const double x)
{
    return (exp(-1.0 * x) - sqrt(exp(x)) + 3.7) / 3.0 - x;
}

double calcSF(const double x)
{
    return (exp(-1.0 * x) - sqrt(exp(x)) + 3.7) / 3.0;
}

int calcPrecision(const double precision)
{
    int prec = 0;
    double precis = precision;
    while (precis < 1)
    {
        prec++;
        precis *= 10;
    }
    return prec;
}

int solveDividing(const double a, const double b, const double precision, double (*func)(double)) {
    double x, left = a, right = b;
    unsigned int amount = 0;

    while ((right - left) >= precision)
    {
        x = (left + right) / 2;
        amount++;
        if (func(x) * func(b) < 0)
        {
            left = x;
        } else {
            right = x;
        }
    }

    std::cout << "Solution: " << std::fixed <<  std::setprecision(calcPrecision(precision)) << x
            << " Iterations: " << amount << std::endl;
    return 0;
}

int solveIterations(const double a, const double b, const double precision, double (*func)(double))
{
    int amount = 0;
    double x0 = (a + b) / 2, x;

    while ((fabs(a - x0) >= precision) && (fabs(b - x0) >= precision))
    {
        x = func(x0);
        amount++;
        if (fabs(x - x0) < precision)
        {
            break;
        } else {
            x0 = x;
        }
    }

    std::cout << "Solution: " << std::fixed <<  std::setprecision(calcPrecision(precision)) << x
            << " Iterations: " << amount << std::endl;
    return 0;
}
