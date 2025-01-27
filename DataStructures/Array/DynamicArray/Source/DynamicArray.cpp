// Title:   Source file for Dynamic Array
// Authors: by vezzolter
// Date:    January 31, 2024
// ----------------------------------------------------------------------------


#include "DynamicArray.h"


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty array
DA::DA() : _size(0), _capacity(0), _data(nullptr) {}

// Constructs an array with 'size' copies of elements initialized to zeros
DA::DA(int size) : _size(size), _capacity(size), _data(new int[_capacity]) {
    for (int i = 0; i < _size; ++i) { _data[i] = 0; }
}

// Constructs an array with 'size' copies of elements with 'val'
DA::DA(int size, int val) : _size(size), _capacity(size), _data(new int[_capacity]) {
    for (int i = 0; i < _size; ++i) { _data[i] = val; }
}

// Constructs an array with the contents of 'other'
DA::DA(const DA& other) : _size(other._size), _capacity(other._capacity) {
    // Copy the data (if any), the size and capacity are in init list
    if (other._data) {
        _data = new int[_capacity];
        for (int i = 0; i < _size; ++i) { _data[i] = other._data[i]; }
    } else {
        _data = nullptr;
    }  
}

// Replaces the contents with a copy of the contents of 'rhs'
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

// Performs final cleanup and terminates the object
DA::~DA() { delete[] _data; }


// -----------
//  Iterators 
// -----------

// Returns an iterator to the first element of the array
DA::Iterator DA::begin() { return Iterator(_data); }

// Returns an iterator to one past the last element of the array
DA::Iterator DA::end() { return Iterator(_data + _size); }

// Returns a const iterator to the first element of the array
DA::const_iterator DA::begin() const { return ConstIterator(_data); }

// Returns a const iterator to one past the last element of the array
DA::const_iterator DA::end() const { return ConstIterator(_data + _size); }

// Explicitly returns a const iterator to the first element of the array
DA::ConstIterator DA::cbegin() const { return ConstIterator(_data); }

// Explicitly returns a const iterator to one past the last element of the array
DA::ConstIterator DA::cend() const { return ConstIterator(_data + _size); }


// ----------------
//  Element Access 
// ----------------

// Returns a modifiable reference to the element at the given position
int& DA::operator[](const int pos) { return _data[pos]; }

// Returns a non-modifiable reference to the element at the given position
const int& DA::operator[](const int pos) const { return _data[pos]; }

// Returns a modifiable reference to the first element
int& DA::front() { return _data[0]; }

// Returns a non-modifiable reference to the first element
const int& DA::front() const { return _data[0]; }

// Returns a modifiable reference to the last element
int& DA::back() { return _data[_size - 1]; }

// Returns a non-modifiable reference to the last element
const int& DA::back() const { return _data[_size - 1]; }


// ----------
//  Capacity
// ----------

// Returns true if array has no elements
bool DA::empty() const { return (_size == 0); }

// Returns the number of stored elements
int DA::size() const { return _size; }

// Returns the number of possible elements
int DA::capacity() const { return _capacity; }

// Reserves memory for new elements at least of given `capacity`
void DA::reserve(int capacity) {
    // Case: capacity is enough (for decreasing - shrinkToFit())
    if (capacity <= _capacity) { return; }

    // Allocate new memory with the requested capacity
    int* data = new int[capacity];

    // Copy existing elements to the new array
    for (int i = 0; i < _size; ++i) { data[i] = _data[i]; }

    // Deallocate old memory and point to new one
    delete[] _data;
    _data = data;

    // Update the capacity to the requested capacity
    _capacity = capacity;
}

// Requests the removal of unused capacity
void DA::shrinkToFit() {
    // Case: capacity is equal (for increasing - reserve())
    if (_capacity == _size) { return; }

    // Allocate new memory with the size equal to the current size
    int* data = new int[_size];

    // Copy existing elements to the new array
    for (int i = 0; i < _size; ++i) { data[i] = _data[i]; }

    // Deallocate old memory and point to new one
    delete[] _data;
    _data = data;

    // Update capacity to match the current size
    _capacity = _size;
}


