// Source file for simplified ADT: Static Array
// by vezzolter
// January 29, 2024

#include "StaticArray.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
StaticArr::StaticArr() : _size(0)
{
    for (int i = 0; i < MAX_SIZE; ++i)
        _data[i] = 0;
}

// Parameterized constructor
StaticArr::StaticArr(int size) : _size(size)
{
    // Initialize the array with default values
    for (int i = 0; i < MAX_SIZE; ++i)
        _data[i] = 0;
}

// Destructor
StaticArr::~StaticArr() { }


// --------------
// Element Access
// --------------

// Access the element at the specified index without bounds checking
int& StaticArr::operator[](const int pos) { return _data[pos]; }

// Access the first element of the container without bounds checking
int StaticArr::front() { return _data[0]; }

// Access the last element of the container without bounds checking
int StaticArr::back() { return _data[_size - 1]; }



// --------
// Capacity
// --------

// Check if the container is empty
bool StaticArr::empty() const { return (_size == 0); }

// Get the size of the container
int StaticArr::size() const { return _size; }
