// Title:   Source file for BST
// Authors: by vezzolter
// Date:    April 29, 2024
// ----------------------------------------------------------------------------


#include "BST.h"


// -----------------
//  Utility Methods
// -----------------

// Recursively copies nodes with relationships from 'src' into a new tree
BST::Node* BST::copyNodes(Node* src, Node* parent) {
	// Case: node is empty
	if (!src) { return nullptr; }

	// Create new node with the same val as src and same parent
	Node* newNode = new Node(src->_data);
	newNode->_parent = parent;

	// Recursively copy both subtrees (post-order traversal)
	newNode->_left = copyNodes(src->_left, newNode);
	newNode->_right = copyNodes(src->_right, newNode);

	return newNode;
}

// Find the leftmost node starting from the given node (begin)
BST::Node* BST::findLeftmost(Node* node) const {
	// Traverse until its not empty and there is a left child
	for (; node && node->_left; ) { node = node->_left; }
	return node;
}


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty BST
BST::BST() : _size(0), _root(nullptr) {}

// Constructs a BST with the deep copy contents of 'other'
BST::BST(const BST& other) : _size(other._size), _root(nullptr) {
	// Case: empty tree
	if (!other._root) { return; }

	// Delegate actual copy to utility function
	_root = copyNodes(other._root, nullptr);
}

// Replaces the contents of this BST with a deep copy of 'rhs'
BST& BST::operator=(const BST& rhs) {
	// Prepare: self-assignment & deallocate any old memory
	if (this == &rhs) { return *this; }
	clear();

	// Set corresponding size
	_size = rhs._size;

	// Case: empty tree
	if (!rhs._root) {
		_root = nullptr;
		return *this;
	}

	// Delegate actual copy to utility function
	_root = copyNodes(rhs._root, nullptr);

	return *this;
}

// Destroys the BST, resetting it to its initial state
BST::~BST() { clear(); }


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the BST
//BST::iterator BST::begin() { }

// Returns an iterator to one past the last element of the BST
//BST::iterator BST::end() { }

// Returns a const iterator to the first element of the BST
//BST::const_iterator BST::begin() const { }

// Returns a const iterator to one past the last element of the BST
//BST::const_iterator BST::end() const { }

// Explicitly returns a const iterator to the first element of the BST
BST::const_iterator BST::cbegin() const { return const_iterator(findLeftmost(_root), this); }

// Explicitly returns a const iterator to one past the last element of the BST
BST::const_iterator BST::cend() const { return const_iterator(nullptr, this); }


// ----------------
//  Element Access 
// ----------------

// Description
//BST::iterator BST::find(const int& val) { } 

// Description
//BST::const_iterator BST::find(const int& val) const { }

// Description
//int BST::maximum() const { }

// Description
//int BST::minimum() const { }

// Description
//BST::iterator BST::predecessor(const int& val)  { }

// Description
//BST::const_iterator BST::predecessor(const int& val) const { }

// Description
//BST::iterator BST::successor(const int& val) { }

// Description
//BST::const_iterator BST::successor(const int& val) const { }


// ----------
//  Capacity
// ----------

// Description
//bool BST::empty() const { }

// Description
//int BST::size() const { }

// Description
//int BST::height(const int& val) const { }

// Description
//int BST::depth(const int& val) const { }


// -----------
//  Modifiers
// -----------

// Inserts a new element into the BST, maintaining BST ordering (not balancing)
void BST::insert(const int& val) {
	Node* parent = nullptr; // keep track of parent during traversal and helps to insert

	// Traverse to ifnd the insertion point
	for (Node* curr = _root; curr; ) {
		parent = curr;

		if (val < curr->_data) {
			curr = curr->_left;
		} else if (val > curr->_data) {
			curr = curr->_right;
		} else {
			curr->_count++;
			return;
		}
	}

	// Create new node and place it in appropriate spot
	Node* newNode = new Node(val, parent);
	if (!parent) {
		_root = newNode;
	} else if (val < parent->_data) {
		parent->_left = newNode;
	} else {
		parent->_right = newNode;
	}

	// Reflect new element on size
	++_size;
}

// Description
//void BST::remove(const int& val) { }

// Removes all nodes from the BST, resetting it to its initial state
void BST::clear() {
	// Lamda keeps the logic local, preventing mess
	auto deleteNodes = [](Node* node, auto& deleteNodesRef) -> void {
		// Case: empty node
		if (!node) { return; }

		// Recursively delete all nodes in the left and right subtrees (post-order)
		deleteNodesRef(node->_left, deleteNodesRef);
		deleteNodesRef(node->_right, deleteNodesRef);

		// Deletion itself
		delete node;
	};

	// Start recursive deletion from the root via lambda
	deleteNodes(_root, deleteNodes); 

	// Reset the tree to an empty state
	_root = nullptr;
	_size = 0;
}

// Description
//void BST::swap(BST& other) { }


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