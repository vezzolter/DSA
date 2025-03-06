// Title:   Source file for AVL
// Authors: by vezzolter
// Date:    February 17, 2025
// ----------------------------------------------------------------------------


#include "AVL.h"


// -----------------
//  Utility Methods
// -----------------

// Recursively copies nodes with relationships from 'src' into a new tree
AVL::Node* AVL::copyNodes(Node* src, Node* parent) {
	if (!src) { return nullptr; }

	Node* newNode = new Node(src->_data);
	newNode->_parent = parent;

	newNode->_left = copyNodes(src->_left, newNode);
	newNode->_right = copyNodes(src->_right, newNode);

	return newNode;
}

// Find the leftmost node starting from the given node (the smallest)
AVL::Node* AVL::findLeftmost(Node* node) const {
	if (!node) { return nullptr; }
	for (; node && node->_left; ) { node = node->_left; }
	return node;
}

// Find the rightmost node starting from the given node (the biggest)
AVL::Node* AVL::findRightmost(Node* node) const {
	if (!node) { return nullptr; }
	for (; node && node->_right; ) { node = node->_right; }
	return node;
}

// Compute the height of a given node
int AVL::computeHeight(Node* node) const {
	if (!node) { return -1; }
	int leftHeight = computeHeight(node->_left);
	int rightHeight = computeHeight(node->_right);
	return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight); // ?: instead of std::max
}

// Computes the depth of a given node
int AVL::computeDepth(Node* node) const {
	if (!node) { return -1; }
	int depth = 0;
	for (Node* curr = _root; curr && curr != node; ++depth) {
		curr = (node->_data < curr->_data) ? curr->_left : curr->_right;
	}
	return depth;
}


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty AVL
AVL::AVL() : _size(0), _root(nullptr) {}

// Constructs a AVL with the deep copy contents of 'other'
AVL::AVL(const AVL& other) : _size(other._size), _root(nullptr) {
	if (other._root) { _root = copyNodes(other._root, nullptr); }
}

// Replaces the contents of this AVL with a deep copy of 'rhs'
AVL& AVL::operator=(const AVL& rhs) {
	if (this == &rhs) { return *this; }
	clear();
	_size = rhs._size;

	_root = rhs._root ? copyNodes(rhs._root, nullptr) : nullptr;

	return *this;
}

// Performs final cleanup and terminates the object
AVL::~AVL() { clear(); }


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the AVL
AVL::iterator AVL::begin() { return iterator(findLeftmost(_root), this); }

// Returns an iterator to one past the last element of the AVL
AVL::iterator AVL::end() { return iterator(nullptr, this); }

// Returns a const iterator to the first element of the AVL
AVL::const_iterator AVL::begin() const { return const_iterator(findLeftmost(_root), this); }

// Returns a const iterator to one past the last element of the AVL
AVL::const_iterator AVL::end() const { return const_iterator(nullptr, this); }

// Explicitly returns a const iterator to the first element of the AVL
AVL::const_iterator AVL::cbegin() const { return const_iterator(findLeftmost(_root), this); }

// Explicitly returns a const iterator to one past the last element of the AVL
AVL::const_iterator AVL::cend() const { return const_iterator(nullptr, this); }


// ----------------
//  Element Access 
// ----------------

// Returns an iterator to the element with given value
AVL::iterator AVL::find(const int& val) {
	for (Node* curr = _root; curr; ) {
		if (val > curr->_data) {
			curr = curr->_right;
		} else if (val < curr->_data) {
			curr = curr->_left;
		} else {
			return iterator(curr, this); // found
		}
	}

	return end(); // not found
}

// Returns a const iterator to the element with given value
AVL::const_iterator AVL::find(const int& val) const {
	for (Node* curr = _root; curr; ) {
		if (val > curr->_data) {
			curr = curr->_right;
		} else if (val < curr->_data) {
			curr = curr->_left;
		} else {
			return const_iterator(curr, this); // found
		}
	}

	return cend(); // not found
}

