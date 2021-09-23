#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>

#include "header.h"

template<class...Args>
void Print(Args...args)
{
    ((std::cout << std::forward<Args>(args) << " "), ...);
    std::cout << '\n';
}

// function that return double and take on double argument
double SecantMethod(double (*)(double),double);
double quantumProblem(double x)
{
    return 1.0 / tan(x) - x;
}

int main()
{
    int age;
    bool keep_running = false;
    while (keep_running)
    {
        Print("Please enter you age:");
        std::cin >> age;
        if (age < 0)
            break;

        if (age >= 21)
        {
            if (age == 21)
                Print("I bet you drank before this.");

            Print("You can vote and drink!");
        }
        else if (age >= 18)
        {
            Print("You can vote!");
        }
        else
        {
            Print("You're a baby...");
        }

    }

    Print("First energy level is:", SecantMethod(quantumProblem, 1.2));

    return 0;
}

double SecantMethod(double (*func)(double), double x0)
{
    double tol = 1e-6;
    double x1, x2;

    x1 = 1.1 * x0;

    double err = 1e10;
    while (err > tol)
    {
        x2 = x1 - func(x1) * (x1 - x0) / (func(x1) - func(x0));
        x0 = x1;
        x1 = x2;

        err = fabs((x2 - x1) / x2);
    }

    return x2;
}