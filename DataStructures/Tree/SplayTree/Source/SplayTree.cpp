// Title:   Source file for Splay Tree
// Authors: by vezzolter
// Date:    April 15, 2025
// ----------------------------------------------------------------------------


#include "SplayTree.h"


// -----------------
//  Utility Methods
// -----------------

// Recursively creates a deep copy of a subtree
SplayTree::Node* SplayTree::copySubtree(Node* src, Node* parent) {
	if (!src) { return nullptr; }
	Node* newNode = new Node(src->data);
	newNode->parent = parent;
	newNode->left = copySubtree(src->left, newNode);
	newNode->right = copySubtree(src->right, newNode);
	return newNode;
}

// Recursively deletes all nodes in a subtree
void SplayTree::destroySubtree(Node* node) {
	if (!node) { return; }
	destroySubtree(node->left);
	destroySubtree(node->right);
	delete node;
}

// Find the leftmost node starting from the given node (the smallest)
SplayTree::Node* SplayTree::findLeftmost(Node* node) const {
	if (!node) { return nullptr; }
	for (; node && node->left; ) { node = node->left; }
	return node;
}

// Find the rightmost node starting from the given node (the biggest)
SplayTree::Node* SplayTree::findRightmost(Node* node) const {
	if (!node) { return nullptr; }
	for (; node && node->right; ) { node = node->right; }
	return node;
}



// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty SplayTree
SplayTree::SplayTree() : _size(0), _root(nullptr) {}

// Constructs a SplayTree with the deep copy contents of 'other'
SplayTree::SplayTree(const SplayTree& other) : _size(other._size), _root(copySubtree(other._root, nullptr)) {}

// Replaces the contents of this SplayTree with a deep copy of 'rhs'
SplayTree& SplayTree::operator=(const SplayTree& rhs) {
	if (this == &rhs) { return *this; }
	clear();
	_size = rhs._size;
	_root = copySubtree(rhs._root, nullptr);
	return *this;
}

// Performs final cleanup and terminates the object
SplayTree::~SplayTree() {
	clear();
}


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the SplayTree
SplayTree::iterator SplayTree::begin() { return iterator(Iterator::findLeftmost(_root)); }

// Returns an iterator to one past the last element of the SplayTree
SplayTree::iterator SplayTree::end() { return iterator(nullptr); }

// Returns a const iterator to the first element of the SplayTree
SplayTree::const_iterator SplayTree::begin() const { return const_iterator(ConstIterator::findLeftmost(_root)); }

// Returns a const iterator to one past the last element of the SplayTree
SplayTree::const_iterator SplayTree::end() const { return const_iterator(nullptr); }

// Explicitly returns a const iterator to the first element of the SplayTree
SplayTree::const_iterator SplayTree::cbegin() const { return const_iterator(ConstIterator::findLeftmost(_root)); }

// Explicitly returns a const iterator to one past the last element of the SplayTree
SplayTree::const_iterator SplayTree::cend() const { return const_iterator(nullptr); }


// ----------------
//  Element Access 
// ----------------

// Returns an iterator to the element with given value
SplayTree::iterator SplayTree::find(const int& val) {
	for (Node* curr = _root; curr; ) {
		if (val > curr->data) {
			curr = curr->right;
		} else if (val < curr->data) {
			curr = curr->left;
		} else {
			// splay(curr);
			return iterator(curr);
		}
	}

	return end();
}

// Returns an iterator to the predecessor of the given value
SplayTree::iterator SplayTree::predecessor(const int& val) {
	Node* pred = nullptr;

	for (Node* curr = _root; curr; ) {
		if (val > curr->data) {
			pred = curr;
			curr = curr->right;
		} else {
			curr = curr->left;
		}
	}

	if (pred) {
		// splay(pred);
		return iterator(pred);
	}

	return end();
}

// Returns an iterator to the predecessor of the node pointed to by the given iterator
SplayTree::iterator SplayTree::predecessor(iterator& it) {
	Node* curr = it._curr;
	if (!curr) { return end(); }

	// Case 1: if the 'given' has a left subtree, 'prev' is the rightmost node in that subtree
	if (curr->left) {
		Node* pred = curr->left;
		for (; pred->right; ) { pred = pred->right; }
		// splay(pred);
		return iterator(pred);
	}

	// Case 2: otherwise 'prev' is the first parent node, where the 'given' is in the right subtree
	Node* parent = curr->parent;
	for (; parent && curr == parent->left; ) {
		curr = parent;
		parent = parent->parent;
	}
	
	if (parent) {
		// splay(parent);
		return iterator(parent);
	}

	return end();
}

// Returns an iterator to the successor of the given value
SplayTree::iterator SplayTree::successor(const int& val) {
	Node* succ = nullptr;

	for (Node* curr = _root; curr; ) {
		if (val < curr->data) {
			succ = curr;
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}

	if (succ) {
		// splay(succ);
		return iterator(succ);
	}

	return end();
}

// Returns an iterator to the successor of the node pointed to by the given iterator
SplayTree::iterator SplayTree::successor(iterator& it) {
	Node* curr = it._curr;
	if (!curr) { return end(); }

	// Case 1: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
	if (curr->right) {
		Node* succ = curr->right;
		for (; succ->left; ) { succ = succ->left; }
		// splay(succ);
		return iterator(succ);
	}

	// Case 2: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
	Node* parent = curr->parent;
	for (; parent && curr == parent->right; ) {
		curr = parent;
		parent = parent->parent;
	}
	
	if (parent) {
		// splay(parent);
		return iterator(parent);
	}

	return end();
}

// Returns a const iterator to the minimum element in the tree
SplayTree::iterator SplayTree::minimum() {
	if (!_root) { return end(); }
	Node* leftmost = findLeftmost(_root);
	// splay(leftmost);
	return iterator(leftmost);
}

// Returns a const iterator to the maximum element in the tree
SplayTree::iterator SplayTree::maximum() {
	if (!_root) { return end(); }
	Node* rightmost = findRightmost(_root);
	// splay(rightmost);
	return iterator(rightmost);
}


// ----------
//  Capacity
// ----------

//// Returns true if the tree has no elements
//bool SplayTree::empty() const {
//	// Implementation
//}
//
//// Returns the total number of elements in the tree
//int SplayTree::size() const {
//	// Implementation
//}
//
//// Returns the height of the entire tree
//int SplayTree::height() const {
//	// Implementation
//}
//
//// Returns the height of the subtree rooted at the given value
//int SplayTree::height(const int& val) const {
//	// Implementation
//}
//
//// Returns the height of the subtree rooted at the given iterator
//int SplayTree::height(const iterator& it) const {
//	// Implementation
//}
//
//// Returns the depth of the entire tree
//int SplayTree::depth() const {
//	// Implementation
//}
//
//// Returns the depth of the node with the given value
//int SplayTree::depth(const int& val) const {
//	// Implementation
//}
//
//// Returns the depth of the node given an iterator
//int SplayTree::depth(const iterator& it) const {
//	// Implementation
//}


// -----------
//  Modifiers
// -----------

//// Inserts a new element into the SplayTree, maintaining ordering and balance 
//void SplayTree::insert(const int& val) {
//	// Implementation
//}
//
//// Removes a node with the given value from the SplayTree, maintaining order and balance
//void SplayTree::remove(const int& val) {
//	// Implementation
//}

// Removes all nodes from the tree and resets it to an empty state
void SplayTree::clear() {
	destroySubtree(_root);
	_root = nullptr;
	_size = 0;
}

//// Exchanges the contents of this SplayTree with another SplayTree
//void SplayTree::swap(SplayTree& other) {
//	// Implementation
//}