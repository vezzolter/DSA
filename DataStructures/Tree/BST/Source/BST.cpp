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

// Find the leftmost node starting from the given node (begin/smallest)
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
BST::iterator BST::begin() { return iterator(findLeftmost(_root), this); }

// Returns an iterator to one past the last element of the BST
BST::iterator BST::end() { return iterator(nullptr, this); }

// Returns a const iterator to the first element of the BST
BST::const_iterator BST::begin() const { return const_iterator(findLeftmost(_root), this);}

// Returns a const iterator to one past the last element of the BST
BST::const_iterator BST::end() const { return const_iterator(nullptr, this); }

// Explicitly returns a const iterator to the first element of the BST
BST::const_iterator BST::cbegin() const { return const_iterator(findLeftmost(_root), this); }

// Explicitly returns a const iterator to one past the last element of the BST
BST::const_iterator BST::cend() const { return const_iterator(nullptr, this); }


// ----------------
//  Element Access 
// ----------------

// Returns an iterator to the element with given value
BST::iterator BST::find(const int& val) {
	for (Node* curr = _root; curr; ) {
		if (val > curr->_data) {
			curr = curr->_right;
		} else if (val < curr->_data) {
			curr = curr->_left;
		} else {
			return iterator(curr, this);
		}
	}

	return end(); // if not present
}

// Returns a const iterator to the element with given value
BST::const_iterator BST::find(const int& val) const {
	for (Node* curr = _root; curr; ) {
		if (val > curr->_data) {
			curr = curr->_right;
		} else if (val < curr->_data) {
			curr = curr->_left;
		} else {
			return const_iterator(curr, this);
		}
	}

	return cend(); // if not present
}

// Returns an iterator to the predecessor of the given value
BST::iterator BST::predecessor(const int& val) {
	Node* pred = nullptr;

	// We have to traverse from the root, since we have only value
	for (Node* curr = _root; curr; ) {
		if (val > curr->_data) {
			pred = curr;
			curr = curr->_right;
		} else {
			curr = curr->_left;
		}
	}

	return pred ? iterator(pred, this) : end();
}

// Returns a const_iterator to the predecessor of the given value
BST::const_iterator BST::predecessor(const int& val) const {
	Node* pred = nullptr;

	// We have to traverse from the root, since we have only value
	for (Node* curr = _root; curr; ) {
		if (val > curr->_data) {
			pred = curr;
			curr = curr->_right;
		} else {
			curr = curr->_left;
		}
	}

	return pred ? const_iterator(pred, this) : cend();
}

// Returns an iterator to the successor of the given value
BST::iterator BST::successor(const int& val) {
	Node* succ = nullptr;

	// We have to traverse from the root, since we have only value
	for (Node* curr = _root; curr; ) {
		if (val < curr->_data) {
			succ = curr;
			curr = curr->_left;
		} else {
			curr = curr->_right;
		}
	}

	return succ ? iterator(succ, this) : end();
}

// Returns a const_iterator to the successor of the given value
BST::const_iterator BST::successor(const int& val) const {
	Node* succ = nullptr;

	// We have to traverse from the root, since we have only value
	for (Node* curr = _root; curr;) {
		if (val < curr->_data) {
			succ = curr;
			curr = curr->_left;
		} else {
			curr = curr->_right;
		}
	}

	return succ ? const_iterator(succ, this) : cend();
}

// Returns an iterator to the predecessor of the node pointed to by the given iterator
BST::iterator BST::predecessor(const iterator& it) {
	Node* pred = nullptr;
	Node* curr = it._curr;

	// Case: if the 'given' has a left subtree, 'next' is the rightmost node in that subtree
	if (curr->_left) {
		pred = curr->_left;
		for (; pred->_right; ) { pred = pred->_right; }

	// Case: otherwise 'next' is the first parent node, where the 'given' is in the right subtree
	} else {
		Node* parent = curr->_parent;
		for (; parent && curr == parent->_left; ) {
			curr = parent;
			parent = parent->_parent;
		}
		pred = parent;
	}

	return pred ? iterator(pred, this) : end();
}

// Returns a const_iterator to the predecessor of the node pointed to by the given iterator
BST::const_iterator BST::predecessor(iterator& it) const {
	Node* pred = nullptr;
	Node* curr = it._curr;

	// Case: if the 'given' has a left subtree, 'next' is the rightmost node in that subtree
	if (curr->_left) {
		pred = curr->_left;
		for (; pred->_right; ) { pred = pred->_right; }

	// Case: otherwise 'next' is the first parent node, where the 'given' is in the right subtree
	} else {
		Node* parent = curr->_parent;
		for (; parent && curr == parent->_left; ) {
			curr = parent;
			parent = parent->_parent;
		}
		pred = parent;
	}

	return pred ? const_iterator(pred, this) : cend();
}

// Returns an iterator to the successor of the node pointed to by the given iterator
BST::iterator BST::successor(const iterator& it) {
	Node* succ = nullptr;
	Node* curr = it._curr;

	// Case: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
	if (curr->_right) {
		succ = curr->_right;
		for (; succ->_left; ) { succ = succ->_left; }

	// Case: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
	} else {
		Node* parent = curr->_parent;
		for (; parent && curr == parent->_right;) {
			curr = parent;
			parent = parent->_parent;
		}
		succ = parent;
	}

	return succ ? iterator(succ, this) : end();
}

// Returns a const_iterator to the successor of the node pointed to by the given iterator
BST::const_iterator BST::successor(iterator& it) const {
	Node* succ = nullptr;
	Node* curr = it._curr;

	// Case: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
	if (curr->_right) {
		
		succ = curr->_right;
		for (; succ->_left; ) { succ = succ->_left; }

	// Case: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
	} else {
		Node* parent = curr->_parent;
		for (; parent && curr == parent->_right; ) {
			curr = parent;
			parent = parent->_parent;
		}
		succ = parent;
	}

	return succ ? const_iterator(succ, this) : cend();
}

// Returns the minimum value in the tree
int BST::minimum() const {
	// Case: empty tree
	if (!_root) { return -1; }

	// The leftmost in balanced version is the min
	Node* curr = _root;
	for (; curr->_left; ) { curr = curr->_left; }

	return curr->_data;
}

// Returns the maximum value in the tree
int BST::maximum() const {
	// Case: empty tree
	if (!_root) { return -1; }

	// The righmost in balanced version is the max
	Node* curr = _root;
	for (; curr->_right; ) { curr = curr->_right; }

	return curr->_data;
}


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

	// Traverse to find the insertion point
	for (Node* curr = _root; curr; ) {
		parent = curr;

		if (val < curr->_data) {
			curr = curr->_left;
		} else if (val > curr->_data) {
			curr = curr->_right;
		} else {
			return; // if BST handles duplicates, there could be counter increment added
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