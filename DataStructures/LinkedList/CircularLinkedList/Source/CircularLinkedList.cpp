// Title:   Source file for Circular Linked List
// Authors: by vezzolter
// Date:    February 15, 2024
// ----------------------------------------------------------------------------


#include "CircularLinkedList.h"


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty list
CLL::CLL() : _size(0), _head(nullptr) {}

// Constructs a list with 'size' copies of elements with 'data' value
CLL::CLL(int size, int data)
	: _size(size), _head(nullptr) {
	// Create the head node
	_head = new Node(data);

	// Create rest of the nodes
	Node* curr = _head;
	for (int i = 1; i < size; ++i) {
		curr->_next = new Node(data);
		curr = curr->_next;
	}
}

// Constructs a list with the contents of 'other'
CLL::CLL(const CLL& other)
	: _size(other._size) {
	// Case: empty list
	if (!other._head) {
		_head = nullptr;
		return;
	}

	// Copy head node
	_head = new Node(other._head->_data);

	// Copy rest of nodes
	Node* currSrc = other._head->_next;
	Node* curr = _head;
	for (; currSrc; ) {
		curr->_next = new Node(currSrc->_data);
		curr = curr->_next;
		currSrc = currSrc->_next;
	}
}

// Replaces the contents with a copy of the contents of 'rhs'
CLL& CLL::operator=(const CLL& rhs) {
	// Prepare: check for self-assignment and deallocate any old memory
	if (this == &rhs) { return *this; }
	clear();

	// Set corresponding size
	_size = rhs._size;

	// Case: empty list
	if (rhs._head == nullptr) {
		_head = nullptr;
		return *this;
	}

	// Copy head node
	_head = new Node(rhs._head->_data);

	// Copy rest of nodes
	Node* currRhs = rhs._head->_next;
	Node* curr = _head;
	for (; currRhs; ) {
		curr->_next = new Node(currRhs->_data);
		curr = curr->_next;
		currRhs = currRhs->_next;
	}

	return *this;
}

// Destructs the list
CLL::~CLL() {
	Node* curr = _head;
	for (; curr; ) {
		Node* next = curr->_next;
		delete curr;
		curr = next;
	}
	_head = nullptr;
	_size = 0;
}


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the list
CLL::Iterator CLL::begin() { return iterator(_head); }

// Returns an iterator to one past the last element of the list
CLL::Iterator CLL::end() { return iterator(nullptr); }

// Returns a const iterator to the first element of the list
CLL::ConstIterator CLL::cbegin() const { return const_iterator(_head); }

// Returns a const iterator to one past the last element of the list
CLL::ConstIterator CLL::cend() const { return const_iterator(nullptr); }


// ----------------
//  Element Access
// ----------------

// Returns a modifiable reference to the first element
int& CLL::front() { return _head->_data; }

// Returns a non-modifiable reference to the first element
const int& CLL::front() const { return _head->_data; }


// ----------
//  Capacity
// ----------

// Returns true if list has no elements
bool CLL::empty() const { return _size == 0; }

// Returns the number of stored elements (nodes)
int CLL::size() const { return _size; }


// -----------
//  Modifiers
// -----------

// Inserts a copy of 'data' after 'pos'
void CLL::insertAfter(iterator pos, const int& data) {
	// Case: wrong iterator
	if (pos == this->end()) { return; }

	// Create a new node with the given data
	Node* newNode = new Node(data);

	// Get the given node
	Node* curr = pos.operator->();

	// Insert the new node after the current one
	newNode->_next = curr->_next;
	curr->_next = newNode;

	// Reflect new element on size
	++_size;
}

// Removes the element after 'pos'.
void CLL::eraseAfter(iterator pos) {
	// Case: wrong iterator
	if (pos == this->end()) { return; }

	// Get the given node
	Node* curr = pos.operator->();

	// Remove node (if there is one after the current)
	if (curr && curr->_next) {
		Node* nodeToDelete = curr->_next;
		curr->_next = nodeToDelete->_next;
		delete nodeToDelete;
	}

	// Reflect removed element on size
	--_size;
}


