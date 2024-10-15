// Source file for Static Array
// by vezzolter
// January 29, 2024


#include "StaticArray.h"


// --------------------
//  Compiler Generated 
// --------------------

// Default Constructor
SA::SA() { for (int i = 0; i < _SIZE; ++i) { _data[i] = 0; } }

//// Parameterized Constructor
//SA::SA(std::initializer_list<int> values) { }

// Shallow Copy Constructor
SA::SA(const SA& rhs) { for (int i = 0; i < _SIZE; ++i) { _data[i] = rhs._data[i]; } }

// Shallow Copy Assignment Operator
SA& SA::operator=(const SA& rhs) {
    if (this == &rhs) { return *this; } // Self-assignment guard
    for (int i = 0; i < _SIZE; ++i) { _data[i] = rhs._data[i]; }
    return *this;
}


// -----------
//  Iterators 
// -----------

// Returns an iterator to the first element of the container
SAIterator SA::begin() { return SAIterator(_data); }

// Returns an iterator to one past the last element of the container
SAIterator SA::end() { return SAIterator(_data + _SIZE); } 


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
int& SA::back() { return _data[_SIZE - 1]; }

// Accesses the last element in the container, no range check, denies modification
const int& SA::back() const { return _data[_SIZE - 1]; }


// ----------
//  Capacity
// ----------

// Check if the container is empty
bool SA::empty() const { return (_SIZE == 0); }

// Get the size of the container
int  SA::size() const { return _SIZE; }


// ------------
//  Operations
// ------------

// Assigns the specified value to all elements in the array
void SA::assign(int val) { for (int i = 0; i < _SIZE; ++i) { _data[i] = val; } }

// Swaps the contents with another static array
void SA::swap(SA& other) {
    for (int i = 0; i < _SIZE; ++i) {
        int temp = _data[i];
        _data[i] = other._data[i];
        other._data[i] = temp;
    }
}
