// Source file for simplified ADT: Circular Linked List
// by vezzolter
// February 15, 2024

#ifndef CLL_CPP
#define CLL_CPP

#include "CircularLinkedList.h"


// ------------------
// Facilitator Method
// ------------------

// Determine whether to start traversal from the head or tail
template<typename T>
typename CLL<T>::Node<T>* CLL<T>::getStartingNode(int index) const {
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
CLL<T>::CLL() : _size(0), _head(nullptr), _tail(nullptr) {}

//// Parametrized constructor
//template<class T>
//CLL<T>::CLL(const std::initializer_list<T>& initList) { }

// Deep copy constructor
template<class T>
CLL<T>::CLL(const CLL& rhs) : _size(rhs._size) {
	// Case: empty list
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return;
	}

	_head = new Node<T>(rhs._head->_data);
	Node<T>* currentRhs = rhs._head->_next;
	Node<T>* current = _head;
	Node<T>* originalHead = rhs._head; // Save the original head of the list

	while (currentRhs != originalHead) {
		current->_next = new Node<T>(currentRhs->_data);
		current->_next->_prev = current;
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Make the list circular
	_tail = current;
	_tail->_next = _head;
	_head->_prev = _tail;
}

// Deep copy assignment operator
template<class T>
CLL<T>& CLL<T>::operator=(const CLL& rhs) {
	// Self-assignment guard
	if (this == &rhs)
		return *this;

	clear();
	_size = rhs._size;

	// Case: empty list
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return *this;
	}

	_head = new Node<T>(rhs._head->_data);
	Node<T>* currentRhs = rhs._head->_next;
	Node<T>* current = _head;
	Node<T>* originalHead = rhs._head; // Save the original head of the list

	while (currentRhs != originalHead) {
		current->_next = new Node<T>(currentRhs->_data);
		current->_next->_prev = current;
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Make the list circular
	_tail = current;
	_tail->_next = _head;
	_head->_prev = _tail;

	return *this;
}

// Destructor
template<typename T>
CLL<T>::~CLL() { clear(); }



// --------------
// Element Access
// --------------

// Accesses the element at the specified index, no range check, allows modification
template<class T>
T& CLL<T>::operator[](const int index) {
	// Traverse to the required node
	Node<T>* current = getStartingNode(index);
	return current->_data;
}

// Accesses the element at the specified index, no range check, denies modification
template<class T>
const T& CLL<T>::operator[](const int index) const {
	// Traverse to the required node
	Node<T>* current = getStartingNode(index);
	return current->_data;
}

// Accesses the first element in the container, no range check, allows modification
template<class T>
T& CLL<T>::front() { return _head->_data; }

// Accesses the first element in the container, no range check, denies modification
template<class T>
const T& CLL<T>::front() const { return _head->_data; }

// Accesses the last element in the container, no range check, allows modification
template<class T>
T& CLL<T>::back() { return _tail->_data; }

// Accesses the last element in the container, no range check, denies modification
template<class T>
const T& CLL<T>::back() const { return _tail->_data; }



// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool CLL<T>::empty() const { return _size == 0; }

// Returns the number of elements in the container
template<typename T>
int CLL<T>::size() const { return _size; }



// ---------
// Modifiers
// ---------

// Erases all elements from the container
template<typename T>
void CLL<T>::clear() {
	// Case: empty list
	if (!_head)
		return;

	// Traverse the list and deallocate memory for each node
	Node<T>* current = _head;
	while (current) {
		Node<T>* temp = current;
		current = current->_next;
		delete temp;

		// If we've reached the original head, exit the loop
		if (current == _head)
			break;
	}

	// Update the state of list
	_head = _tail = nullptr;
	_size = 0;
}

// Inserts elements after the specified position in the container
// Note: with no bounds check, assumes that index is correct
template<class T>
void CLL<T>::insert(const int index, const T& newData) {
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
		prevNode->_next->_prev = newNode; // Update next node's previous pointer
		prevNode->_next = newNode;

		++_size;
	}
}

// Removes an element at the specified position
// Note: with no bounds check, assumes that index is correct
template<class T>
void CLL<T>::erase(const int index) {
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
		--_size;
	}
}

// Prepends the given element value to the beginning of the container
template<typename T>
void CLL<T>::pushFront(const T& newData) {
	Node<T>* newNode = new Node<T>(newData);

	// Case: empty list
	if (_size == 0) { 
		_head = _tail = newNode;
		newNode->_next = newNode->_prev = newNode; // Make the list circular
	}
	else {
		// Push front
		newNode->_next = _head;
		newNode->_prev = _tail;
		_head->_prev = newNode;
		_head = newNode;

		// Update the tail's next pointer to point to the new head
		_tail->_next = _head;
	}

	++_size;
}

// Removes the first element of the container
// Note: with no bounds check, assumes that list contains at least 1 element
template<class T>
void CLL<T>::popFront() {
	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	Node<T>* temp = _head;
	_head = _head->_next;
	_head->_prev = _tail; // Update head's previous pointer to point to tail
	_tail->_next = _head; // Update tail's next pointer to point to head
	delete temp;

	--_size;
}

// Appends the given element to the end of the container
template<class T>
void CLL<T>::pushBack(const T& newData) {
	Node<T>* newNode = new Node<T>(newData);

	// Case: empty list
	if (_size == 0) { 
		_head = _tail = newNode;
		newNode->_next = newNode->_prev = newNode; // Make the list circular
	}
	else {
		// Push back
		newNode->_next = _head;
		newNode->_prev = _tail;
		_tail->_next = newNode;
		_tail = newNode;

		// Update the head's previous pointer to point to the new tail
		_head->_prev = _tail;
	}

	++_size;
}

// Removes the last element of the container
// Note: with no bounds check, assumes that list contains at least 1 element
template<class T>
void CLL<T>::popBack() {
	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the tail pointer to the previous node
	Node<T>* temp = _tail;
	_tail = _tail->_prev;
	_tail->_next = _head; // Update tail's next pointer to point to head
	delete temp;

	--_size;
}


#endif