
#include "header.h"

double squared(double x)
{
    return x * x;
}


double CircleArea(double radius)
{
    double pi = 3.14159;
    return pi * squared(radius);
}

double* SquareArray(double* x, int count)
{
    double* out = new double[count];
    for (int i = 0; i < count; i++)
    {
        out[i] = squared(x[i]);
    }
    return out;
}

void ModifyVar(double x)
{
    x += 10; // x = x + 10
}

void ModifyVar(double* x)
{
    *x += 10;
}