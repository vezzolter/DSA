// Title:   Source file for Splay Tree
// Authors: by vezzolter
// Date:    April 15, 2025
// ----------------------------------------------------------------------------


#include "SplayTree.h"


// -----------------
//  Utility Methods
// -----------------

// Implementation


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty SplayTree
SplayTree::SplayTree() {
	// Implementation
}

// Constructs a SplayTree with the deep copy contents of 'other'
SplayTree::SplayTree(const SplayTree& other) {
	// Implementation
}

// Replaces the contents of this SplayTree with a deep copy of 'rhs'
SplayTree& SplayTree::operator=(const SplayTree& rhs) {
	// Implementation
}

// Performs final cleanup and terminates the object
SplayTree::~SplayTree() {
	// Implementation
}


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the SplayTree
SplayTree::iterator SplayTree::begin() { }

// Returns an iterator to one past the last element of the SplayTree
SplayTree::iterator SplayTree::end() {  }

// Returns a const iterator to the first element of the SplayTree
SplayTree::const_iterator SplayTree::begin() const { }

// Returns a const iterator to one past the last element of the SplayTree
SplayTree::const_iterator SplayTree::end() const { }

// Explicitly returns a const iterator to the first element of the SplayTree
SplayTree::const_iterator SplayTree::cbegin() const { }

// Explicitly returns a const iterator to one past the last element of the SplayTree
SplayTree::const_iterator SplayTree::cend() const {  }


// ----------------
//  Element Access 
// ----------------

// Returns an iterator to the element with given value
SplayTree::iterator SplayTree::find(const int& val) {
	// Implementation
}

// Returns a const iterator to the element with given value
SplayTree::const_iterator SplayTree::find(const int& val) const {
	// Implementation
}

// Returns an iterator to the predecessor of the given value
SplayTree::iterator SplayTree::predecessor(const int& val) {
	// Implementation
}

// Returns a const_iterator to the predecessor of the given value
SplayTree::const_iterator SplayTree::predecessor(const int& val) const {
	// Implementation
}

// Returns an iterator to the successor of the given value
SplayTree::iterator SplayTree::successor(const int& val) {
	// Implementation
}

// Returns a const_iterator to the successor of the given value
SplayTree::const_iterator SplayTree::successor(const int& val) const {
	// Implementation
}

// Returns an iterator to the predecessor of the node pointed to by the given iterator
SplayTree::iterator SplayTree::predecessor(const iterator& it) {
	// Implementation
}

// Returns a const_iterator to the predecessor of the node pointed to by the given iterator
SplayTree::const_iterator SplayTree::predecessor(iterator& it) const {
	// Implementation
}

// Returns an iterator to the successor of the node pointed to by the given iterator
SplayTree::iterator SplayTree::successor(const iterator& it) {
	// Implementation
}

// Returns a const_iterator to the successor of the node pointed to by the given iterator
SplayTree::const_iterator SplayTree::successor(iterator& it) const {
	// Implementation
}

// Returns the minimum value in the tree
int SplayTree::minimum() const {
	// Implementation
}

// Returns the maximum value in the tree
int SplayTree::maximum() const {
	// Implementation
}


// ----------
//  Capacity
// ----------

// Returns true if the tree has no elements
bool SplayTree::empty() const {
	// Implementation
}

// Returns the total number of elements in the tree
int SplayTree::size() const {
	// Implementation
}

// Returns the height of the entire tree
int SplayTree::height() const {
	// Implementation
}

// Returns the height of the subtree rooted at the given value
int SplayTree::height(const int& val) const {
	// Implementation
}

// Returns the height of the subtree rooted at the given iterator
int SplayTree::height(const iterator& it) const {
	// Implementation
}

// Returns the depth of the entire tree
int SplayTree::depth() const {
	// Implementation
}

// Returns the depth of the node with the given value
int SplayTree::depth(const int& val) const {
	// Implementation
}

// Returns the depth of the node given an iterator
int SplayTree::depth(const iterator& it) const {
	// Implementation
}


// -----------
//  Modifiers
// -----------

// Inserts a new element into the SplayTree, maintaining ordering and balance 
void SplayTree::insert(const int& val) {
	// Implementation
}

// Removes a node with the given value from the SplayTree, maintaining order and balance
void SplayTree::remove(const int& val) {
	// Implementation
}

// Removes all nodes from the tree and resets it to an empty state
void SplayTree::clear() {
	// Implementation
}

// Exchanges the contents of this SplayTree with another SplayTree
void SplayTree::swap(SplayTree& other) {
	// Implementation
}