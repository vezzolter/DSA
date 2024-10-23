// Source file for Dynamic Array
// by vezzolter
// January 31, 2024


#include "DynamicArray.h"


// --------------------
//  Compiler Generated
// --------------------

// Default constructor
DA::DA() : _size(0), _capacity(0), _data(nullptr) {}


// Parameterized constructor to fill the array with the default values
DA::DA(int size)
    : _size(size), _capacity(size), _data(new int[_capacity]) {
    for (int i = 0; i < _size; ++i) { _data[i] = 0; }
}

// Parameterized constructor to fill the array with the given value
DA::DA(int size, int data)
    : _size(size), _capacity(size), _data(new int[_capacity]) {
    for (int i = 0; i < _size; ++i) { _data[i] = data; }
}

//// Parameterized constructor to fill the array with the given list
//DA::DA(std::initializer_list<int> list)
//    : _size(list.size()), _capacity(list.size()), _data(new int[_capacity]) {
//    int i = 0;
//    for (const int& val : list) {
//        _data[i++] = val;
//    }
//}

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

//// Accesses the element at the specified position, allows modification
//int& DA::at()(const int pos) {
//    //TODO: Range check
//    return _data[pos];
//}
//
//// Accesses the element at the specified pos, denies modification
//const int& DA::at()(const int pos) const {
//    //TODO: Range check
//    return _data[pos];
//}

// Accesses the element at the specified position, allows modification
int& DA::operator[](const int pos) { return _data[pos]; }

// Accesses the element at the specified pos, denies modification
const int& DA::operator[](const int pos) const { return _data[pos]; }

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

// Reserves memory for elements at least of given capacity
void DA::reserve(int cap) {
    // Case: capacity is enough (for decreasing - shrinkToFit())
    if (cap <= _capacity) { return; }

    // Allocate new memory with the requested capacity
    int* data = new int[cap];

    // Copy existing elements to the new array
    for (int i = 0; i < _size; ++i) { data[i] = _data[i]; }

    // Deallocate old memory and point to new one
    delete[] _data;
    _data = data;

    // Update the capacity to the requested capacity
    _capacity = cap;
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

// Inserts element at given position, shifting other elements as needed
void DA::insert(int pos, const int& val) {
    // If memory isn't enough - reallocate; Otherwise shift within from the end
    if (_size == _capacity) {
        // Allocate new memory (double if needed, or assign 1 if no at all)
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        int* data = new int[_capacity];

        // Copy elements before the position, insert, copy elements after
        for (int i = 0; i < pos; ++i) { data[i] = _data[i]; }
        data[pos] = val;
        for (int i = pos; i < _size; ++i) { data[i + 1] = _data[i]; }

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = data;
    } else {
        // Shifting from the beginning result in premature overwrite
        for (int i = _size; i > pos; --i) { _data[i] = _data[i - 1]; }
        _data[pos] = val;
    }

    // Reflect new element on size
    ++_size; 
}

// Appends the given element to the end of the container
void DA::pushBack(const int& data) {
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
    _data[_size] = data;

    // Reflect new element on size
    ++_size; 
}

// Removes the last element from the array
void DA::popBack() {
    // Case: empty container
    if (_size == 0) { return; }

    // TODO: Invalidate iterators pointing to element
    // TODO: Call the destructor for each element
    
    // Avoid stale data
    _data[_size] = 0;

    // Reflect removed element on size
    --_size;
}

// Removes an element at the specified position
void DA::erase(int pos) {
    // Case: one element
    if (_size == 1) {
        clear();
        return;
    }

    // Shift elements to the left to fill the gap
    for (int i = pos; i < _size - 1; ++i) { _data[i] = _data[i + 1]; }

    // Reflect removed element on size
    --_size;
}

// Assigns the specified value to all elements in the array
void DA::assign(int val) {
    for (int i = 0; i < _size; ++i) { _data[i] = val; }
}

// Removes all the elements, doesn't touch the capacity (thus memory)
void DA::clear() {
    // Case: empty container
    if (_size == 0) { return; }

    // TODO: Invalidate iterators pointing to elements
    // TODO: Call the destructor for each element

    // Reflect removed elements on size
    _size = 0;
}

// Changes the size of an array exactly to the given
void DA::resize(int size) {
    // Case 1: new size is the same as current one
    if (size == _size) { return; }

    // Case 2: new size is smaller than current one 
    if (size < _size) {
        _size = size;
        return;
    }

    // Case 3: new size is larger and exceeds capacity; Otherwise its within
    if (size > _capacity) {
        // Allocate new memory (assign given or double it)
        _capacity = size > _capacity * 2 ? size : _capacity * 2;
        int* data = new int[_capacity];

        // Copy existing elements
        for (int i = 0; i < _size; ++i) { data[i] = _data[i]; }

        // Default initialize new elements to 0
        for (int i = _size; i < size; ++i) { data[i] = 0; }

        // Deallocate old memory and point to new one
        delete[] _data;
        _data = data;

        // Update size to the new size
        _size = size;
    }
    else {
        // Capacity is sufficient, just default initialize new elements
        for (int i = _size; i < size; ++i) { _data[i] = 0; }

        // Update size to the new size
        _size = size;
    }
}

// Swaps the data, size, capacity of this array with another array
void DA::swap(DA& other) {
    // Case: the same container
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