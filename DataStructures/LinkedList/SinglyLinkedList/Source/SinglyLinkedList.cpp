// Title:   Source file for Singly Linked List
// Authors: by vezzolter
// Date:    February 3, 2024
// ----------------------------------------------------------------------------


#include "SinglyLinkedList.h"


// --------------------
//  Compiler Generated
// --------------------

// Initializes an empty list
SLL::SLL() : _size(0), _head(nullptr) {}

// Initializes lsit with given size and all elements with one value
SLL::SLL(int size, int data)
	: _size(size), _head(nullptr) {
	// Case: wrong size
	if (size <= 0) {
		_size = 0;
		return;
	}

	// Create head node
	_head = new Node(data);

	// Create rest of nodes
	Node* curr = _head;
	for (int i = 1; i < size; ++i) {
		curr->_next = new Node(data);
		curr = curr->_next;
	}
}

// Initializes list with data by deep copying it from another one
SLL::SLL(const SLL& src) 
	: _size(src._size) {
	// Case: empty container
	if (src._head == nullptr) {
		_head = nullptr;
		return;
	}

	// Copy head node
	_head = new Node(src._head->_data);

	// Copy rest of nodes
	Node* currSrc = src._head->_next;
	Node* current = _head;
	for ( ; currSrc; ) {
		current->_next = new Node(currSrc->_data);
		current = current->_next;
		currSrc = currSrc->_next;
	}
}

// Assigns list with data by deep copying it from another one
SLL& SLL::operator=(const SLL& rhs) {
	// Prepare: check for self-assignment and deallocate any old memory
	if (this == &rhs) { return *this; }
	clear();
	
	// Set corresponding size
	_size = rhs._size;

	// Case: empty container
	if (rhs._head == nullptr) {
		_head = nullptr;
		return *this;
	}

	// Copy head node
	_head = new Node(rhs._head->_data);

	// Copy rest of nodes
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;
	while (currentRhs) {
		current->_next = new Node(currentRhs->_data);
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	return *this;
}

// Destructor
SLL::~SLL() { clear(); }


// -----------
//  Iterators
// -----------

// Description
// SLLIterator begin() {
// 
// }


// ----------------
//  Element Access
// ----------------

// Returns a modifiable reference to the first element
int& SLL::front() { return _head->_data; }

// Returns a non-modifiable reference to the first element
const int& SLL::front() const { return _head->_data; }


// ----------
//  Capacity
// ----------

// Returns true if list has no elements
bool SLL::empty() const { return _size == 0; }

// Returns the number of stored elements (nodes)
int SLL::size() const { return _size; }


// -----------
//  Modifiers
// -----------

// Inserts a new node with given data after the specified position
void SLL::insertAfter(const int pos, const int& data) {
	// Create a new node with the given data
	Node* newNode = new Node(data);

	// Find the node at the specified index
	Node* curr = _head;
	for (int i = 0; i < pos; ++i) { curr = curr->_next; }

	// Insert the new node after the current one
	newNode->_next = curr->_next;
	curr->_next = newNode;

	// Reflect new element on size
	++_size;
}

// Removes the node after the specified position
void SLL::eraseAfter(const int pos) {
	// Traverse to the node before the node to be erased
	Node* curr = _head;
	for (int i = 0; i < pos; ++i) { curr = curr->_next; }

	// Remove node (if there is such)
	if (curr != nullptr && curr->_next != nullptr) {
		Node* nodeToDelete = curr->_next;
		curr->_next = nodeToDelete->_next;
		delete nodeToDelete;
	}

	// Reflect removed element on size
	--_size;
}

// Adds a new node with the given data at the front of the list
void SLL::pushFront(const int& data) {
	// Create a new node with the given data
	Node* newNode = new Node(data);

	// Push front
	newNode->_next = _head;
	_head = newNode;

	// Reflect new element on size
	++_size;
}

// Removes the first node in the list
void SLL::popFront() {
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

// Assigns the specified data to all elements
void SLL::assign(int size, const int& data) {
	// Clear the existing list
	clear();

	// Add 'size' nodes with 'data'
	for (int i = 0; i < size; ++i) {
		pushFront(data);
	}
}

// Clears the list by deallocating all nodes
void SLL::clear() {
	// Traverse the list and deallocate memory for each node
	for (; _head; ) {
		Node* curr = _head;
		_head = _head->_next;
		delete curr;
	}

	// Reset the container to an empty state
	_size = 0;
	_head = nullptr;
}

// Resizes the list to the specified size, reallocating if necessary
void SLL::resize(int size, const int& data = 0) {
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
		
		// Traverse to the last node (if list is not empty)
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

// Swaps the contents with another list
void SLL::swap(SLL& src) {
	// Case: the same container
	if (this == &src) { return; }

	// Swap the head pointers
	Node* tempHead = _head;
	_head = src._head;
	src._head = tempHead;

	// Swap the sizes
	int tempSize = _size;
	_size = src._size;
	src._size = tempSize;
}