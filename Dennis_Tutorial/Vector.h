#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>


class Vector
{
public:
    // default constructor
    Vector() = default;
    // allocate n bits of memory
    Vector(size_t n);
    // allocate n bits of memory and fill with array
    Vector(double* array, size_t n);
    // Copy constructor
    Vector(const Vector& vec);
    // Destructor  
    ~Vector();

    // to access memory as with usual array
    double operator[](size_t i);
    // copy assignment operator
    Vector& operator=(const Vector& vec);
    // move assignment operator
    Vector& operator=(Vector&& vec) noexcept;

    // to access memory as with usual array, but container is of pointer type
    double  At(size_t i);
    // increase size by one, and fill with val
    void  PushBack(double val);
    // change vector size to n, which must be greater than current size; 
    void    Resize(size_t n);
    // return size of vector, not reserved
    size_t  Size() const;
    // return the underlying pointer to data
    double* Data();
    // delete memory allocation, and set size to zero
    void    Clear();
    // sets instance back to default, without deleting data (for move semantics)
    void    Orphan();

private:
    double* m_data = nullptr;
    size_t  m_size;
    size_t  m_reserved;
};

#endif
