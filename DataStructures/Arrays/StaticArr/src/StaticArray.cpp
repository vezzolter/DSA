// Source file for simplified ADT: Static Array
// by vezzolter
// January 29, 2024

#include "StaticArray.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
StaticArr::StaticArr() : mLength(0), mArr(nullptr) {}

// Parameterized constructor without bounds checking
StaticArr::StaticArr(int length) : mLength(length)
{
	if (length > 0) { mArr = new int[length]; }
	else { mArr = nullptr; }
}

// Destructor
StaticArr::~StaticArr() { delete[] mArr; }


// --------------
// Element Access
// --------------

// Access the element at the specified index without bounds checking
int& StaticArr::operator[](const int index) { return mArr[index]; }

// Access the first element of the container without bounds checking
int StaticArr::front() { return mArr[0]; }

// Access the last element of the container without bounds checking
int StaticArr::back() { return mArr[mLength - 1]; }



// --------
// Capacity
// --------

// Check if the container is empty
bool StaticArr::isEmpty() const { return (mLength == 0); }

// Get the size of the container
int StaticArr::size() const { return (isEmpty() ? 0 : mLength); }


// ----------
// Operations
// ----------

// Fill the container with specified value
void StaticArr::fill(const int val)
{
	for (int i = 0; i < mLength; ++i)
		mArr[i] = val;
}