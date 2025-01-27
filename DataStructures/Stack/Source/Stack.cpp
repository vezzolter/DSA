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
Stack::Stack(const Stack& other) : _size(other._size), _capacity(other._capacity) {
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

// Performs final cleanup and terminates the object
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

// Returns true if stack has no elements
bool Stack::empty() const { return (_size == 0); }

// Returns the number of stored elements
int Stack::size() const { return _size; }


// -----------
//  Modifiers
// -----------

// Appends the given element to the end of the stack
void Stack::push(const int& val) {
    // Moving out memory handling to a separate reserve() is unnecessary for the stack,
    // as resizing is only required in push(), and it would add an extra layer without benefit
    if (_size == _capacity) {
        // Allocate new memory (double if needed, or assign 1 if no at all)
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        int* data = new int[_capacity];

        // Copy elements
        for (int i = 0; i < _size; ++i) { data[i] = _data[i]; }

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = data;
    }

    // Insert new element and reflect on size
    _data[_size] = val;
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

    int* data = _data;
    _data = other._data;
    other._data = data;

    int size = _size;
    _size = other._size;
    other._size = size;

    int capacity = _capacity;
    _capacity = other._capacity;
    other._capacity = capacity;
}