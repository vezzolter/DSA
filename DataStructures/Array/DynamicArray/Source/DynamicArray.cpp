// Source file for Dynamic Array
// by vezzolter
// January 31, 2024


#include "DynamicArray.h"


// --------------------
//  Compiler Generated
// --------------------

// Default constructor
DA::DA() : _size(0), _data(nullptr) {}

// Parameterized constructor, no range check
DA::DA(int newSize, int newData) : _size(newSize) {
    // Allocate memory for new array
    _data = new int[newSize];

    // Fill with elements
    for (int i = 0; i < newSize; ++i) {
        _data[i] = newData;
    }
        
}

// Deep copy constructor
DA::DA(const DA& rhs) : _size(rhs._size) {
    if (rhs._data) {
        // Allocate memory for new array
        _data = new int[_size];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            _data[i] = rhs._data[i];
    }
    else {
        _data = nullptr;
    }
        
}

// Deep copy assignment operator
DA& DA::operator=(const DA& rhs) {
    // Self-assignment guard
    if (this == &rhs)
        return *this;
        
    // Prevent memory leak
    delete[] _data;
    // Set corresponding size
    _size = rhs._size;

    if (rhs._data) {
        // Allocate memory for new array
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
DA::~DA() { delete[] _data; }


// -----------
//  Iterators 
// -----------

//// Returns an iterator to the first element of the container
//DAIterator DA::begin() { return DAIterator(_data); }
//
//// Returns an iterator to one past the last element of the container
//DAIterator DA::end() { return DAIterator(_data + _size); }


// ----------------
//  Element Access 
// ----------------

// Accesses the element at the specified index, no range check, allows modification
int& DA::operator[](const int index) { return _data[index]; }

// Accesses the element at the specified index, no range check, denies modification
const int& DA::operator[](const int index) const { return _data[index]; }

// Accesses the first element in the container, no range check, allows modification
int& DA::front() { return _data[0]; }

// Accesses the first element in the container, no range check, denies modification
const int& DA::front() const { return _data[0]; }

// Accesses the last element in the container, no range check, allows modification
int& DA::back() { return _data[_size - 1]; }

// Accesses the last element in the container, no range check, denies modification
const int& DA::back() const { return _data[_size - 1]; }


// ----------
//  Capacity
// ----------

// Checks if the container has no elements
bool DA::empty() const { return (_size == 0); }

// Returns the number of elements in the container
int DA::size() const { return _size; }


// ------------
//  Operations
// ------------

// Appends the given element to the end of the container
// Note: without potential memory-reserving adjustments and bounds checking
void DA::pushBack(const int& newData) {
    // Allocate memory for new array, one element more
    int* newArray = new int[_size + 1];

    // Copy elements
    for (int i = 0; i < _size; ++i)
        newArray[i] = _data[i];

    // Insert the new value at the end
    newArray[_size] = newData;

    // Manage memory and pointers
    delete[] _data; // dealloc
    _data = newArray; // point to new
    ++_size; // reflect change on the size

}

// Inserts elements at the specified position, shifting other elements as needed.
// Note: without potential memory-reserving adjustments and bounds checking
void DA::insert(int index, const int& newData) {
    if (index == _size - 1) {
      pushBack(newData);
    }
    else {
        // Allocate memory for new array, one element more
        int* newArray = new int[_size + 1];

        // Copy elements before the position
        for (int before = 0; before < index; ++before)
            newArray[before] = _data[before];

        // Insert the new value at the specified position
        newArray[index] = newData;

        // Copy elements after the position
        for (int after = index; after < _size; ++after)
            newArray[after + 1] = _data[after];

        // Manage memory and pointers
        delete[] _data; // dealloc
        _data = newArray; // point to new
        ++_size; // reflect change on the size
    }
}

// Removes an element at the specified position
// Note: without potential memory-reserving adjustments and bounds checking
void DA::remove(int index) {
    // Case: one element
    if (_size == 1) {
        clear();
        return;
    }

    // Allocate memory for new array, one element less
    int* newArray = new int[_size - 1];

    // Copy before position
    for (int before = 0; before < index; ++before)
        newArray[before] = _data[before];

    // Copy after position
    for (int after = index + 1; after < _size; ++after)
        newArray[after - 1] = _data[after];

    // Manage memory and pointers
    delete[] _data; // dealloc
    _data = newArray; // point to new
    --_size; // reflect change on the size
}

// Changes the size of an array exactly to the given
// Note: without potential memory-reserving adjustments
void DA::resize(int newSize) {
    // Case: already required size
    if (newSize <= _size) {
        return;
    }

    if (newSize > _size) {
        // Allocate memory for new array
        int* newArray = new int[newSize];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            newArray[i] = _data[i];

        // Manage memory and pointers
        delete[] _data; // dealloc
        _data = newArray; // point to new
        _size = newSize; // reflect change on the size
    }
}

// Clears the entire content of the dynamic array, freeing memory.
// Note: without potential memory-reserving adjustments
void DA::clear() {
    delete[] _data; // dealloc
    _data = nullptr; // avoid dangling pointer
    _size = 0; // reflect change on the size
}