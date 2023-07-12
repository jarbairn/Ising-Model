#include <iostream>
#include <cmath>
#include "statistics.h"

using namespace std;

statistics::statistics()
{
    n = 0;
    sum = 0.0;
    sumsq = 0.0;
}

int statistics::getNumber() const
{
    return n;
}

double statistics::getAverage() const
{
    if (n == 0) return 0.;
    return sum / n;
}

double statistics::getSqAverage() const
{
    if (n == 0) return -1;
    return sumsq / n;
}

void statistics::add(double x)
{
    n++;
    sum += x;
    sumsq += x * x;
}
double statistics::getVarSq() const
{
    if (n == 0) return 0.;
    return sqrt((varsq - (sumsq / n)) * (varsq - (sumsq / n)) / (n - 1));
}

double statistics::getVar() const
{
    if (n == 0) return 0.;
    return sqrt((var - (sum / n)) * (var - (sum / n)) / (n - 1));
}