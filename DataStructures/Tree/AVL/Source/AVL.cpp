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
AVL::Node* AVL::findLeftmost(Node* node) const {
	// Traverse until its not empty and there is a left child
	for (; node && node->_left; ) { node = node->_left; }
	return node;
}


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty AVL
AVL::AVL() : _size(0), _root(nullptr) {}

// Constructs a AVL with the deep copy contents of 'other'
AVL::AVL(const AVL& other) : _size(other._size), _root(nullptr) {
	// Case: empty tree
	if (!other._root) { return; }

	// Delegate actual copy to utility function
	_root = copyNodes(other._root, nullptr);
}

// Replaces the contents of this AVL with a deep copy of 'rhs'
AVL& AVL::operator=(const AVL& rhs) {
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
			return iterator(curr, this);
		}
	}

	return end(); // if not present
}

// Returns a const iterator to the element with given value
AVL::const_iterator AVL::find(const int& val) const {
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
AVL::iterator AVL::predecessor(const int& val) {
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
AVL::const_iterator AVL::predecessor(const int& val) const {
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
AVL::const_iterator AVL::predecessor(iterator& it) const {
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
AVL::iterator AVL::successor(const iterator& it) {
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
AVL::const_iterator AVL::successor(iterator& it) const {
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
int AVL::minimum() const {
	// Case: empty tree
	if (!_root) { return -1; }

	// The leftmost in balanced version is the min
	Node* curr = _root;
	for (; curr->_left; ) { curr = curr->_left; }

	return curr->_data;
}

// Returns the maximum value in the tree
int AVL::maximum() const {
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

// Returns true if the tree has no elements
bool AVL::empty() const { return _size == 0; }

// Returns the total number of elements in the tree
int AVL::size() const { return _size; }

// Returns the height of the subtree rooted at the given value, or the root if no value
int AVL::height(const int& val) const {
	// Lambda allows to compute height within function via recursion
	auto computeHeight = [](Node* node, auto& selfRef) -> int {
		// Case: empty tree
		if (!node) { return -1; }

		// Height itself is just a max out of left subtree and right subtree
		int lHeight = selfRef(node->_left, selfRef);
		int rHeight = selfRef(node->_right, selfRef);
		return 1 + (lHeight > rHeight ? lHeight : rHeight); // replaces "std::max(lHeight, rHeight) + 1"
	};

	// If given values is not root, find it
	Node* startNode = _root;
	if (val != _root->_data) {
		for (Node* curr = _root; curr;) {
			// If found break, otherwise navigate left or right
			if (val == curr->_data) {
				startNode = curr;
				break;
			}
			curr = (val < curr->_data) ? curr->_left : curr->_right;
		}
	}

	// If the value doesn't exist (validation)
	if (!startNode) { return -1; }

	// Compute and return the height starting from the found node
	return computeHeight(startNode, computeHeight);
}

// Returns the depth of the node with the given value, or the root if no value
int AVL::depth(const int& val) const {
	// Traverse the tree from root until given val, each turn incrementing the depth
	Node* curr = _root;
	int depth = 0;
	for (; curr; ) {
		if (val == curr->_data) { return depth; }
		curr = (val < curr->_data) ? curr->_left : curr->_right;
		++depth;
	}

	return -1;
}


// -----------
//  Modifiers
// -----------

// Inserts a new element into the AVL, maintaining AVL ordering (not balancing)
void AVL::insert(const int& val) {
	Node* parent = nullptr; // keep track of parent during traversal and helps to insert

	// Traverse to find the insertion point
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

// Removes a node with the given value from the AVL
void AVL::remove(const int& val) {
	// Lamda keeps the logic local, preventing mess
	auto deleteNode = [](Node* root, const int& key, auto& selfRef) -> Node* {
		// Case: value not found
		if (!root) { return nullptr; }

		// Traverse to (left, right, found)
		if (key < root->_data) {
			root->_left = selfRef(root->_left, key, selfRef);
		} else if (key > root->_data) {
			root->_right = selfRef(root->_right, key, selfRef);
		} else {

			// Case: only right or no at all
			if (!root->_left) {
				Node* temp = root->_right;
				delete root;
				return temp;

				// Case: only left
			} else if (!root->_right) {
				Node* temp = root->_left;
				delete root;
				return temp;

				// Case: both
			} else {
				// Find the in-order successor (smallest in the right subtree)
				Node* succ = root->_right;
				for (; succ->_left; ) { succ = succ->_left; }
				// Copy the in-order successor's data to this node
				root->_data = succ->_data;
				// Delete the in-order successor
				root->_right = selfRef(root->_right, succ->_data, selfRef);
			}
		}

		return root;
	};

	// Deletion start from the root
	_root = deleteNode(_root, val, deleteNode);
	if (find(val) == end()) { --_size; }
}

// Removes all nodes from the AVL, resetting it to its initial state
void AVL::clear() {
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

// Exchanges the contents of this AVL with another AVL
void AVL::swap(AVL& other) {
	// Case: the same tree
	if (this == &other) { return; }

	Node* root = _root;
	_root = other._root;
	other._root = root;

	int size = _size;
	_size = other._size;
	other._size = size;
}