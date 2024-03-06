// Source file for simplified ADT: Linear Queue
// by vezzolter
// March 2, 2024

#ifndef LQ_CPP
#define LQ_CPP

#include "LinearQueue.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
template<class T>
LQ<T>::LQ() : _size(0), _front(nullptr), _rear(nullptr) {}

// Deep copy constructor
template<class T>
LQ<T>::LQ(const LQ& rhs) : _size(rhs._size), _front(nullptr), _rear(nullptr) {
	// Case: empty queue
	if (rhs._front == nullptr)
		return;

	// Create corresponding first node
	_front = new Node(rhs._front->_data);
	_rear = _front;

	// Copy other nodes
	Node* currentRhs = rhs._front->_next;
	while (currentRhs) {
		_rear->_next = new Node(currentRhs->_data);
		_rear = _rear->_next;
		currentRhs = currentRhs->_next;
	}
}

// Deep copy assignment operator
template<class T>
LQ<T>& LQ<T>::operator=(const LQ& rhs) {
	// Self-assignment guard
	if (this == &rhs)
		return *this;

	// Ensure that the destination list doesn't retain any of its existing elements
	while (_front) {
		Node* temp = _front;
		_front = _front->_next;
		delete temp;
	}

	// Set corresponding size
	_size = rhs._size;

	// Case: empty queue
	if (rhs._front == nullptr) {
		_front = _rear = nullptr;
	}
	else {
		// Create corresponding first node
		_front = new Node(rhs._front->_data);
		_rear = _front;

		// Copy other nodes
		Node* currentRhs = rhs._front->_next;
		while (currentRhs) {
			_rear->_next = new Node(currentRhs->_data);
			_rear = _rear->_next;
			currentRhs = currentRhs->_next;
		}
	}

	return *this;
}

// Destructor
template<class T>
LQ<T>::~LQ() {
	while (_front) {
		Node* temp = _front;
		_front = _front->_next;
		delete temp;
	}

	// Update the state
	_rear = nullptr;
	_size = 0;
}



// --------------
// Element Access
// --------------

// Accesses the first element in the container, no range check, allows modification
template<class T>
T& LQ<T>::front() { return _front->_data; }

// Accesses the first element in the container, no range check, denies modification
template<class T>
const T& LQ<T>::front() const { return _front->_data; }

// Accesses the last element in the container, no range check, allows modification
template<class T>
T& LQ<T>::rear() { return _rear->_data; }

// Accesses the last element in the container, no range check, denies modification
template<class T>
const T& LQ<T>::rear() const { return _rear->_data; }



// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool LQ<T>::empty() const { return _size == 0; }

// Returns the number of elements in the container
template<typename T>
size_t LQ<T>::size() const { return _size; }



// ---------
// Modifiers
// ---------

// Pushes the given element to the end of the queue
template<class T>
void LQ<T>::push(const T& newData) {
	// Create a new node with the given data
	Node* newNode = new Node(newData);

	// Case: empty queue
	if (_front == nullptr) {
		_front = _rear = newNode;
	}
	else {
		_rear->_next = newNode;
		_rear = newNode;
	}

	// Update the size
	++_size;
}

// Removes an element from the front of the queue
// Note: with no bounds check, assumes that queue contains at least 1 element
template<class T>
void LQ<T>::pop() {
	// Case: empty queue
	if (_front == nullptr)
		return;
	
	// Move the head pointer to the next node
	Node* temp = _front;
	_front = _front->_next;
	delete temp;

	// Case: last element
	if (_front == nullptr)
		_rear = nullptr;

	// Update the size
	--_size;
}


#endif