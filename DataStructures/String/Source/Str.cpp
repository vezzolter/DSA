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

// Resizes the string to contain 'size' elements
void Str::resize(int size, const char& val) {
    // Case 1: new size is the same as current one
    if (size == _size) { return; }

    // Case 2: new size is smaller than current one 
    if (size < _size) {
        _size = size;
        _data[_size] = '\0';
        return;
    }

    if (size + 1 > _capacity) { reserve(size + 1); }
    for (int i = _size; i < size; ++i) { _data[i] = val; }

    _size = size;
    _data[_size] = '\0';
}

// Exchanges the contents of the string with those of 'other'
void Str::swap(Str& other) {
    // Case: the same string
    if (this == &other) { return; }

    char* data = _data;
    _data = other._data;
    other._data = data;

    int size = _size;
    _size = other._size;
    other._size = size;

    int capacity = _capacity;
    _capacity = other._capacity;
    other._capacity = capacity;
}

// ------------
//  Operations
// ------------

// Finds the first occurrence of the substring starting from `start`
int Str::find(const char* str, int start) const {
    // Case: invalid range (aligns with the logic and no exceptions decision)
    if (start < 0 || start >= _size) { return -1; }

    int strLen = 0;
    for (; str[strLen] != '\0'; ) { ++strLen; }

    for (int i = start; i <= _size - strLen; ++i) {
        bool match = true;
        for (int j = 0; j < strLen; ++j) {
            if (_data[i + j] != str[j]) {
                match = false;
                break;
            }
        }
        if (match) { return i; }
    }

    return -1;
}

// Finds the first occurrence of the character starting from `start`
int Str::find(char c, int start) const {
    // Case: invalid range (aligns with the logic and no exceptions decision)
    if (start < 0 || start >= _size) { return -1; }

    for (int i = start; i < _size; ++i) { 
        if (_data[i] == c) { return i; }
    }

    return -1;
}

// Compares the current string with another string
int Str::compare(const Str& other) const {
    int minLength = (_size < other._size) ? _size : other._size;

    // Compare characters one by one
    for (int i = 0; i < minLength; ++i) {
        if (_data[i] < other._data[i]) { return -1; } // lexicographically smaller
        if (_data[i] > other._data[i]) { return 1; } // lexicographically greater
    }

    // If all characters are equal, compare lengths
    if (_size < other._size) { return -1; } // shorter
    if (_size > other._size) { return 1; } // lomger

    return 0; // equal
}


//// Returns a substring starting from `start` with the specified `length`
//Str Str::substr(int start, int length) const {
//    // Adjust length if it exceeds the remaining size
//    if (start + length > _size) { length = _size - start; }
//
//    // Create a new Str object with enough capacity for substr and null
//    Str result;
//    result.reserve(length + 1);
//
//    // Copy characters from the original string to the new one
//    for (int i = 0; i < length; ++i) { result._data[i] = _data[start + i]; }
//
//    // Update the size and null-terminate the new string
//    result._size = length;
//    result._data[length] = '\0';
//
//    return result; // requires disabling the RVO, or enabling move cstr
//}


// ---------------------
//  Numeric Conversions
// ---------------------

// Converts the string to an integer, to -1 if an error occurs
int Str::toInt() const {
    int ans = 0;
    int sign = 1; // most numbers are positive unless explicitly indicated
    int i = 0; // string traversing

    // Case: empty string
    if (_size == 0) { return -1; }

    // Skipping leading whitespace allows to properly detect sign
    for (; i < _size && (_data[i] == ' ' || _data[i] == '\t'); ++i) { }

    // Handle sign
    if (i < _size && _data[i] == '-') {
        sign = -1;
        ++i;

    } else if (i < _size && _data[i] == '+') {
        ++i;
    }

    // Parse digits
    for (; i < _size; ++i) {
        // Invalid chars (often implementations still parse the string)
        if (_data[i] < '0' || _data[i] > '9') { 
            if (_data[i] == ' ' || _data[i] == '\t') { continue; } // internal and trailing whitespaces
            return -1; 
        }

        // by subtracting '0' we get the distance from '0' in ASCII table, i.e. digit
        // e.g. '5' - '0' = 53 - 48 = 5
        int digit = _data[i] - '0';

        // Case: overflow (32-bit signed int) check from inequality of 'ans * 10 + digit <= INT_MAX'
        if (ans > (2147483647 - digit) / 10) { return -1; }

        // shift to the left, add new digit to build the int incrementally
        // e.g. "123", ans 0
        // 1: 0 * 10 + 1 = 1
        // 2: 1 * 10 + 2 = 12
        // 3: 12 * 10 + 3 = 123
        ans = ans * 10 + digit;
    }

    return ans * sign; // apply the sign
}

// Converts the string to a double, returns -1.0 on failure
double Str::toDouble() const {
    double ans = 0.0;
    int sign = 1; // most numbers are positive unless explicitly indicated
    int i = 0; // string traversing
    double fraction = 0.0;
    bool hasFraction = false; // marker to indicate start of fraction
    double fractionDivider = 10.0; // allows to shift fractional digits

    // Case: empty string
    if (_size == 0) { return -1.0; }

    // Skipping leading whitespace allows to properly detect sign
    for (; i < _size && (_data[i] == ' ' || _data[i] == '\t'); ++i) {}

    // Handle sign
    if (i < _size && _data[i] == '-') {
        sign = -1;
        ++i;

    } else if (i < _size && _data[i] == '+') {
        ++i;
    }

    // Parse digits
    for (; i < _size; ++i) {
        if (_data[i] >= '0' && _data[i] <= '9') {
            if (hasFraction) {
                // by subtracting '0' we get the distance from '0' in ASCII table, i.e. digit
                // e.g. '5' - '0' = 53 - 48 = 5
                // by dividing we shift digit to its correct place, and account it for next digit
                // e.g. '3' in '12.3' is divided by '10.0' to represent '0.3'
                fraction += (_data[i] - '0') / fractionDivider;
                fractionDivider *= 10.0;

            } else {
                // shift to the left, add new digit to build the int incrementally
                // e.g. "123", ans 0.0
                // 1: 0.0 * 10.0 + 1 = 1.0
                // 2: 1.0 * 10.0 + 2 = 12.0
                // 3: 12.0 * 10.0 + 3 = 123.0
                ans = ans * 10.0 + (_data[i] - '0');
            }

        // First dot means start of the fraction part
        } else if (_data[i] == '.' && !hasFraction) {
            hasFraction = true;

        // Skip trailing whitespace (internal are handled within digit check)
        } else if (_data[i] == ' ' || _data[i] == '\t') {
            continue;

        // Invalid chars (often implementations still parse the string)
        } else {
            return -1.0;
        }
    }

    ans += fraction; // combine int and fractional parts
    return ans * sign; // apply the sign
}