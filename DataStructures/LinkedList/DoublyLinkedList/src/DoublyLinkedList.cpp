// Source file for simplified ADT: Doubly Linked List
// by vezzolter
// February 13, 2024

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

//// Parametrized constructor
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

	// Create corresponding first node
	_head = new Node<T>(rhs._head->_data);

	// Initialize traversal pointers
	Node<T>* currentRhs = rhs._head->_next;
	Node<T>* current = _head;

	// Copy other nodes
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

	// Create corresponding first node
	_head = new Node<T>(rhs._head->_data);

	// Initialize traversal pointers
	Node<T>* currentRhs = rhs._head->_next;
	Node<T>* current = _head;

	// Copy other nodes
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
	// TODO: range check
 
	// Traverse to the required node
	Node<T>* current = getStartingNode(index);

	return current->_data;
}

// Access the element at the specified index, denies modification
template<class T>
T& DLL<T>::operator[](const int index) const {
	// TODO: range check

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
	// Case: empty list
	if (!_head)
		return;

	// Traverse the list and deallocate memory for each node
	while (_head) {
		Node<T>* current = _head;
		_head = _head->_next;
		delete current;
	}

	// Update the state of list
	_size = 0;
	_tail = _head = nullptr;
}

// Inserts elements after the specified position in the container
template<class T>
void DLL<T>::insert(const int index, const T& newData) {
	// TODO: range check

	if (index == 0) {
		pushFront(newData);
	}
	else if (index == _size - 1) {
		pushBack(newData);
	}
	else {
		// Insert new node at specified position
		Node<T>* prevNode = getStartingNode(index - 1);
		Node<T>* newNode = new Node<T>(newData);
		newNode->_next = prevNode->_next;
		newNode->_prev = prevNode;
		prevNode->_next = newNode;

		// Update the size
		++_size;
	}
}

// Removes an element at the specified position
template<class T>
void DLL<T>::erase(const int index) {
	// TODO: range check

	if (index == 0) {
		popFront();
	}
	else if (index == _size - 1) {
		popBack();
	}
	else {
		// Remove specified node
		Node<T>* prevNode = getStartingNode(index - 1);
		Node<T>* nodeToErase = prevNode->_next;
		prevNode->_next = nodeToErase->_next;
		nodeToErase->_next->_prev = prevNode;
		delete nodeToErase;

		// Update the size
		--_size;
	}
}

// Prepends the given element value to the beginning of the container
template<typename T>
void DLL<T>::pushFront(const T& newData) {
	// Create a new node with the given data
	Node<T>* newNode = new Node<T>(newData);

	// Case: empty list
	if (_size == 0) {
		_head = _tail = newNode;
	}
	else {
		// Push front
		_head->_prev = newNode;
		newNode->_next = _head;
		_head = newNode;
	}
	
	// Update the size
	++_size;
}

// Removes the first element of the container
template<class T>
void DLL<T>::popFront() {
	// TODO: range check

	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}
	
	// Move the head pointer to the next node
	Node<T>* temp = _head;
	_head = _head->_next;
	_head->_prev = nullptr;
	delete temp;

	// Update the size
	--_size;
}

// Appends the given element to the end of the container
template<class T>
void DLL<T>::pushBack(const T& newData) {
	// Create a new node with the given data
	Node<T>* newNode = new Node<T>(newData);

	// Case: empty list
	if (_size == 0) { 
		_head = _tail = newNode;
	}
	else {
		// Push back
		_tail->_next = newNode;
		newNode->_prev = _tail;
		_tail = newNode;
	}
	

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