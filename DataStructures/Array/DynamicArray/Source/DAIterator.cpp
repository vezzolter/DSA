// Title:   Source file for Dynamic Array Iterator
// Authors: by vezzolter
// Date:    October 19, 2024
// ----------------------------------------------------------------------------


#include "DAIterator.h"


// --------------------
//  Compiler Generated 
// --------------------

// Initializes the iterator to point to the specified memory address
DAIterator::DAIterator(int* ptr) : _ptr(ptr) { }


// ----------------------
//  Overloaded Operators
// ----------------------

// Returns a reference to the element pointed to by the iterator
int& DAIterator::operator*() { return *_ptr; }

// Advances the iterator to the next element (pre-increment)
DAIterator& DAIterator::operator++() {
    ++_ptr;
    return *this;
}

// Advances the iterator to the next element, returning the previous state
DAIterator DAIterator::operator++(int) {
    DAIterator temp(*this);
    ++_ptr;
    return temp; // could require disabling the RVO or using move cstr
}

// Moves the iterator to the previous element (pre-decrement)
DAIterator& DAIterator::operator--() {
    --_ptr;
    return *this;
}

// Moves the iterator to the previous element, returning the previous state
DAIterator DAIterator::operator--(int) {
    DAIterator temp(*this);
    --_ptr;
    return temp; // could require disabling the RVO or using move cstr
}

// Returns true if two iterators point to the same element
bool operator==(const DAIterator& lhs, const DAIterator& rhs) {
    return lhs._ptr == rhs._ptr;
}

// Returns true if two iterators point to different elements
bool operator!=(const DAIterator& lhs, const DAIterator& rhs) {
    return lhs._ptr != rhs._ptr;
}