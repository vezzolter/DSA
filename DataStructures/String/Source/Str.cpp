// Title:   Source file for String
// Authors: by vezzolter
// Date:    November 28, 2024
// ----------------------------------------------------------------------------


#include "Str.h"


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty string
Str::Str() : _size(0), _capacity(0), _data(nullptr) {}

// Constructs a string from a C-style null-terminated string
Str::Str(const char* str) {
	// Case: empty
	if (!str) {
		_size = 0;
		_capacity = 0;
		_data = nullptr;
		return;
	}

	// Determine the size without null
	_size = 0;
	for (; str[_size] != '\0'; ) { ++_size; }
	
	// Allocate and copy
	_capacity = _size;
	_data = new char[_capacity];
	for (int i = 0; i < _size; ++i) { _data[i] = str[i]; }
}

// Constructs a string with the contents of 'other'
Str::Str(const Str& other)
	: _size(other._size), _capacity(other._capacity) {

	if (other._data) {
		_data = new char[_capacity];
		for (int i = 0; i < _size; ++i) { _data[i] = other._data[i]; }

	} else {
		_data = nullptr;
	}
}

// Replaces the contents with a copy of the contents of 'rhs'
Str& Str::operator=(const Str& rhs) {
	if (this == &rhs) { return *this; }
	delete[] _data;

	_size = rhs._size;
	_capacity = rhs._capacity;
	if (rhs._data) {
		_data = new char[_capacity];
		for (int i = 0; i < _size; ++i) { _data[i] = rhs._data[i]; }

	} else {
		_data = nullptr;
	}
}

// Destructs the string
Str::~Str() { delete[] _data; }



// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the string
Str::iterator Str::begin() { return Iterator(_data); }

// Returns an iterator to one past the last element of the string
Str::iterator Str::end() { return Iterator(_data + _size); }

// Returns a const iterator to the first element of the string
Str::const_iterator Str::begin() const { return ConstIterator(_data); }

// Returns a const iterator to one past the last element of the string
Str::const_iterator Str::end() const { return ConstIterator(_data + _size); }

// Explicitly returns a const iterator to the first element of the string
Str::const_iterator Str::cbegin() const { return ConstIterator(_data); }

// Explicitly returns a const iterator to one past the last element of the string
Str::const_iterator Str::cend() const { return ConstIterator(_data + _size); }


// ----------------
//  Element Access 
// ----------------

// Returns a modifiable reference to the element at the given position
char& Str::operator[](const int pos) { return _data[pos]; }

// Returns a non-modifiable reference to the element at the given position
const char& Str::operator[](const int pos) const { return _data[pos]; }

// Returns a modifiable reference to the first element
char& Str::front() { return _data[0]; }

// Returns a non-modifiable reference to the first element
const char& Str::front() const { return _data[0]; }

// Returns a modifiable reference to the last element
char& Str::back() { return _data[_size - 1]; }

// Returns a non-modifiable reference to the last element
const char& Str::back() const { return _data[_size - 1]; }

// Description
// void data();

// Description
// void c_str();


// ----------
//  Capacity
// ----------

// -----------
//  Modifiers
// -----------

// ------------
//  Operations
// ------------

// ---------------------
//  Numeric Conversions
// ---------------------


