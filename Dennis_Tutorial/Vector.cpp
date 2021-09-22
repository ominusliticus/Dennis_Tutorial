#include "Vector.h"

// No definition for Vector(), we will let compiler take care of that

Vector::Vector(size_t n) 
    : m_size{ n }, m_reserved{ n + 3 }  // Initializer list
{
    m_data = new double[n + 3];
}

Vector::Vector(double* array, size_t n)
    : m_size{ n }, m_reserved{ n + 3 }
{
    m_data = new double[n + 3];
    memcpy((void*)m_data, (const void*)array, n);
}

Vector::Vector(const Vector& vec)
{
    m_size      = vec.m_size;
    m_reserved  = vec.m_reserved;
    memcpy((void*)m_data, (const void*)vec.m_data, m_size);
}

Vector::~Vector()
{
    Clear();
}

double Vector::operator[](size_t i)
{
    return m_data[i];
}

Vector& Vector::operator=(const Vector& vec)
{
    m_size        = vec.m_size;
    m_reserved    = vec.m_reserved;
    memcpy((void*)m_data, (const void*)vec.m_data, m_size);
    return *this;
}

Vector& Vector::operator=(Vector&& vec)
{
    m_size      = vec.m_size;
    m_reserved  = vec.m_reserved;
    m_data      = vec.m_data;

    vec.Orphan();
    return *this;
}