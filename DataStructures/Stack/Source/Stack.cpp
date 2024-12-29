// Title:   Source file for Stack (Array-Based)
// Authors: by vezzolter
// Date:    March 2, 2024
// ----------------------------------------------------------------------------


#include "Stack.h"


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty stack 
Stack::Stack() : _size(0), _capacity(0), _data(nullptr) {}

// Constructs a stack with the contents of 'other'
Stack::Stack(const Stack& other)
    : _size(other._size), _capacity(other._capacity) {

    // Copy the data (if any), the size and capacity are in init list
    if (other._data) {
        _data = new int[_capacity];
        for (int i = 0; i < _size; ++i) { _data[i] = other._data[i]; }

    } else {
        _data = nullptr;
    }
}

// Replaces the contents with a copy of the contents of 'rhs'
Stack& Stack::operator=(const Stack& rhs) {
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

// Destructs the stack 
Stack::~Stack() { delete[] _data; }


// ----------------
//  Element Access 
// ----------------

// Returns a modifiable reference to the last element
int& Stack::top() { return _data[_size - 1]; }

// Returns a non-modifiable reference to the last element
const int& Stack::top() const { return _data[_size - 1]; }


// ----------
//  Capacity
// ----------

// Returns true if stack  has no elements
bool Stack::empty() const { return (_size == 0); }

// Returns the number of stored elements
int Stack::size() const { return _size; }


// -----------
//  Modifiers
// -----------

// Appends the given element to the end of the stack
void Stack::push(const int& val) {
    if (_size == _capacity) {
        // Allocate new memory (double if needed, or assign 1 if no at all)
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        int* data = new int[_capacity];

        // Copy elements from the old stack to the new one
        for (int i = 0; i < _size; ++i) { data[i] = _data[i]; }

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = data;
    }

    // Insert the new value at the end
    _data[_size] = val;

    // Reflect new element on size
    ++_size;
}

// Removes the last element from the stack
void Stack::pop() {
    // Case: empty container
    if (_size == 0) { return; }

    // Reflect removed element on size
    --_size;

    // Avoid stale data
    _data[_size] = 0;
}

// Exchanges the contents of the stack with those of 'other'
void Stack::swap(Stack& other) {
    // Case: the same stack
    if (this == &other) { return; }

    int* tempData = _data;
    _data = other._data;
    other._data = tempData;

    int tempSize = _size;
    _size = other._size;
    other._size = tempSize;

    int tempCapacity = _capacity;
    _capacity = other._capacity;
    other._capacity = tempCapacity;
}