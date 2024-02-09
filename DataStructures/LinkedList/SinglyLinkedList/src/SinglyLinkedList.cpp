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

// Desctuctor
template<typename T>
SLL<T>::~SLL() { clear(); };



// --------
// Capacity
// --------

// Returns the number of elements in the container
template<typename T>
int SLL<T>::size() { return _size; }



// ---------
// Modifiers
// ---------

// Erases all elements from the container.
template<typename T>
void SLL<T>::clear() {
	// Loop until end (nullptr)
	while (_head) {
		// Store the currrent, so you can delete it after iterate
		Node<T>* temp = _head;
		// Iterate via head
		_head = _head->_next;
		// Delete previous
		delete temp;
	}
	// Ensure proper size
	_size = 0;
}

// Prepends the given element value to the beginning of the container.
template<typename T>
void SLL<T>::push_front(const T& newData) {
	// Create a new node with the given data
	Node<T>* newNode = new Node<T>(newData);

	// If list has elements
	if (_head != nullptr) {
		// Point newNode to current head
		newNode->_next = _head;
	}

	// Update head
	_head = newNode;
	// Increase counter
	_size++;
}

#endif