// Prepends the given 'data' to the beginning of the list
void CLL::pushFront(const int& data) {
	// Create a new node with the given data
	Node* newNode = new Node(data);

	// Push front
	newNode->_next = _head;
	_head = newNode;

	// Reflect new element on size
	++_size;
}

// Removes the first element of the list
void CLL::popFront() {
	// Case: empty list
	if (!_head) { return; }

	// Case: one element
	if (_size == 1) {
		delete _head;
		_head = nullptr;
		_size = 0;
		return;
	}

	// Move the head pointer to the next node
	Node* temp = _head;
	_head = _head->_next;
	delete temp;

	// Reflect removed element on size
	--_size;
}

// Reverses the order of the elements in the list
void CLL::reverse() {
	// Case: empty list, single element
	if (!_head || !_head->_next) { return; }

	// Preliminaries
	Node* prev = nullptr;
	Node* curr = _head;
	Node* next = nullptr;

	for (; curr; ) {
		// Reverse the next pointer via temp prev
		next = curr->_next;
		curr->_next = prev;
		prev = curr;

		// Move iterating node ahead
		curr = next;
	}

	// Update the head to point to the new front of the list
	_head = prev;
}

// Replaces the contents with 'size' copies of 'data'
void CLL::assign(int size, const int& data) {
	// Clear the existing contents
	clear();

	// Add 'size' nodes with 'data'
	for (int i = 0; i < size; ++i) { pushFront(data); }

	// No reverse(), since data is the same
}

// Replaces the contents with copies of those in the range [first, last)
void CLL::assign(const_iterator first, const_iterator last) {
	// Clear the existing contents
	clear();

	// Add each element from the iterator range
	for (auto it = first; it != last; ++it) { pushFront(*it); }

	// Reverse the list to preserve the order
	reverse();
}

// Erases all elements from the list
void CLL::clear() {
	// Case: empty list
	if (!_head) { return; }

	// Traverse the list and deallocate memory for each node
	for (; _head; ) {
		Node* curr = _head;
		_head = _head->_next;
		delete curr;
	}

	// Reset the list to an empty state
	_size = 0;
	_head = nullptr;
}

// Resizes the list to contain 'size' elements
void CLL::resize(int size, const int& data) {
	// Case 1: new size is the same 
	if (size == _size) { return; }

	// Case 2: new size is smaller
	if (size < _size) {
		// Traverse to the new last node
		Node* curr = _head;
		for (int i = 1; i < size; ++i) { curr = curr->_next; }

		// Delete excessive nodes
		Node* toDelete = curr->_next;
		curr->_next = nullptr; // detach the rest of the list

		// Delete remaining nodes
		for (; toDelete; ) {
			Node* temp = toDelete;
			toDelete = toDelete->_next;
			delete temp;
		}

	} else if (size > _size) {
		// Case 3: new size is greater

		// Get the previous end
		Node* curr = _head;
		if (curr) {
			for (; curr->_next; ) {
				curr = curr->_next;
			}
		}

		// Add new nodes until reaching new size
		for (int i = _size; i < size; ++i) {
			Node* newNode = new Node(data);
			if (curr) {
				curr->_next = newNode;
			} else {
				_head = newNode;  // for an initially empty list
			}
			curr = newNode;
		}
	}

	// Update size to the new size
	_size = size;
}

// Exchanges the contents of the list with those of 'other'
void CLL::swap(CLL& other) {
	// Case: the list
	if (this == &other) { return; }

	// Swap the head pointers
	Node* tempHead = _head;
	_head = other._head;
	other._head = tempHead;

	// Swap the sizes
	int tempSize = _size;
	_size = other._size;
	other._size = tempSize;
}