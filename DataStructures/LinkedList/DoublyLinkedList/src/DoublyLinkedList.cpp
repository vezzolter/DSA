// Source file for simplified ADT: Singly Linked List
// by vezzolter
// February 3, 2024

#ifndef DLL_CPP
#define DLL_CPP

#include "DoublyLinkedList.h"


// ------------------
// Facilitator Method
// ------------------

// Determine whether to start traversal from the head or tail
template<typename T>
typename DLL<T>::Node<T>* DLL<T>::getStartingNode(int index) const {
	Node<T>* startingNode;
	int distanceFromHead = index;
	int distanceFromTail = _size - index - 1;

	if (distanceFromHead <= distanceFromTail) {
		startingNode = _head;
		for (int i = 0; i < index; ++i) {
			startingNode = startingNode->_next;
		}
	}
	else {
		startingNode = _tail;
		for (int i = _size - 1; i > index; --i) {
			startingNode = startingNode->_prev;
		}
	}

	return startingNode;
}



// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
template<typename T>
DLL<T>::DLL() : _size(0), _head(nullptr), _tail(nullptr) {}

//// Parametrized Constructor
//template<class T>
//DLL<T>::DLL(const std::initializer_list<T>& initList) { }

// Deep copy constructor
template<class T>
DLL<T>::DLL(const DLL& rhs) {
	// Set corresponding size
	_size = rhs._size;

	// Case: empty list, avoid dangling pointers
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return;
	}

	// Create corresponding node
	_head = new Node<T>(rhs._head->_data);

	// Initialize traversal pointers
	Node<T>* currentRhs = rhs._head->_next;
	Node<T>* current = _head;

	// Copy elements
	while (currentRhs) {
		current->_next = new Node<T>(currentRhs->_data);
		current->_next->_prev = current;
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Maintain proper reference to the end
	_tail = current;
}

// Deep copy assignment operator
template<class T>
DLL<T>& DLL<T>::operator=(const DLL& rhs) {
	// Self-assignment guard
	if (this == &rhs) 
		return *this;

	// Ensure that the destination list doesn't retain any of its existing elements
	clear();

	// Set corresponding size
	_size = rhs._size;

	// Case: empty list, avoid dangling pointers
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return *this;
	}

	// Create corresponding node
	_head = new Node<T>(rhs._head->_data);

	// Initialize traversal pointers
	Node<T>* currentRhs = rhs._head->_next;
	Node<T>* current = _head;

	// Copy elements
	while (currentRhs) {
		current->_next = new Node<T>(currentRhs->_data);
		current->_next->_prev = current;
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Maintain proper reference to the end
	_tail = current;

	return *this;
}

// Destructor
template<typename T>
DLL<T>::~DLL() { clear(); }



// --------------
// Element Access
// --------------

// Access the element at the specified index, allows modification
template<class T>
T& DLL<T>::operator[](const int index) {
	// TODO: potential range check
 
	// Traverse to the required node
	Node<T>* current = getStartingNode(index);

	return current->_data;
}

// Access the element at the specified index, denies modification
template<class T>
T& DLL<T>::operator[](const int index) const {
	// TODO: potential range check

	// Traverse to the required node
	Node<T>* current = getStartingNode(index);

	return current->_data;
}

// Returns a reference to the first element in the container, allows modification
template<class T>
T& DLL<T>::front() {
	// TODO: handle empty case

	return _head->_data;
}

// Returns a reference to the first element in the container, denies modification
template<class T>
const T& DLL<T>::front() const {
	// TODO: handle empty case

	return _head->_data;
}

// Returns a reference to the last element in the container, allows modification
template<class T>
T& DLL<T>::back() {
	// TODO: handle empty case

	return _tail->_data;
}

// Returns a reference to the last element in the container, denies modification
template<class T>
const T& DLL<T>::back() const {
	// TODO: handle empty case

	return _tail->_data;
}



// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool DLL<T>::empty() const { return _size == 0; }

// Returns the number of elements in the container
template<typename T>
int DLL<T>::size() const { return _size; }



// ---------
// Modifiers
// ---------

// Erases all elements from the container
template<typename T>
void DLL<T>::clear() {
	// Traverse the list and deallocate memory for each node
	while (_head) {
		Node<T>* temp = _head;
		_head = _head->_next;
		delete temp;
	}

	// Update the size and pointers
	_tail = _head = nullptr;
	_size = 0;
}

// Inserts elements after the specified position in the container
template<class T>
void DLL<T>::insert(const int index, const T& newData) {
	// TODO: range check

	// Create a new node with the given data
	Node<T>* current = getStartingNode(index);
	Node<T>* newNode = new Node<T>(newData);
	newNode->_next = current->_next;
	newNode->_prev = current;
	current->_next = newNode;

	// Insert the new node after the current node
	if (newNode->_next) {
		newNode->_next->_prev = newNode;
	}
	else {
		// If the new node is inserted at the end, update the tail pointer
		_tail = newNode;
	}

	// Update the size
	++_size;
}

// Removes an element at the specified position
template<class T>
void DLL<T>::erase(const int index) {
	// TODO: range check

	// Save a pointer to the node to be erased
	Node<T>* current = getStartingNode(index);
	Node<T>* nodeToErase = current->_next;

	// Update the pointers to remove the node from the list
	current->_next = nodeToErase->_next;
	if (nodeToErase->_next) {
		nodeToErase->_next->_prev = current;
	}
	else {
		_tail = current;
	}

	// Delete the node
	delete nodeToErase;

	// Update the size
	--_size;
}

// Prepends the given element value to the beginning of the container.
template<typename T>
void DLL<T>::pushFront(const T& newData) {
	// Create a new node with the given data
	Node<T>* newNode = new Node<T>(newData);

	// If the list is empty, set the new node as both head and tail
	if (_size == 0) { _head = _tail = newNode; }

	// Push front
	_head->_prev = newNode;
	newNode->_next = _head;
	_head = newNode;

	// Increase the size of the list
	++_size;
}

// Removes the first element of the container.
template<class T>
void DLL<T>::popFront() {
	// TODO: range check

	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the head pointer to the next node
	_head = _head->_next;
	delete _head->_prev;
	_head->_prev = nullptr;

	// Update the size
	--_size;
}

// Appends the given element to the end of the container.
template<class T>
void DLL<T>::pushBack(const T& newData) {
	// Create a new node with the given data
	Node<T>* newNode = new Node<T>(newData);

	// If the list is empty, set the new node as both head and tail
	if (_size == 0) { _head = _tail = newNode; }

	// Push back
	_tail->_next = newNode;
	newNode->_prev = _tail;
	_tail = newNode;

	// Update the size
	++_size;
}

// Removes the last element of the container
template<class T>
void DLL<T>::popBack() {
	// TODO: range check

	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the tail pointer to the previous node
	_tail = _tail->_prev;
	delete _tail->_next;
	_tail->_next = nullptr;

	// Update the size
	--_size;
}

#endif