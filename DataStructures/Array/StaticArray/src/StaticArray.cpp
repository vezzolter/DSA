// Source file for simplified ADT: Static Array
// by vezzolter
// January 29, 2024

#ifndef SA_CPP
#define SA_CPP

#include "StaticArray.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
template<class T, int MAX_SIZE>
SA<T, MAX_SIZE>::SA() : _size(0) {
    for (int i = 0; i < MAX_SIZE; ++i)
        _data[i] = 0;
}

// Parameterized constructor, no range check
template<class T, int MAX_SIZE>
SA<T, MAX_SIZE>::SA(int size) : _size(size) {
    for (int i = 0; i < MAX_SIZE; ++i)
        _data[i] = 0;
}

// Shallow copy constructor
template<class T, int MAX_SIZE>
SA<T, MAX_SIZE>::SA(const SA& rhs) : _size(rhs._size) {
    for (int i = 0; i < _size; ++i)
        _data[i] = rhs._data[i];
}

// Shallow copy assignment operator
template<class T, int MAX_SIZE>
SA<T, MAX_SIZE>& SA<T, MAX_SIZE>::operator=(const SA& rhs) {
    // Self-assignment guard
    if (this == &rhs)
        return *this;

    _size = rhs._size;
    for (int i = 0; i < _size; ++i)
        _data[i] = rhs._data[i];

    return *this;
}



// --------------
// Element Access
// --------------

// Accesses the element at the specified index, allows modification, no range check
template<class T, int MAX_SIZE>
T& SA<T, MAX_SIZE>::operator[](const int index) { return _data[index]; }

// Accesses the element at the specified index, denies modification, no range check
template<class T, int MAX_SIZE>
const T& SA<T, MAX_SIZE>::operator[](const int index) const { return _data[index]; }

// Accesses the first element in the container, allows modification, no range check
template<class T, int MAX_SIZE>
T& SA<T, MAX_SIZE>::front() { return _data[0]; }

// Accesses the first element in the container, denies modification, no range check
template<class T, int MAX_SIZE>
const T& SA<T, MAX_SIZE>::front() const { return 0; }

// Accesses the last element in the container, allows modification, no range check
template<class T, int MAX_SIZE>
T& SA<T, MAX_SIZE>::back() { return _data[_size - 1]; }

// Accesses the last element in the container, denies modification, no range check
template<class T, int MAX_SIZE>
const T& SA<T, MAX_SIZE>::back() const { return 0; }



// --------
// Capacity
// --------

// Check if the container is empty
template<class T, int MAX_SIZE>
bool SA<T, MAX_SIZE>::empty() const { return (_size == 0); }

// Get the size of the container
template<class T, int MAX_SIZE>
int SA<T, MAX_SIZE>::size() const { return _size; }


#endif