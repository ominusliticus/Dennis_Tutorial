#include "Vector.h"

#include <cstring>

Vector::Vector()
    : m_size{ 0 }, m_reserved{ 3 }
{
    m_data = new double[m_reserved];
}

Vector::Vector(size_t n) 
    : m_size{ n }, m_reserved{ n + 3 }  // Initializer list
{
    m_data = new double[n + 3];
}

Vector::Vector(double* array, size_t n)
    : m_size{ n }, m_reserved{ n + 3 }
{
    m_data = new double[n + 3];
    memcpy(m_data, array, n);
}

Vector::Vector(const Vector& vec)
{
    Orphan();
    m_size      = vec.m_size;
    m_reserved  = vec.m_reserved;
    m_data      = new double[m_reserved];
    std::memcpy(m_data, vec.m_data, m_size * sizeof(double));
}

Vector::~Vector()
{
    Clear();
}

double& Vector::operator[](size_t i)
{
    // Error bounds checking not done
    return m_data[i];
}

Vector& Vector::operator=(const Vector& vec)
{
    m_size      = vec.m_size;
    m_reserved  = vec.m_reserved;
    m_data      = new double[m_reserved];
    std::memcpy(m_data, vec.m_data, m_size * sizeof(double));
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
        size_t i = 3 - (m_reserved - m_size);
        m_data[i] = val;
        m_size++;
    }
    else
    {
        // Allocate new array
        double* temp = new double[m_reserved + 3];
        // Copy existing data
        memcpy(temp, m_data, m_reserved * sizeof(double));
        // Free old data
        delete[] m_data;
        // Assign pointer to new data;
        m_data = temp;
        // Add new value to vector
        temp[m_reserved] = val;
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
    memcpy(temp, m_data, m_reserved * sizeof(double));
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