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

	// Recursively copy both subtrees
	newNode->_left = copyNodes(src->_left, newNode);
	newNode->_right = copyNodes(src->_right, newNode);

	return newNode;
}


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty BST
BST::BST() : _size(0), _root(nullptr) {}

// Constructs a BST with the deep copy contents of 'other'
//BST::BST(const BST& other) 
//	: _size(other._size), _root(nullptr) {
//
//	// Case: empty tree
//	if (!other._root) {
//
//	}
//
//	for (auto it = other.begin(); it != other.end(); ++it) {
//		insert(*it);
//	}
//}

// Replaces the contents of this BST with a deep copy of 'rhs'
//BST& BST::operator=(const BST& rhs) { }

// Destroys the BST, resetting it to its initial state
BST::~BST() { clear(); }


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the string
//BST::iterator BST::begin() { }

// Returns an iterator to one past the last element of the string
//BST::iterator BST::end() { }

// Returns a const iterator to the first element of the string
//BST::const_iterator BST::begin() const { }

// Returns a const iterator to one past the last element of the string
//BST::const_iterator BST::end() const { }

// Explicitly returns a const iterator to the first element of the string
//BST::const_iterator BST::cbegin() const { }

// Explicitly returns a const iterator to one past the last element of the string
//BST::const_iterator BST::cend() const { }


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

// Description
//void BST::insert(const int& val) { }

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