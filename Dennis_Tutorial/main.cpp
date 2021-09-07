#include <stdio.h>
#include <iostream>
#include <utility>

#include "header.h"

//template<class...Args>
//void Print(Args...args)
//{
//    ((std::cout << std::forward<Args>(args) << " "), ...);
//    std::cout << '\n';
//}

int main()
{
    // variable declaration
    // type-specifier variable-name
    double x = 4.0;
    printf("%lf\n", CircleArea(x));


    // pointers
    double* y = &x;
    *y = *y + 5;

    printf("%lf\n", *y);
    std::cout << &x << ": " << x << '\n';
    std::cout << y << ": " << *y << '\n';

    double w = x;
    w = w + 5;
    std::cout << w << " " << x << '\n';


    double z[4] = { 5.0, 6.0, 7.0, 8.0 };
    // i++ <==> i += 1 <==> i = i + 1
    std::cout << z << ": " << *z << "\n";
    for (int i = 0; i < 4; i++)
        std::cout << &z[i] << ": " << z[i] << "\n";

    double* z2 = z;
    for (int i = 0; i < 4; i++)
        std::cout << &z2[i] << ": " << z2[i] << "\n";

    double* out = SquareArray(z, 4);
    for (int i = 0; i < 4; i++)
    {
        std::cout << z[i] << " " << out[i] << '\n';
    }

    double a = 5;
    ModifyVar(a);
    std::cout << a << '\n';

    ModifyVar(&a);
    std::cout << a << '\n';



    return 0;
}

