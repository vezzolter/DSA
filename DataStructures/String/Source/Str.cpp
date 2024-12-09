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

// ----------------
//  Element Access
// ----------------

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


