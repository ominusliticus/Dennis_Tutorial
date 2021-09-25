#include <stdio.h>
#include <iostream>
#include <utility>
#include <vector>
#include <cstring>

#include "header.h"
#include "Vector.h"

template<class...Args>
void Print(Args...args)
{
    ((std::cout << std::forward<Args>(args) << " "), ...);
    std::cout << '\n';
}


int main()
{
    Vector vec(10);
    Print(vec.Size());
    vec.Resize(20);
    Print(vec.Size());

    double ix = 0.0;
    for (int i = 0; i < 20; i++)
    {
        vec[i] = ix;
        ix += 1.0 / 20.0;
    }

    Vector vec2;
    for (int i = 0; i < 3; i++)
        vec2.PushBack((double)i);
    
    for (int i = 0; i < 3; i++) Print(vec2[i]);
    
    Vector vec3(vec);
    for (int i = 0; i < (int)vec.Size(); i++) Print(vec[i]);
    for (int i = 0; i < (int)vec3.Size(); i++) Print(vec3[i]);
    Print(vec3.Size());

    return 0;
}
