// Title:   Source file for String
// Authors: by vezzolter
// Date:    November 28, 2024
// ----------------------------------------------------------------------------


#include "Str.h"


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty string
Str::Str() : _size(0), _capacity(1), _data(nullptr) {
	_data = new char[_capacity];
	_data[_size] = '\0';
}

// Constructs a string from a C-style null-terminated string
Str::Str(const char* str) {
	// Case: empty
	if (!str) {
		_size = 0;
		_capacity = 1;
		_data = new char[_capacity];
		_data[_size] = '\0';
		return;
	}

	// Determine the size
	_size = 0;
	for (; str[_size] != '\0'; ) { ++_size; }
	
	// Allocate and copy
	_capacity = _size + 1;
	_data = new char[_capacity];
	for (int i = 0; i < _size; ++i) { _data[i] = str[i]; }
	_data[_size] = '\0';
}

// Constructs a string with the contents of 'other'
Str::Str(const Str& other)
	: _size(other._size), _capacity(other._capacity) {

	_data = new char[_capacity];
	if (other._data) {
		for (int i = 0; i < _size; ++i) { _data[i] = other._data[i]; }
	}
	_data[_size] = '\0';
}

// Replaces the contents with a copy of the contents of 'rhs'
Str& Str::operator=(const Str& rhs) {
	if (this == &rhs) { return *this; }
	delete[] _data;

	_size = rhs._size;
	_capacity = rhs._capacity;
	_data = new char[_capacity];
	if (rhs._data) {
		for (int i = 0; i < _size; ++i) { _data[i] = rhs._data[i]; }
	}
	_data[_size] = '\0';
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

//// Returns a pointer to the underlying character array
//char* Str::data() { return _data; }

//// Returns a pointer to the underlying character array (const version)
//const char* Str::data() const { return _data; }


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


