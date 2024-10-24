// Title:   Source file for Static Array
// Authors: by vezzolter
// Date:    January 29, 2024
// ----------------------------------------------------------------------------


#include "StaticArray.h"


// --------------------
//  Compiler Generated 
// --------------------

// Initializes an empty array
SA::SA() { 
    for (int i = 0; i < _SIZE; ++i) { _data[i] = 0; }
}

// Initializes an array with data by shallow copying it from another one
SA::SA(const SA& rhs) { 
    for (int i = 0; i < _SIZE; ++i) { _data[i] = rhs._data[i]; }
}

// Assigns an array with data by shallow copying it from another one
SA& SA::operator=(const SA& rhs) {
    if (this == &rhs) { return *this; } // self-assignment guard
    for (int i = 0; i < _SIZE; ++i) { _data[i] = rhs._data[i]; }

    return *this;
}


// -----------
//  Iterators 
// -----------

// Returns an iterator to the first element of the array
SAIterator SA::begin() { return SAIterator(_data); }

// Returns an iterator to one past the last element of the array
SAIterator SA::end() { return SAIterator(_data + _SIZE); } 


// ----------------
//  Element Access
// ----------------

// Returns a modifiable reference to the element at the given position
int& SA::operator[](const int pos) { return _data[pos]; }

// Returns a non-modifiable reference to the element at the given position
const int& SA::operator[](const int pos) const { return _data[pos]; }

// Returns a modifiable reference to the first element
int& SA::front() { return _data[0]; }

// Returns a non-modifiable reference to the first element
const int& SA::front() const { return _data[0]; }

// Returns a modifiable reference to the last element
int& SA::back() { return _data[_SIZE - 1]; }

// Returns a non-modifiable reference to the last element
const int& SA::back() const { return _data[_SIZE - 1]; }


// ----------
//  Capacity
// ----------

// Returns true if the array has no elements
bool SA::empty() const { return (_SIZE == 0); }

// Returns the number of stored elements
int  SA::size() const { return _SIZE; }


// ------------
//  Operations
// ------------

// Assigns the specified value to all elements
void SA::assign(int val) {
    for (int i = 0; i < _SIZE; ++i) { _data[i] = val; }
}

// Swaps the data with another array
void SA::swap(SA& other) {
    // Case: the same container
    if (this == &other) { return; }

    for (int i = 0; i < _SIZE; ++i) {
        int temp = _data[i];
        _data[i] = other._data[i];
        other._data[i] = temp;
    }
}