// ------------
//  Operations
// ------------

// Inserts an element at the iterator position, shifting subsequent elements
void DA::insert(iterator pos, const int& val) {
    // Get the index out of itr
    int index = pos - this->begin();

    // If memory isn't enough - reallocate; otherwise shift within from the end
    if (_size == _capacity) {
        // Allocate new memory (double if needed, or assign 1 if no at all)
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        int* data = new int[_capacity];

        // Copy elements before the position, insert, copy elements after
        for (int i = 0; i < index; ++i) { data[i] = _data[i]; }
        data[index] = val;
        for (int i = index; i < _size; ++i) { data[i + 1] = _data[i]; }

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = data;

    } else {
        // Shifting from the beginning result in premature overwrite
        for (int i = _size; i > index; --i) { _data[i] = _data[i - 1]; }
        _data[index] = val;
    }

    // Reflect new element on size
    ++_size;
}

// Removes an element at the iterator position, shifting subsequent elements to the left
void DA::erase(iterator pos) {
    // Case: one element
    if (_size == 1) {
        clear();
        return;
    }
    
    // Get the index out of itr
    int index = pos - this->begin();

    // Shift elements to the left to fill the gap
    for (int i = index; i < _size - 1; ++i) { _data[i] = _data[i + 1]; }

    // Reflect removed element on size
    --_size;
}

// Appends the given element to the end of the array
void DA::pushBack(const int& val) {
    if (_size == _capacity) {
        // Allocate new memory (double if needed, or assign 1 if no at all)
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        int* data = new int[_capacity];

        // Copy elements from the old array to the new one
        for (int i = 0; i < _size; ++i) { data[i] = _data[i];}

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = data;
    }

    // Insert the new value at the end
    _data[_size] = val;

    // Reflect new element on size
    ++_size; 
}

// Removes the last element from the array
void DA::popBack() {
    // Case: empty container
    if (_size == 0) { return; }
    
    // Avoid stale data
    _data[_size] = 0;

    // Reflect removed element on size
    --_size;
}

// Assigns the specified value to all elements
void DA::assign(int size, const int& val) {
    // Ensure sufficient capacity for the requested size
    if (size > _capacity) { reserve(size); }

    // Fill all elements with the specified value
    for (int i = 0; i < size; ++i) { _data[i] = val; }

    // Match the requested size
    _size = size;
}

// Assigns elements from the range [first, last) to the array
void DA::assign(Iterator first, Iterator last) {
    // Calculate the number of elements in the range
    int newSize = 0;
    for (auto it = first; it != last; ++it) { ++newSize; }

    // Ensure sufficient capacity for the range
    if (newSize > _capacity) { reserve(newSize); }

    // Copy elements from the range into the array
    int index = 0;
    for (auto it = first; it != last; ++it) { _data[index++] = *it; }

    // Match the size to the number of elements in the range
    _size = newSize;
}

// Erases all elements from the array, keeps the capacity unchanged
void DA::clear() {
    // Case: empty container
    if (_size == 0) { return; }

    // Reflect removed elements on size
    _size = 0;
}

// Resizes the array to contain 'size' elements
void DA::resize(int size, const int& val) {
    // Case 1: new size is the same as current one
    if (size == _size) { return; }

    // Case 2: new size is smaller than current one 
    if (size < _size) {
        _size = size;
        return;
    }

    // Case 3: new size is larger and exceeds capacity; otherwise its within
    if (size > _capacity) {
        // Allocate new memory (assign given or double it)
        _capacity = size > _capacity * 2 ? size : _capacity * 2;
        int* data = new int[_capacity];

        // Copy existing elements
        for (int i = 0; i < _size; ++i) { data[i] = _data[i]; }

        // Initialize new elements
        for (int i = _size; i < size; ++i) { data[i] = val; }

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = data;

        // Update size to the new size
        _size = size;

    } else {
        // Capacity is sufficient, just default initialize new elements
        for (int i = _size; i < size; ++i) { _data[i] = val; }

        // Update size to the new size
        _size = size;
    }
}

// Exchanges the contents of the array with those of 'other'
void DA::swap(DA& other) {
    // Case: the same array
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