// Source file for Static Array
// by vezzolter
// January 29, 2024


#ifndef SA_CPP
#define SA_CPP


#include "StaticArray.h"


// --------------------------
//  Special Member Functions 
// --------------------------

// Default Constructor
SA::SA() : _size(0) {
    for (int i = 0; i < 100; ++i)
        _data[i] = 0;
}

// Parameterized Constructor
SA::SA(int size) : _size(size) {
    for (int i = 0; i < size; ++i)
        _data[i] = 0;
}

// Shallow Copy Constructor
SA::SA(const SA& rhs) : _size(rhs._size) {
    for (int i = 0; i < _size; ++i)
        _data[i] = rhs._data[i];
}

// Shallow Copy Assignment Operator
SA& SA::operator=(const SA& rhs) {
    // Self-assignment guard
    if (this == &rhs)
        return *this;

    _size = rhs._size;
    for (int i = 0; i < _size; ++i)
        _data[i] = rhs._data[i];

    return *this;
}


// ----------------
//  Element Access
// ----------------

// Accesses the element at the specified index, no range check, allows modification
int& SA::operator[](const int index) { return _data[index]; }

// Accesses the element at the specified index, no range check, denies modification
const int& SA::operator[](const int index) const { return _data[index]; }

// Accesses the first element in the container, no range check, allows modification
int& SA::front() { return _data[0]; }

// Accesses the first element in the container, no range check, denies modification
const int& SA::front() const { return _data[0]; }

// Accesses the last element in the container, no range check, allows modification
int& SA::back() { return _data[_size - 1]; }

// Accesses the last element in the container, no range check, denies modification
const int& SA::back() const { return _data[_size - 1]; }


// ----------
//  Capacity
// ----------

// Check if the container is empty
bool SA::empty() const { return (_size == 0); }

// Get the size of the container
int  SA::size() const { return _size; }


// ------------
//  Operations
// ------------

// Exchanges the contents of this array with another array
//void SA::assign() { }

// Get the size of the container
//void SA::swap() { }


#endif