// Returns an iterator to the predecessor of the given value
AVL::iterator AVL::predecessor(const int& val) {
	Node* pred = nullptr;

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
AVL::const_iterator AVL::predecessor(const int& val) const {
	Node* pred = nullptr;

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
AVL::iterator AVL::successor(const int& val) {
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
AVL::const_iterator AVL::successor(const int& val) const {
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
AVL::iterator AVL::predecessor(const iterator& it) {
	Node* curr = it._curr; // for readability
	if (!curr) { return end(); }

	// Case 1: if the 'given' has a left subtree, 'next' is the rightmost node in that subtree
	if (curr->_left) {
		Node* pred = curr->_left;
		for (; pred->_right; ) { pred = pred->_right; }
		return iterator(pred, this);
	}

	// Case 2: otherwise 'next' is the first parent node, where the 'given' is in the right subtree
	Node* parent = curr->_parent;
	for (; parent && curr == parent->_left; ) {
		curr = parent;
		parent = parent->_parent;
	}

	return parent ? iterator(parent, this) : end();
}

// Returns a const_iterator to the predecessor of the node pointed to by the given iterator
AVL::const_iterator AVL::predecessor(iterator& it) const {
	Node* curr = it._curr; // for readability
	if (!curr) { return end(); }

	// Case 1: if the 'given' has a left subtree, 'next' is the rightmost node in that subtree
	if (curr->_left) {
		Node* pred = curr->_left;
		for (; pred->_right; ) { pred = pred->_right; }
		return const_iterator(pred, this);
	}

	// Case 2: otherwise 'next' is the first parent node, where the 'given' is in the right subtree
	Node* parent = curr->_parent;
	for (; parent && curr == parent->_left; ) {
		curr = parent;
		parent = parent->_parent;
	}

	return parent ? const_iterator(parent, this) : cend();
}

// Returns an iterator to the successor of the node pointed to by the given iterator
AVL::iterator AVL::successor(const iterator& it) {
	Node* curr = it._curr; // for readability
	if (!curr) { return end(); }

	// Case 1: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
	if (curr->_right) {
		Node* succ = curr->_right;
		for (; succ->_left; ) { succ = succ->_left; }
		return iterator(succ, this);
	}

	// Case 2: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
	Node* parent = curr->_parent;
	for (; parent && curr == parent->_right;) {
		curr = parent;
		parent = parent->_parent;
	}

	return parent ? iterator(parent, this) : end();
}

// Returns a const_iterator to the successor of the node pointed to by the given iterator
AVL::const_iterator AVL::successor(iterator& it) const {
	Node* curr = it._curr; // for readability
	if (!curr) { return cend(); }

	// Case 1: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
	if (curr->_right) {
		Node* succ = curr->_right;
		for (; succ->_left; ) { succ = succ->_left; }
		return const_iterator(succ, this);
	}

	// Case 2: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
	Node* parent = curr->_parent;
	for (; parent && curr == parent->_right; ) {
		curr = parent;
		parent = parent->_parent;
	}

	return parent ? const_iterator(parent, this) : cend();
}

// Returns the minimum value in the tree
int AVL::minimum() const {
	if (!_root) { return -1; }
	Node* leftmost = findLeftmost(_root);
	return leftmost->_data;
}

// Returns the maximum value in the tree
int AVL::maximum() const {
	if (!_root) { return -1; }
	Node* rightmost = findRightmost(_root);
	return rightmost->_data;
}


// ----------
//  Capacity
// ----------

// Returns true if the tree has no elements
bool AVL::empty() const { 
	return _size == 0; 
}

// Returns the total number of elements in the tree
int AVL::size() const {
	return _size;
}

// Returns the height of the entire tree
int AVL::height() const {
	return computeHeight(_root);
}

// Returns the height of the subtree rooted at the given value
int AVL::height(const int& val) const {
	Node* node = _root;
	for (; node && node->_data != val; ) {
		node = (val < node->_data) ? node->_left : node->_right;
	}
	return computeHeight(node);
}

// Returns the height of the subtree rooted at the given iterator
int AVL::height(const iterator& it) const {
	return computeHeight(it._curr);
}

// Returns the depth of the entire tree
int AVL::depth() const {
	return computeHeight(_root);
}

// Returns the depth of the node with the given value
int AVL::depth(const int& val) const {
	Node* node = _root;
	for (; node && node->_data != val; ) {
		node = (val < node->_data) ? node->_left : node->_right;
	}
	return computeDepth(node);
}

// Returns the depth of the node given an iterator
int AVL::depth(const iterator& it) const {
	return computeDepth(it._curr);
}


// -----------
//  Modifiers
// -----------

// Inserts a new element into the AVL, maintaining AVL ordering (not balancing)
void AVL::insert(const int& val) {
	Node* parent = nullptr;

	// Locate the insertion point
	for (Node* curr = _root; curr; ) {
		parent = curr;

		if (val < curr->_data) {
			curr = curr->_left;
		} else if (val > curr->_data) {
			curr = curr->_right;
		} else {
			return; // if AVL handles duplicates, there could be counter increment added
		}
	}

	// Create and insert new node
	Node* newNode = new Node(val, parent);
	if (!parent) {
		_root = newNode;
	} else if (val < parent->_data) {
		parent->_left = newNode;
	} else {
		parent->_right = newNode;
	}

	++_size;
}

// Removes a node with the given value from the AVL
void AVL::remove(const int& val) {
	auto deleteNode = [](Node* root, const int& key, auto& selfRef) -> Node* {
		if (!root) { return nullptr; }

		// Locate node to delete
		if (key < root->_data) {
			root->_left = selfRef(root->_left, key, selfRef);
		} else if (key > root->_data) {
			root->_right = selfRef(root->_right, key, selfRef);
		} else {
			// Case 1: at most one child
			if (!root->_left || !root->_right) {
				Node* temp = root->_left ? root->_left : root->_right;
				delete root;
				return temp;
			}

			// Case 2: two children (replace with in-order successor)
			Node* succ = root->_right;
			for (; succ->_left; ) { succ = succ->_left; }
			root->_data = succ->_data;
			root->_right = selfRef(root->_right, succ->_data, selfRef);
		}

		return root;
	};

	_root = deleteNode(_root, val, deleteNode);
	if (find(val) == end()) { --_size; }
}

// Removes all nodes from the AVL, resetting it to its initial state
void AVL::clear() {
	auto deleteNodes = [](Node* node, auto& deleteNodesRef) -> void {
		if (!node) { return; }
		deleteNodesRef(node->_left, deleteNodesRef);
		deleteNodesRef(node->_right, deleteNodesRef);
		delete node;
	};

	deleteNodes(_root, deleteNodes);
	_root = nullptr;
	_size = 0;
}

// Exchanges the contents of this AVL with another AVL
void AVL::swap(AVL& other) {
	if (this == &other) { return; }

	Node* root = _root;
	_root = other._root;
	other._root = root;

	int size = _size;
	_size = other._size;
	other._size = size;
}