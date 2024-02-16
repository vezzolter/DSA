// Source file for simplified ADT: Dynamic Array
// by vezzolter
// January 31, 2024

#include "DynamicArray.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
DynArr::DynArr() : _size(0), _data(nullptr) {}

// Parameterized constructor
// Note: without bounds checking
DynArr::DynArr(int size, int defVal) : _size(size) {
    _data = new int[size];
    for (int i = 0; i < size; ++i) {
        _data[i] = defVal;
    }
        
}

// Copy constructor
DynArr::DynArr(const DynArr& rhs) : _size(rhs._size) {
    // Shallow Copy
    _size = rhs._size;

    // Deep Copy if has data
    if (rhs._data) {
        // Allocate new array
        _data = new int[_size];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            _data[i] = rhs._data[i];
    }
    else {
        _data = nullptr;
    }
        
}

// Copy Assignment Operator
DynArr& DynArr::operator=(const DynArr& rhs) {
    // Self assignment check
    if (this == &rhs) {
        return *this;
    }
        

    // Prevent memory leak
    delete[] _data;

    // Shallow copy
    _size = rhs._size;

    // Deep Copy is has data
    if (rhs._data) {
        // Allocate new array
        _data = new int[_size];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            _data[i] = rhs._data[i];
    }
    else {
        _data = nullptr;
    }
        

    return *this;
}

// Destructor
DynArr::~DynArr() { delete[] _data; }


// --------------
// Element Access
// --------------

// Access the element at the specified index without bounds checking
int& DynArr::operator[](const int index) { return _data[index]; }

int& DynArr::operator[](const int index) const { return _data[index]; }

// Access the first element of the container without bounds checking
int DynArr::front() { return _data[0]; }

// Access the last element of the container without bounds checking
int DynArr::back() { return _data[_size - 1]; }



// --------
// Capacity
// --------

// Check if the container has elements
bool DynArr::empty() const { return (_size == 0); }

// Get the size of the container
int DynArr::size() const { return _size; }



// ---------
// Modifiers
// ---------

// Inserts a new element at the specified position, shifting other elements as needed.
// Note: without potential memory-reserving adjustments and bounds checking
void DynArr::insert(int index, int val) {
    // New array, one element more
    int* newData = new int[_size + 1];

    // Copy elements before the position
    for (int before = 0; before < index; ++before)
        newData[before] = _data[before];

    // Insert the new value at the specified position
    newData[index] = val;

    // Copy elements after the position
    for (int after = index; after < _size; ++after)
        newData[after + 1] = _data[after];

    // Manage memory
    delete[] _data;
    _data = newData;
    ++_size;
}

// Removes an element at the specified position
// Note: without potential memory-reserving adjustments and bounds checking
void DynArr::remove(int index) {
    // Sole element
    if (_size == 1) {
        clear();
        return;
    }

    // New array, one element less
    int* data = new int[_size - 1];

    // Copy until position
    for (int before = 0; before < index; ++before)
        data[before] = _data[before];

    // Copy after position
    for (int after = index + 1; after < _size; ++after)
        data[after - 1] = _data[after];

    // Manage memory
    delete[] _data;
    _data = data;
    --_size;
}

// Changes the size of an array exactly to the given
// Note: without potential memory-reserving adjustments
void DynArr::resize(int newSize) {
    // Either already required or leads to deleting
    if (newSize <= _size) {
        return;
    }

    // Greater, every element preserves
    if (newSize > _size) {
        // Allocate new array
        int* newData = new int[newSize];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            newData[i] = _data[i];

        // Manage memory
        delete[] _data;
        _data = newData;
        _size = newSize;
    }
}

// Clears the entire content of the dynamic array, freeing memory.
// Note: without potential memory-reserving adjustments
void DynArr::clear() {
    delete[] _data;
    _data = nullptr;
    _size = 0;
}