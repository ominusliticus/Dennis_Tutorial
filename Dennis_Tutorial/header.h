
#ifndef HEADER_H
#define HEADER_H

#include <iostream>

// functions and variables that are defined in the header file
// need to have the keyword `inline` prepended

inline void PrintEmptyLine()
{
    std::cout << "-------------------------------\n";
}

namespace practice
{
    // function prototyping
    double squared(double);
    double CircleArea(double);

    // squares a list of numbers
    double* SquareArray(double*, int);

    // Pass-by-reference
    void ModifyVar(double);
    void ModifyVar(double*);
}

namespace expert
{
    // function prototyping
    double squared(double);
    double CircleArea(double);

    // squares a list of numbers
    double* SquareArray(double*, int);

    // Pass-by-reference
    void ModifyVar(double);
    void ModifyVar(double*);
}

#endif