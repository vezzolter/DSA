// Source file for Dynamic Array
// by vezzolter
// January 31, 2024


#include "DynamicArray.h"


// --------------------
//  Compiler Generated
// --------------------

// Default constructor
DA::DA() : _size(0), _capacity(0), _data(nullptr) {}

// Parameterized constructor
DA::DA(int size, int val) :
    _size(size), _capacity(size), _data(new int[_capacity]) {
    // Fill the array with the given value
    for (int i = 0; i < _size; ++i) { _data[i] = val; }  
}

// Deep copy constructor
DA::DA(const DA& rhs) : _size(rhs._size), _capacity(rhs._capacity) {
    // Copy the data (if any), the size and capacity are in init list
    if (rhs._data) {
        _data = new int[_capacity];
        for (int i = 0; i < _size; ++i) { _data[i] = rhs._data[i]; }      
    } else {
        _data = nullptr;
    }  
}

// Deep copy assignment operator
DA& DA::operator=(const DA& rhs) {  
    // Prepare: check for self-assignment and deallocate any old memory
    if (this == &rhs) { return *this; } 
    delete[] _data; 

    // Copy the size, capacity, data (if any)
    _size = rhs._size;
    _capacity = rhs._capacity;
    if (rhs._data) {
        _data = new int[_capacity];
        for (int i = 0; i < _size; ++i) { _data[i] = rhs._data[i]; }   
    } else {
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

// Accesses the element at the specified index, allows modification
int& DA::operator[](const int index) { return _data[index]; }

// Accesses the element at the specified index, denies modification
const int& DA::operator[](const int index) const { return _data[index]; }

// Accesses the first element in the container, allows modification
int& DA::front() { return _data[0]; }

// Accesses the first element in the container, denies modification
const int& DA::front() const { return _data[0]; }

// Accesses the last element in the container, allows modification
int& DA::back() { return _data[_size - 1]; }

// Accesses the last element in the container, denies modification
const int& DA::back() const { return _data[_size - 1]; }


// ----------
//  Capacity
// ----------

// Returns true if the container has no elements
bool DA::empty() const { return (_size == 0); }

// Returns the number of stored elements in the container
int DA::size() const { return _size; }

// Returns the number of possible elements in the container
int DA::capacity() const { return _capacity; }

// Description
void DA::reserve() {
    // to be implemented
}

// Description
void DA::shrinkToFit() {
    // to be implemented
}


// ------------
//  Operations
// ------------

// Description
void DA::assign(int val) {
    // to be implemented
}

// Description
void DA::swap(DA& other) {
    // to be implemented
}
// ----------------------------------------------------------------------------
// Inserts element at given position, shifting other elements as needed
void DA::insert(int pos, const int& val) {
    // If memory isn't enough - reallocate, otherwise shift within from the end
    if (_size == _capacity) {
        // Allocate new memory (double if needed, or assign 1 if no at all)
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        int* newArray = new int[_capacity];

        // Copy elements before the position, insert, copy elements after
        for (int i = 0; i < pos; ++i) { newArray[i] = _data[i]; }
        newArray[pos] = val;
        for (int i = pos; i < _size; ++i) { newArray[i + 1] = _data[i]; }

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = newArray;
    } else {
        // Shifting from the beginning result in premature overwrite
        for (int i = _size; i > pos; --i) {
            _data[i] = _data[i - 1];
        }
        _data[pos] = val;
    }

    // Reflect new element on size
    ++_size; 
}

// ----------------------------------------------------------------------------
// Appends the given element to the end of the container
void DA::pushBack(const int& newData) {
    if (_size == _capacity) {
        // Allocate new memory (double if needed, or assign 1 if no at all)
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        int* newArray = new int[_capacity];

        // Copy elements from the old array to the new one
        for (int i = 0; i < _size; ++i) { newArray[i] = _data[i];}

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = newArray;
    }

    // Insert the new value at the end
    _data[_size] = newData;

    // Reflect new element on size
    ++_size; 
}


// Description
void DA::popBack() {
    // to be implemented
}

// ----------------------------------------------------------------------------
// Removes an element at the specified position
void DA::erase(int index) {
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

// Clears the entire content of the dynamic array, freeing memory.
// Note: without potential memory-reserving adjustments
void DA::clear() {
    delete[] _data; // dealloc
    _data = nullptr; // avoid dangling pointer
    _size = 0; // reflect change on the size
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