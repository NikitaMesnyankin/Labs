#include "data.h"

int main() {
    double a, b, n;
    std::cout << "Enter range and N..." << std::endl;
    std::cin >> a >> b >> n;

    if ((n < 1) || (n > 10))
    {
        std::cout << "Wrong N! Press any key..." << std::endl;
        system("pause");
        return 1;
    }

    if ((a >= b) || (a < 0) || (b > 2))
    {
        std::cout << "Wrong a and b! Press any key..." << std::endl;
        system("pause");
        return 1;
    }

    for (auto i = 0; i < n; i++)
    {
        double precision = 1.0 / (pow(10, i + 1));

        if ((precision > 0.1) || (precision < 0))
        {
            std::cout << "Wrong precision! Press any key..." << std::endl;
            system("pause");
            return 1;
        }

        std::cout << "PRECISION: " << std::fixed << std::setprecision(i + 1) << precision << std::endl;

        if (calcFirstFunc(a) * calcFirstFunc(b) >= 0)
        {
            std::cout << "No solution on [a..b] (1st function)! Press any key..." << std::endl;
            system("pause");
        } else {
            std::cout << "First function (dividing): " << "    | ";
            solveDividing(a, b, precision, calcFirstFunc);
            std::cout << "First function (iterations): " << "  | ";
            solveIterations(a, b, precision, calcFF);
        }

        if (calcSecondFunc(a) * calcSecondFunc(b) >= 0)
        {
            std::cout << "No solution on [a..b] (1st function)! Press any key..." << std::endl;
            system("pause");
        } else {
            std::cout << "Second function (dividing): " << "   | ";
            solveDividing(a, b, precision, calcSecondFunc);
            std::cout << "Second function (iterations): " << " | ";
            solveIterations(a, b, precision, calcSF);
        }
        std::cout << "====================================================================" << std::endl;
    }
    return 0;
}
