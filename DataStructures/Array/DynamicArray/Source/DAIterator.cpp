// Source file for Dynamic Array Iterator
// by vezzolter
// October 19, 2024


#include "DAIterator.h"


// --------------------
//  Compiler Generated 
// --------------------

// Parameterized constructor
DAIterator::DAIterator(int* ptr) : _ptr(ptr) { }



// ----------------------
//  Overloaded Operators
// ----------------------

// Dereference operator for accessing and modifying the element the iterator points to
int& DAIterator::operator*() {
    return *_ptr;
}

// Pre-increment operator to move the iterator to the next element
DAIterator& DAIterator::operator++() {
    ++_ptr;
    return *this;
}

// Post-increment operator to move the iterator to the next element, returning the previous state
DAIterator DAIterator::operator++(int) {
    DAIterator temp(*this);
    ++_ptr;
    return temp; // could require disabling the RVO or using move cstr
}

// Pre-decrement operator to move the iterator to the previous element
DAIterator& DAIterator::operator--() {
    --_ptr;
    return *this;
}

// Post-decrement operator to move the iterator to the previous element, returning the previous state
DAIterator DAIterator::operator--(int) {
    DAIterator temp(*this);
    --_ptr;
    return temp; // could require disabling the RVO or using move cstr
}

// Equality operator to check if two iterators point to the same element
bool operator==(const DAIterator& lhs, const DAIterator& rhs) {
    return lhs._ptr == rhs._ptr;
}

// Inequality operator to check if two iterators point to different elements
bool operator!=(const DAIterator& lhs, const DAIterator& rhs) {
    return lhs._ptr != rhs._ptr;
}