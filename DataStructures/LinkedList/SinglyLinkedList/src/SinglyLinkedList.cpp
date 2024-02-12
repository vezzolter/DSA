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

// Deep Copy Constructor
template<class T>
SLL<T>::SLL(const SLL& rhs) {
	// Initialize head pointer and size
	_head = nullptr;
	_size = 0;

	// Iterate and copy nodes
	Node<T>* current = rhs._head;
	while (current != nullptr) {
		// Create a new node for each node in the other list
		Node<T>* newNode = new Node<T>(current->_data);

		// Link it to the new list, by making it head
		if (_head == nullptr) {
			// No elements
			_head = newNode;
		}
		else {
			// Some elements, preserve them 
			Node<T>* tail = _head;
			while (tail->_next != nullptr) {
				tail = tail->_next;
			}
			tail->_next = newNode;
		}

		// Move to the next node in the other list
		current = current->_next;
		// Update the size
		_size++;
	}
}

// Deep copy assignment operator
template<class T>
SLL<T>& SLL<T>::operator=(const SLL& rhs) {
	// Check for self-assignment
	if (this == &rhs) 
		return *this;

	// Iterate and copy nodes
	Node<T>* current = rhs._head;
	while (current != nullptr) {
		// Create a new node for each node in the other list
		Node<T>* newNode = new Node<T>(current->_data);

		// Link it to the new list, by making it head
		if (_head == nullptr) {
			// No elements
			_head = newNode;
		}
		else {
			// Some elements, preserve them 
			Node<T>* tail = _head;
			while (tail->_next != nullptr) {
				tail = tail->_next;
			}
			tail->_next = newNode;
		}
	}

	// Move to the next node in the other list
	current = current->_next;
	// Update the size
	_size = rhs._size;
}

// Desctuctor
template<typename T>
SLL<T>::~SLL() { clear(); }



// --------------
// Element Access
// --------------

// Access the element at the specified index with modification
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

// Access the element at the specified index without modification
template<class T>
T& SLL<T>::operator[](const int index) const {
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
int SLL<T>::size() const { return _size; }



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
	// Update size of the list
	_size = 0;
}

// Inserts elements after the specified position in the container
template<class T>
void SLL<T>::insertAfter(const int index, const T& newData) {
	// TODO: range check
	
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

	// Update size of the list
	_size++;
}

// Removes an element at the specified position
template<class T>
void SLL<T>::eraseAfter(const int index) {
	// TODO: range check

	// Traverse to the node before the node to be erased
	Node<T>* current = _head;
	for (int i = 0; i < index; ++i) {
		current = current->_next;
	}

	// Store a pointer to the node to be removed
	Node<T>* temp = current->_next;
	// Update the next pointer of the current node to skip over the node to be removed
	current->_next = temp->_next;
	// Free up memory
	delete temp;
	// Update size of the list
	_size--;
}

// Prepends the given element value to the beginning of the container.
template<typename T>
void SLL<T>::pushFront(const T& newData) {
	// Create a new node with the given data
	Node<T>* newNode = new Node<T>(newData);

	// If list has elements
	if (_head != nullptr) {
		// Point newNode to current head
		newNode->_next = _head;
	}

	// Update head
	_head = newNode;
	// Update size of the list
	_size++;
}

// Removes the first element of the container.
template<class T>
void SLL<T>::popFront() {
	// TODO: range check

	// Move the head pointer to the next node
	Node<T>* temp = _head;
	_head = _head->_next;

	// Delete the original head node
	delete temp;
	// Update the size of the list
	_size--;
}

#endif