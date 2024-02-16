// Source file for simplified ADT: Static Array
// by vezzolter
// January 29, 2024

#include "StaticArray.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
SA::SA() : _size(0) {
    for (int i = 0; i < MAX_SIZE; ++i)
        _data[i] = 0;
}

// Parameterized constructor
SA::SA(int size) : _size(size) {
    // Initialize the array with default values
    for (int i = 0; i < MAX_SIZE; ++i)
        _data[i] = 0;
}



// --------------
// Element Access
// --------------

// Accesses the element at the specified index, allows modification, no range check
int& SA::operator[](const int index) { return _data[index]; }

// Accesses the element at the specified index, denies modification, no range check
const int& SA::operator[](const int index) const { return _data[index]; }

// Accesses the first element in the container, allows modification, no range check
int SA::front() { return _data[0]; }

// Accesses the first element in the container, denies modification, no range check
const int SA::front() const { return 0; }

// Accesses the last element in the container, allows modification, no range check
int SA::back() { return _data[_size - 1]; }

// Accesses the last element in the container, denies modification, no range check
const int SA::back() const { return 0; }



// --------
// Capacity
// --------

// Check if the container is empty
bool SA::empty() const { return (_size == 0); }

// Get the size of the container
int SA::size() const { return _size; }
