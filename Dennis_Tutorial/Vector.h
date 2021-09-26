#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

// TODO: Add iterator class to Vector
// Will go ahead and implement here so that refactoring is easier
// when I switch everything to templates
class VectorIterator
{
public:
    // TODO: add iterator flags

    // Default constructor
    VectorIterator() = default;
    // Constructor that takes a pointer
    VectorIterator(double* ptr) : m_ptr{ ptr } {};
        
    // Allow for dereferencing
    double& operator*()     { return *m_ptr; };
    // Allow for pointer access
    double* operator->()    { return m_ptr; };

    // Increment pointer, return iterator at new address
    VectorIterator&   operator++()    { m_ptr++; return *this; };
    // Decrement pointer, return iterator at new address
    VectorIterator&   operator--()    { m_ptr--; return *this; };
    // Increment pointer, returns value stored at previous adress
    VectorIterator    operator++(int) { VectorIterator temp = *this; ++(*this); return temp; };
    // Decrement pointer, returns value stored at previous address
    VectorIterator    operator--(int) { VectorIterator temp = *this; --(*this); return temp; };
        
    // These are pretty explanatory
    friend bool operator==(const VectorIterator& a, const VectorIterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!=(const VectorIterator& a, const VectorIterator& b) { return a.m_ptr != b.m_ptr; };

private:
    double* m_ptr;
};
// TODO: upgrade to templated vector

class Vector
{
public:
    // TODO: add class flags

    // default constructor
    Vector();
    // allocate n bits of memory
    Vector(size_t n);
    // allocate n bits of memory and fill with array
    Vector(double* array, size_t n);
    // Copy constructor
    Vector(const Vector& vec);
    // Destructor  
    ~Vector();

    // to access memory as with usual array
    double& operator[](size_t i);
    // copy assignment operator
    Vector& operator=(const Vector& vec);
    // move assignment operator
    Vector& operator=(Vector&& vec) noexcept;

    // to access memory as with usual array, but container is of pointer type
    double  At(size_t i);
    // increase size by one, and fill with val
    void    PushBack(double val);
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


    // Need to be lower-case so that range-based loop API can identify
    VectorIterator begin()  { return &m_data[0]; }
    VectorIterator end()    { return &m_data[m_size]; };

protected:
    double* m_data = nullptr;
    size_t  m_size;
    size_t  m_reserved;
};

#endif
