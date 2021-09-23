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
    // Error bounds checking not done
    return m_data[i];
}

Vector& Vector::operator=(const Vector& vec)
{
    m_size        = vec.m_size;
    m_reserved    = vec.m_reserved;
    memcpy((void*)m_data, (const void*)vec.m_data, m_size);
    return *this;
}

Vector& Vector::operator=(Vector&& vec) noexcept
{
    m_size      = vec.m_size;
    m_reserved  = vec.m_reserved;
    m_data      = vec.m_data;

    vec.Orphan();
    return *this;
}

double Vector::At(size_t i)
{
    // Error bounds checking not done
    return m_data[i];
}

void Vector::PushBack(double val)
{
    if (m_size + 1 < m_reserved)
    {
        m_data[m_size] = val;
        m_size++;
    }
    else
    {
        // Allocate new array
        double* temp = new double[m_reserved + 3];
        // Copy existing data
        memcpy((void*)temp, (const void*)m_data, m_reserved);
        // Free old data
        delete[] m_data;
        // Assign pointer to new data;
        m_data = temp;
        // Avoid memory leak
        temp = nullptr;

        // Update sizes
        m_size      = m_reserved;
        m_reserved  = m_size + 3;
    }
}

void Vector::Resize(size_t n)
{
    // Check PushBack for more details
    double* temp = new double[n + 3];
    memcpy((void*)temp, (const void*)m_data, m_reserved);
    delete[] m_data;
    m_data = temp;
    temp = nullptr;

    // Update sizes
    m_size      = n;
    m_reserved  = n + 3;
}

size_t Vector::Size() const
{
    return m_size;
}

double* Vector::Data()
{
    return m_data;
}

void Vector::Clear()
{
    delete[] m_data;
    m_size      = 0;
    m_reserved  = 0;
}

void Vector::Orphan()
{
    m_data      = nullptr;
    m_size      = 0;
    m_reserved  = 0;
}