// Source file Static Array Iterator
// by vezzolter
// October 13, 2024


#include "SAIterator.h"


// --------------------
//  Compiler Generated 
// --------------------

// Parameterized Constructor
SAIterator::SAIterator(int* ptr) : _ptr(ptr) { }

// Copy constructor
SAIterator::SAIterator(const SAIterator& rhs) : _ptr(rhs._ptr) { }


// ----------------------
//  Overloaded Operators
// ----------------------

// Dereference operator for accessing and modifying the element the iterator points to
int& SAIterator::operator*() { return *_ptr; }

// Dereference operator for accessing the element the iterator points to in read-only mode
const int& SAIterator::operator*() const { return *_ptr; }

// Pre-increment operator to move the iterator to the next element
SAIterator& SAIterator::operator++() {
	++_ptr;
	return *this;
}

//// Post-increment operator to move the iterator to the next element, returning the previous state
//SAIterator SAIterator::operator++(int) {
//    SAIterator temp(*this); 
//    ++_ptr;
//    return temp; // could require disabling the RVO or using move cstr
//}

// Pre-decrement operator to move the iterator to the previous element
SAIterator& SAIterator::operator--() {
	--_ptr;
	return *this;
}

//// Post-decrement operator to move the iterator to the previous element, returning the previous state
//SAIterator SAIterator::operator--(int) {
//	SAIterator temp(*this);
//	--_ptr;
//	return temp; // could require disabling the RVO or using move cstr
//}

// Equality operator to check if two iterators point to the same element
bool operator==(const SAIterator& lhs, const SAIterator& rhs) {
	return lhs._ptr == rhs._ptr;
}

// Inequality operator to check if two iterators point to different elements
bool operator!=(const SAIterator& lhs, const SAIterator& rhs) {
	return lhs._ptr != rhs._ptr;
}