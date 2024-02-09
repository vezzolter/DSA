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
SLL<T>::~SLL() { clear(); }



// --------------
// Element Access
// --------------

// Access the element at the specified index
template<class T>
T& SLL<T>::operator[](const int index) {
	// TODO: potential range check

	// For traversing purposes
	int counter = 0;
	Node<T>* current = _head;

	// Loop until end (nullptr)
	while (current != nullptr) {
		// Return value of matched node
		if (counter == index) {
			return current->_data;
		}
		// Otherwise keep traversing
		current = current->_next;
		counter++;
	}
}

// Returns a reference to the first element in the container.
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
int SLL<T>::size() { return _size; }



// ---------
// Modifiers
// ---------

// Erases all elements from the container.
template<typename T>
void SLL<T>::clear() {
	// Loop until end (nullptr)
	while (_head) {
		// Create temp node for current, so it can be deleted later
		Node<T>* current = _head;
		// Traverse via head
		_head = _head->_next;
		// Delete previous
		delete current;
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