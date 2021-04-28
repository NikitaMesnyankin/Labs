#ifndef LAB8_DATA_H
#define LAB8_DATA_H

#include <iomanip>
#include <iostream>
#include "math.h"

double calcFirstFunc(const double x);
double calcSecondFunc(const double x);
double calcFF(const double x);
double calcSF(const double x);
int solveDividing(const double a, const double b, const double precision, double (*func)(double));
int solveIterations(const double a, const double b, const double precision, double (*func)(double));

#endif LAB8_DATA_H
