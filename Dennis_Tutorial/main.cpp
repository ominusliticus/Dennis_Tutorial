#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>

#include "header.h"

//template<class...Args>
//void Print(Args...args)
//{
//    ((std::cout << std::forward<Args>(args) << " "), ...);
//    std::cout << '\n';
//}

int main()
{
    double a = 5;
    practice::ModifyVar(a);
    std::cout << a << '\n';
    PrintEmptyLine();
    expert::ModifyVar(&a);
    std::cout << a << '\n';



    return 0;
}

