// Title:   Source file for Static Array
// Authors: by vezzolter
// Date:    January 29, 2024
// ----------------------------------------------------------------------------


#include "StaticArray.h"


// --------------------
//  Compiler Generated 
// --------------------

// Constructs an empty array
SA::SA() { 
    for (int i = 0; i < _SIZE; ++i) { _data[i] = 0; }
}

// Constructs an array with the contents of 'other'
SA::SA(const SA& other) { 
    for (int i = 0; i < _SIZE; ++i) { _data[i] = other._data[i]; }
}

// Replaces the contents with a copy of the contents of 'rhs'
SA& SA::operator=(const SA& rhs) {
    if (this == &rhs) { return *this; } // self-assignment guard
    for (int i = 0; i < _SIZE; ++i) { _data[i] = rhs._data[i]; }

    return *this;
}


// -----------
//  Iterators 
// -----------

// Returns an iterator to the first element of the array
SA::Iterator SA::begin() { return Iterator(_data); }

// Returns an iterator to one past the last element of the array
SA::Iterator SA::end() { return Iterator(_data + _SIZE); } 

// Returns a const iterator to the first element of the array
SA::const_iterator SA::begin() const { return ConstIterator(_data); }

// Returns a const iterator to one past the last element of the array
SA::const_iterator SA::end() const { return ConstIterator(_data + _SIZE); }

// Explicitly returns a const iterator to the first element of the array
SA::ConstIterator SA::cbegin() const { return ConstIterator(_data); }

// Explicitly returns a const iterator to one past the last element of the array
SA::ConstIterator SA::cend() const { return ConstIterator(_data + _SIZE); }


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

// Returns true if array has no elements
bool SA::empty() const { return (_SIZE == 0); }

// Returns the number of stored elements
int  SA::size() const { return _SIZE; }


// ------------
//  Operations
// ------------

// Replaces the contents with 'val'
void SA::fill(int val) {
    for (int i = 0; i < _SIZE; ++i) { _data[i] = val; }
}

// Fills the array with elements from the range [first, last)
void SA::fill(Iterator first, Iterator last) {
    int index = 0;
    for (auto it = first; it != last && index < _SIZE; ++it) { _data[index++] = *it; }
}

// Exchanges the contents of the array with those of 'other'
void SA::swap(SA& other) {
    // Case: the same container
    if (this == &other) { return; }

    for (int i = 0; i < _SIZE; ++i) {
        int temp = _data[i];
        _data[i] = other._data[i];
        other._data[i] = temp;
    }
}
