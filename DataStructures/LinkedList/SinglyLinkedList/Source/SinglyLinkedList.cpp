// Title:   Source file for Singly Linked List
// Authors: by vezzolter
// Date:    February 3, 2024
// ----------------------------------------------------------------------------


#include "SinglyLinkedList.h"


// --------------------
//  Compiler Generated
// --------------------

// Default Constructor
SLL::SLL() : _size(0), _head(nullptr) {}

// Deep copy constructor 
SLL::SLL(const SLL& rhs) : _size(rhs._size) {
	// Case: empty list
	if (rhs._head == nullptr) {
		_head = nullptr;
		return;
	}

	// Create corresponding first node
	_head = new Node(rhs._head->_data);

	// Initialize traversal pointers
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;

	// Copy other nodes
	while (currentRhs) {
		current->_next = new Node(currentRhs->_data);
		current = current->_next;
		currentRhs = currentRhs->_next;
	}
}

// Deep copy assignment operator
SLL& SLL::operator=(const SLL& rhs) {
	// Self-assignment guard
	if (this == &rhs)
		return *this;

	// Ensure that the destination list doesn't retain any of its existing elements
	clear();
	// Set corresponding size
	_size = rhs._size;

	// Case: empty list
	if (rhs._head == nullptr) {
		_head = nullptr;
		return *this;
	}

	// Create corresponding first node
	_head = new Node(rhs._head->_data);

	// Initialize traversal pointers
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;

	// Copy other nodes
	while (currentRhs) {
		current->_next = new Node(currentRhs->_data);
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Maintain the proper reference to the head
	_head = current;

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

// Accesses the first element in the container, no range check, allows modification
int& SLL::front() { return _head->_data; }

// Accesses the first element in the container, no range check, denies modification
const int& SLL::front() const { return _head->_data; }


// ----------
//  Capacity
// ----------

// Checks if the container has no elements
bool SLL::empty() const { return _size == 0; }

// Returns the number of elements in the container
int SLL::size() const { return _size; }


// -----------
//  Modifiers
// -----------

// Inserts elements after the specified position in the container
// Note: with no bounds check, assumes that index is correct
void SLL::insertAfter(const int pos, const int& data) {
	if (pos == 0) {
		pushFront(data);
	}
	else {
		// Create a new node with the given data
		Node* newNode = new Node(data);

		// Find the node at the specified index
		Node* current = _head;
		for (int i = 0; i < pos - 1; i++) {
			current = current->_next;
		}

		// Insert the new node after the current one
		newNode->_next = current->_next;
		current->_next = newNode;

		// Update the size
		++_size;
	}
}

// Removes an element at the specified position
// Note: with no bounds check, assumes that index is correct
void SLL::eraseAfter(const int pos) {
	if (pos == 0) {
		popFront();
	}
	else {
		// Traverse to the node before the node to be erased
		Node* current = _head;
		for (int i = 0; i < pos; ++i) {
			current = current->_next;
		}

		// Remove
		Node* nodeToDelete = current->_next;
		current->_next = nodeToDelete->_next;
		delete nodeToDelete;

		// Update the size
		--_size;
	}
}

// Prepends the given element value to the beginning of the container
void SLL::pushFront(const int& data) {
	// Create a new node with the given data
	Node* newNode = new Node(data);

	// Case: empty list
	if (_size == 0) {
		_head = newNode;
	}
	else {
		// Push front
		newNode->_next = _head;
		_head = newNode;
	}

	// Update the size
	++_size;
}

// Removes the first element of the container
// Note: with no bounds check, assumes that list contains at least 1 element
void SLL::popFront() {
	// TODO: range check

	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the head pointer to the next node
	Node* temp = _head;
	_head = _head->_next;
	delete temp;

	// Update the size
	--_size;
}

// Description
void assign() {

}

// Erases all elements from the container
void SLL::clear() {
	// Case: empty list
	if (!_head)
		return;

	// Traverse the list and deallocate memory for each node
	while (_head) {
		Node* current = _head;
		_head = _head->_next;
		delete current;
	}

	// Update the state of list
	_size = 0;
	_head = nullptr;
}

// Description
void resize() {

}

// Description
void swap() {

}