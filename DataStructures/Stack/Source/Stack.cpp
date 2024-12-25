// Title:   Source file for Stack
// Authors: by vezzolter
// Date:    March 2, 2024
// ----------------------------------------------------------------------------


#include "Stack.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
template<typename T>
Stack<T>::Stack() : _size(0), _top(nullptr) {}

// Deep copy constructor
template<class T>
Stack<T>::Stack(const Stack& rhs) : _size(0), _top(nullptr) {
	// Iterate through the nodes of rhs stack and copy each element
	Node* rhsCurrent = rhs._top;
	Node* prevNode = nullptr;
	while (rhsCurrent != nullptr) {
		// Create a new node with the same data
		Node* newNode = new Node(rhsCurrent->_data);

		// Attach the new node to the current stack
		if (prevNode == nullptr)
			_top = newNode;
		else
			prevNode->_next = newNode;

		// Move to the next node in rhs stack
		prevNode = newNode;
		rhsCurrent = rhsCurrent->_next;
	}

	// Update the size
	_size = rhs._size;
}

// Deep copy assignment operator
template<class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) {
	// Self-assignnment guard
	if (this == &rhs)
		return *this;

	// Ensure that the destination stack doesn't retain any of its existing elements
	while (!empty())
		pop();

	// Set corresponding size
	_size = rhs._size;

	// Case: empty stack
	if (rhs._top == nullptr) {
		_top = nullptr;
	}
	else {
		// Perform deep copy from rhs to this stack
		Node* rhsCurrent = rhs._top;
		while (rhsCurrent != nullptr) {
			push(rhsCurrent->data);
			rhsCurrent = rhsCurrent->next;
		}
	}

	return *this;
}

// Destructor
template<typename T>
Stack<T>::~Stack() {
	while (!empty())
		pop();
}



// --------------
// Element Access
// --------------

// Accesses the last element in the container, no range validation, allows modification
template<class T>
T& Stack<T>::peek() { return _top->_data; }

// Accesses the last element in the container, no range validation, denies modification
template<class T>
const T& Stack<T>::peek() const { return _top->_data; };



// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool Stack<T>::empty() const { return _size == 0; }

// Returns the number of elements in the container
template<typename T>
int Stack<T>::size() const { return _size; }



// ---------
// Modifiers
// ---------

// Appends the given element to the end of the container
template<class T>
void Stack<T>::push(const T& newData) {
	// Create a new node with the given data
	Node* newNode = new Node(newData);

	// Case: empty stack
	if (_top == nullptr) {
		_top = newNode;
	}
	else {
		newNode->_next = _top;
		_top = newNode;
	}

	// Update the size
	++_size;
}

// Removes the last element of the container
// Note: with no bounds check, assumes that stack contains at least 1 element
template<class T>
void Stack<T>::pop() {
	// Case: empty stack
	if (_top == nullptr)
		return;

	// Move the top ptr to the next node
	Node* temp = _top;
	_top = _top->_next;
	delete temp;

	// Update the size
	--_size;
}