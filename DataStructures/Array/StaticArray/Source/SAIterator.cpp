// Title:   Source file for Static Array Iterator
// Authors: by vezzolter
// Date:    October 13, 2024
// ----------------------------------------------------------------------------


#include "SAIterator.h"


// --------------------
//  Compiler Generated 
// --------------------

// Initializes the iterator with specified memory address
SAIterator::SAIterator(int* ptr) : _ptr(ptr) { }


// ----------------------
//  Overloaded Operators
// ----------------------

// Returns a reference to the element pointed to by the iterator
int& SAIterator::operator*() { return *_ptr; }

// Advances the iterator to the next element and returns a reference to it
SAIterator& SAIterator::operator++() {
	++_ptr;
	return *this;
}

// Returns a copy of the iterator and then advances to the next element
SAIterator SAIterator::operator++(int) {
    SAIterator temp(*this); 
    ++_ptr;
    return temp; // could require disabling the RVO or using move cstr
}

// Moves the iterator to the previous element and returns a reference to it
SAIterator& SAIterator::operator--() {
	--_ptr;
	return *this;
}

// Returns a copy of the iterator and then moves to the previous element
SAIterator SAIterator::operator--(int) {
	SAIterator temp(*this);
	--_ptr;
	return temp; // could require disabling the RVO or using move cstr
}

// Returns true if two iterators point to the same element
bool operator==(const SAIterator& lhs, const SAIterator& rhs) {
	return lhs._ptr == rhs._ptr;
}

// Returns true if two iterators point to different elements
bool operator!=(const SAIterator& lhs, const SAIterator& rhs) {
	return lhs._ptr != rhs._ptr;
}