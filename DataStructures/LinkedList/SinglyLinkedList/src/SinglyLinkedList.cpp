// Source file for simplified ADT: Singly Linked List
// by vezzolter
// February 3, 2024

#ifndef SLL_CPP
#define SLL_CPP

#include "SinglyLinkedList.h"

// ------------------------
// Special Member Functions
// ------------------------

// Default Constructor
template<typename T>
SLL<T>::SLL() : _head(nullptr), _size(0) {}

//// Parametrized constructor
//template<class T>
//SLL<T>::SLL(const std::initializer_list<T>& initList) { }

// Deep copy constructor 
template<class T>
SLL<T>::SLL(const SLL& rhs) {
	// Set corresponding size
	_size = rhs._size;

	// Case: empty list, avoid dangling pointers
	if (rhs._head == nullptr) {
		_head = nullptr;
		return;
	}

	// Create corresponding first node
	_head = new Node<T>(rhs._head->_data);

	// Initialize traversal pointers
	Node<T>* currentRhs = rhs._head->_next;
	Node<T>* current = _head;

	// Copy other nodes
	while (currentRhs) {
		current->_next = new Node<T>(currentRhs->_data);
		current = current->_next;
		currentRhs = currentRhs->_next;
	}
}

// Deep copy assignment operator
template<class T>
SLL<T>& SLL<T>::operator=(const SLL& rhs) {
	// Self-assignment guard
	if (this == &rhs)
		return *this;

	// Ensure that the destination list doesn't retain any of its existing elements
	clear();

	// Set corresponding size
	_size = rhs._size;

	// Case: empty list, avoid dangling pointers
	if (rhs._head == nullptr) {
		_head = nullptr;
		return *this;
	}

	// Create corresponding first node
	_head = new Node<T>(rhs._head->_data);

	// Initialize traversal pointers
	Node<T>* currentRhs = rhs._head->_next;
	Node<T>* current = _head;

	// Copy other nodes
	while (currentRhs) {
		current->_next = new Node<T>(currentRhs->_data);
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	_head = current;

	return *this;
}

// Destructor
template<typename T>
SLL<T>::~SLL() { clear(); }



// --------------
// Element Access
// --------------

// Access the element at the specified index, allows modification
template<class T>
T& SLL<T>::operator[](const int index) {
	// TODO: range check

	// Initialize traversal variables
	int counter = 0;
	Node<T>* current = _head;

	while (current != nullptr) {
		// Return value of matched node
		if (counter == index) {
			return current->_data;
		}
		// Otherwise keep traversing
		current = current->_next;
		counter++;
	}

	// Just for the compiler
	return current->_data;
}

// Access the element at the specified index, denies modification
template<class T>
T& SLL<T>::operator[](const int index) const {
	// TODO: range check

	// Initialize traversal variables
	int counter = 0;
	Node<T>* current = _head;

	while (current != nullptr) {
		// Return value of matched node
		if (counter == index) {
			return current->_data;
		}
		// Otherwise keep traversing
		current = current->_next;
		counter++;
	}

	// Just for the compiler
	return current->_data;
}

// Returns a reference to the first element in the container, allows modification
template<class T>
T& SLL<T>::front() {
	// TODO: handle empty case

	return _head->_data;
}



// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool SLL<T>::empty() const { return _size == 0; }

// Returns the number of elements in the container
template<typename T>
int SLL<T>::size() const { return _size; }



// ---------
// Modifiers
// ---------

// Erases all elements from the container
template<typename T>
void SLL<T>::clear() {
	// Traverse the list and deallocate memory for each node
	while (_head) {
		Node<T>* current = _head;
		_head = _head->_next;
		delete current;
	}

	// Update the state of list
	_size = 0;
	_head = nullptr;
}

// Inserts elements after the specified position in the container
template<class T>
void SLL<T>::insertAfter(const int index, const T& newData) {
	// TODO: range check

	if (index == 0) {
		pushFront(newData);
	}
	else {
		// Create a new node with the given data
		Node<T>* newNode = new Node<T>(newData);

		// Find the node at the specified index
		Node<T>* current = _head;
		for (int i = 0; i < index; i++) {
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
template<class T>
void SLL<T>::eraseAfter(const int index) {
	// TODO: range check

	if (index == 0) {
		popFront();
	}
	else {
		// Traverse to the node before the node to be erased
		Node<T>* current = _head;
		for (int i = 0; i < index; ++i) {
			current = current->_next;
		}

		// Remove
		Node<T>* nodeToDelete = current->_next;
		current->_next = nodeToDelete->_next;
		delete nodeToDelete;

		// Update the size
		--_size;
	}
}

// Prepends the given element value to the beginning of the container
template<typename T>
void SLL<T>::pushFront(const T& newData) {
	// Create a new node with the given data
	Node<T>* newNode = new Node<T>(newData);

	// If the list is empty, set the new node as both head
	if (_size == 0) { _head = newNode; }

	// Push front
	newNode->_next = _head;
	_head = newNode;

	// Update the size
	++_size;
}

// Removes the first element of the container
template<class T>
void SLL<T>::popFront() {
	// TODO: range check

	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the head pointer to the next node
	Node<T>* temp = _head;
	_head = _head->_next;
	delete temp;

	// Update the size
	--_size;
}

#endif