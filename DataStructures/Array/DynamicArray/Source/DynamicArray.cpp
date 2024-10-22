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

// Removes an element at the specified position
void DA::erase(int pos) {
    // Edge case: one element
    if (_size == 1) {
        clear();
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = pos; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }

    // Reflect removed element on size
    --_size;
}

// Removes all the elements, doesn't touch the capacity (thus memory)
void DA::clear() {
    if (_size == 0) { return; }
    // TODO: Invalidate iterators pointing to elements
    // TODO: Call the destructor for each element
    _size = 0;
}

// Description
void DA::assign(int val) {
    // to be implemented
}

// Description
void DA::swap(DA& other) {
    // to be implemented
}

// Changes the size of an array exactly to the given
void DA::resize(int newSize) {
    // Case 1: new size is the same as current one
    if (newSize == _size) { return; }

    // Case 2: new size is smaller than current one 
    if (newSize < _size) {
        _size = newSize;
        return;
    }
    
    // Case 3: new size is larger than current one, but exceeds capacity
    if (newSize > _capacity) {         
        // Allocate new memory (assign given or double it)
        _capacity = newSize > _capacity * 2 ? newSize : _capacity * 2;
        int* newArray = new int[_capacity];

        // Copy existing elements
        for (int i = 0; i < _size; ++i) {
            newArray[i] = _data[i];
        }

        // Default initialize new elements to 0
        for (int i = _size; i < newSize; ++i) {
            newArray[i] = 0;
        }

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = newArray;

        // Update size to the new size
        _size = newSize;
    } 
    // Case 4: new size is larger than current one, but within capacity
    else {
        // Capacity is sufficient, just default initialize new elements
        for (int i = _size; i < newSize; ++i) {
            _data[i] = 0;
        }

        // Update size to the new size
        _size = newSize;
    }
}