// Source file for simplified ADT: Dynamic Array
// by vezzolter
// January 31, 2024

#ifndef DA_CPP
#define DA_CPP

#include "DynamicArray.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
template<class T>
DA<T>::DA() : _size(0), _data(nullptr) {}

// Parameterized constructor, no range check
template<class T>
DA<T>::DA(int newSize, T newData) : _size(size) {
    // Allocate memory for new array
    _data = new T[size];

    // Fill with elements
    for (int i = 0; i < size; ++i) {
        _data[i] = newData;
    }
        
}

// Deep copy constructor
template<class T>
DA<T>::DA(const DA& rhs) : _size(rhs._size) {
    if (rhs._data) {
        // Allocate memory for new array
        _data = new T[_size];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            _data[i] = rhs._data[i];
    }
    else {
        _data = nullptr;
    }
        
}

// Deep copy assignment operator
template<class T>
DA<T>& DA<T>::operator=(const DA& rhs) {
    // Self-assignment guard
    if (this == &rhs)
        return *this;
        
    // Prevent memory leak
    delete[] _data;
    // Set corresponding size
    _size = rhs._size;

    if (rhs._data) {
        // Allocate memory for new array
        _data = new T[_size];

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
template<class T>
DA<T>::~DA() { delete[] _data; }


// --------------
// Element Access
// --------------

// Accesses the element at the specified index, no range check, allows modification
template<class T>
T& DA<T>::operator[](const int index) { return _data[index]; }

// Accesses the element at the specified index, no range check, denies modification
template<class T>
const T& DA<T>::operator[](const int index) const { return _data[index]; }

// Accesses the first element in the container, no range check, allows modification
template<class T>
T& DA<T>::front() { return _data[0]; }

// Accesses the first element in the container, no range check, denies modification
template<class T>
const T& DA<T>::front() const { return _data[0]; }

// Accesses the last element in the container, no range check, allows modification
template<class T>
T& DA<T>::back() { return _data[_size - 1]; }

// Accesses the last element in the container, no range check, denies modification
template<class T>
const T& DA<T>::back() const { return _data[_size - 1]; }



// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool DA<T>::empty() const { return (_size == 0); }

// Returns the number of elements in the container
template<class T>
int DA<T>::size() const { return _size; }



// ---------
// Modifiers
// ---------

// Appends the given element to the end of the container
// Note: without potential memory-reserving adjustments and bounds checking
template<class T>
void DA<T>::pushBack(const T& newData) {
    // Allocate memory for new array, one element more
    T* newArray = new T[_size + 1];

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
template<class T>
void DA<T>::insert(int index, const T& newData) {
    if (index == _size - 1) {
      pushBack(newData);
    }
    else {
        // Allocate memory for new array, one element more
        T* newArray = new T[_size + 1];

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
template<class T>
void DA<T>::remove(int index) {
    // Case: one element
    if (_size == 1) {
        clear();
        return;
    }

    // Allocate memory for new array, one element less
    T* newArray = new T[_size - 1];

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
template<class T>
void DA<T>::resize(int newSize) {
    // Case: already required size
    if (newSize <= _size) {
        return;
    }

    if (newSize > _size) {
        // Allocate memory for new array
        T* newArray = new T[newSize];

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
template<class T>
void DA<T>::clear() {
    delete[] _data; // dealloc
    _data = nullptr; // avoid dangling pointer
    _size = 0; // reflect change on the size
}


#endif