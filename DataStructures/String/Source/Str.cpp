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

// Returns a pointer to the underlying character array
char* Str::data() { return _data; }

// Returns a pointer to the underlying character array (const version)
const char* Str::data() const { return _data; }


// ----------
//  Capacity
// ----------

// Returns true if string has no elements
bool Str::empty() const { return (_size == 0); }

// Returns the number of stored elements
int Str::size() const { return _size; }

// Returns the number of possible elements
int Str::capacity() const { return _capacity; }

// Reserves memory for new elements at least of given `capacity`
void Str::reserve(int capacity) {
	// Case: capacity is enough (for decreasing - shrinkToFit())
	if (capacity <= _capacity) { return; }

	char* data = new char[capacity];
	for (int i = 0; i <= _size; ++i) { data[i] = _data[i]; } // <= to include null-terminator

	delete[] _data;
	_data = data;
	_capacity = capacity;
}

// Requests the removal of unused capacity
void Str::shrinkToFit() {
	// Case: capacity is equal (for increasing - reserve())
	if (_capacity == _size + 1) { return; }

	char* data = new char[_size + 1];
	for (int i = 0; i <= _size; ++i) { data[i] = _data[i]; } // <= to include null-terminator

	delete[] _data;
	_data = data;
	_capacity = _size + 1; // to include null-terminator
}


// -----------
//  Modifiers
// -----------

// Inserts an element at the iterator position, shifting subsequent elements
void Str::insert(iterator pos, const char& val) {
    int index = pos - this->begin();

    // Ensure enough capacity for the new element and null-terminator
    if (_size + 1 >= _capacity) { reserve(_capacity == 0 ? 2 : _capacity * 2); }

    // Shifting from the beginning result in premature overwrite
    for (int i = _size; i > index; --i) { _data[i] = _data[i - 1]; }
    _data[index] = val;

    ++_size;
    _data[_size] = '\0';
}

// Removes an element at the iterator position, shifting subsequent elements to the left
void Str::erase(iterator pos) {
    // Case: one element
    if (_size == 1) {
        clear();
        return;
    }

    int index = pos - this->begin();
    for (int i = index; i < _size - 1; ++i) { _data[i] = _data[i + 1]; }

    --_size;
    _data[_size] = '\0';
}

// Appends the given element to the end of the string
void Str::pushBack(const char& val) {
    // 2 is to account for null and new element
    if (_size + 2 >= _capacity) { reserve(_capacity == 0 ? 2 : _capacity * 2); }

    _data[_size] = val;
    ++_size;
    _data[_size] = '\0';
}

// Removes the last element from the string
void Str::popBack() {
    // Case: empty container
    if (_size == 0) { return; }

    --_size;
    _data[_size] = '\0';
}

// Assigns the specified value to all elements
void Str::assign(int size, const char& val) {
    if (size + 1 > _capacity) { reserve(size + 1); }

    for (int i = 0; i < size; ++i) { _data[i] = val; }

    _size = size;
    _data[_size] = '\0';
}

// Assigns elements from the range [first, last) to the string
void Str::assign(Iterator first, Iterator last) {
    int size = 0;
    for (auto it = first; it != last; ++it) { ++size; }

    if (size + 1 > _capacity) { reserve(size + 1); }

    int index = 0;
    for (auto it = first; it != last; ++it) { _data[index++] = *it; }

    _size = size;
	_data[_size] = '\0';
}

// Erases all elements from the string, keeps the capacity unchanged
void Str::clear() {
    // Case: empty container
    if (_size == 0) { return; }

    _size = 0;
	_data[0] = '\0';
}


// ------------
//  Operations
// ------------

// ---------------------
//  Numeric Conversions
// ---------------------


