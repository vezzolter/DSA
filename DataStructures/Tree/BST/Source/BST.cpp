// Title:   Source file for BST
// Authors: by vezzolter
// Date:    April 29, 2024
// ----------------------------------------------------------------------------


#include "BST.h"


// --------------------
//  Compiler Generated
// --------------------

// Description
BST::BST() : _root(nullptr), _size(0) { }

// Description
BST::BST(const BST& rhs) : _root(nullptr), _size(rhs._size) { }

// Description
BST& BST::operator=(const BST& rhs) { }

// Description
BST::~BST() { }


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the string
BST::iterator BST::begin() { }

// Returns an iterator to one past the last element of the string
BST::iterator BST::end() { }

// Returns a const iterator to the first element of the string
BST::const_iterator BST::begin() const { }

// Returns a const iterator to one past the last element of the string
BST::const_iterator BST::end() const { }

// Explicitly returns a const iterator to the first element of the string
BST::const_iterator BST::cbegin() const { }

// Explicitly returns a const iterator to one past the last element of the string
BST::const_iterator BST::cend() const { }


// ----------------
//  Element Access 
// ----------------

// Description
BST::iterator BST::find(const int& val) { } 

// Description
BST::const_iterator BST::find(const int& val) const { }

// Description
int BST::maximum() const { }

// Description
int BST::minimum() const { }

// Description
BST::iterator BST::predecessor(const int& val)  { }

// Description
BST::const_iterator BST::predecessor(const int& val) const { }

// Description
BST::iterator BST::successor(const int& val) { }

// Description
BST::const_iterator BST::successor(const int& val) const { }


// ----------
//  Capacity
// ----------

// Description
bool BST::empty() const { }

// Description
int BST::size() const { }

// Description
int BST::height(const int& val) const { }

// Description
int BST::depth(const int& val) const { }


// -----------
//  Modifiers
// -----------

// Description
void BST::insert(const int& val) { }

// Description
void BST::remove(const int& val) { }

// Description
void BST::clear() { }

// Description
void BST::swap(BST& other) { }


// ------------
//  Operations
// ------------

// Description
// void traverse() { }

// Description
// bool contains(const int& val) const { }

// Description
//void validate() const { }

// Description
//int count(const int& val) const { }