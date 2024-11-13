// Title:   Source file for Doubly Linked List
// Authors: by vezzolter
// Date:    February 13, 2024
// ----------------------------------------------------------------------------


#include "DoublyLinkedList.h"


// ------------------
// Facilitator Method
// ------------------

// Determines whether to start traversal from the head or tail
DLL::Node* DLL::getStartingNode(int pos) const {
	Node* startingNode;
	int distanceFromHead = pos;
	int distanceFromTail = _size - pos - 1;

	if (distanceFromHead <= distanceFromTail) {
		startingNode = _head;
		for (int i = 0; i < pos; ++i) {
			startingNode = startingNode->_next;
		}
	} else {
		startingNode = _tail;
		for (int i = _size - 1; i > pos; --i) {
			startingNode = startingNode->_prev;
		}
	}

	return startingNode;
}


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty list
DLL::DLL() : _size(0), _head(nullptr), _tail(nullptr) {}

// Constructs a list with 'size' copies of elements with 'data' value
DLL::DLL(int size, int data) :
	_size(size), _head(nullptr), _tail(nullptr) {
	// Create the head node
	_head = new Node(data);

	// Create rest of the nodes
	Node* curr = _head;
	for (int i = 1; i < size; ++i) {
		Node* newNode = new Node(data);
		curr->_next = newNode;
		newNode->_prev = curr;
		curr = newNode;
	}

	// Set tail to the last created node
	_tail = curr;

}

// Constructs a list with the contents of 'other'
DLL::DLL(const DLL& other) 
	: _size(other._size) {
	// Case: empty list
	if (!other._head) {
		_head = _tail = nullptr;
		return;
	}

	// Create corresponding first node
	_head = new Node(other._head->_data);

	// Initialize traversal pointers
	Node* currSrc = other._head->_next;
	Node* curr = _head;

	// Copy other nodes
	while (currSrc) {
		curr->_next = new Node(currSrc->_data);
		curr->_next->_prev = curr;
		curr = curr->_next;
		currSrc = currSrc->_next;
	}

	// Maintain proper reference to the end
	_tail = curr;
}

// Replaces the contents with a copy of the contents of 'rhs'
DLL& DLL::operator=(const DLL& rhs) {
	// Self-assignment guard
	if (this == &rhs) { return *this; }

	// Ensure that the destination list doesn't retain any of its existing elements
	clear();

	// Set corresponding size
	_size = rhs._size;

	// Case: empty list
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return *this;
	}

	// Create corresponding first node
	_head = new Node(rhs._head->_data);

	// Initialize traversal pointers
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;

	// Copy other nodes
	for (; currentRhs; ) {
		current->_next = new Node(currentRhs->_data);
		current->_next->_prev = current;
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Maintain proper reference to the end
	_tail = current;

	return *this;
}

// Destructs the list
DLL::~DLL() { clear(); }


// ----------------
//  Element Access
// ----------------

// Returns a modifiable reference to the first element
int& DLL::front() { return _head->_data; }

// Returns a non-modifiable reference to the first element
const int& DLL::front() const { return _head->_data; }

// Returns a modifiable reference to the last element
int& DLL::back() { return _tail->_data; }

// Returns a non-modifiable reference to the last element
const int& DLL::back() const { return _tail->_data; }


// ----------
//  Capacity
// ----------

// Returns true if list has no elements
bool DLL::empty() const { return _size == 0; }

// Returns the number of stored elements
int DLL::size() const { return _size; }


// -----------
//  Modifiers
// -----------

// Inserts a copy of 'data' before 'pos'
void DLL::insert(const int pos, const int& data) {
	if (pos == 0) {
		pushFront(data);
	} else if (pos == _size - 1) {
		pushBack(data);
	} else {
		// Insert new node at specified position
		Node* prevNode = getStartingNode(pos - 1);
		Node* newNode = new Node(data);
		newNode->_next = prevNode->_next;
		newNode->_prev = prevNode;
		prevNode->_next = newNode;

		// Reflect new element on size
		++_size;
	}
}

// Removes the element at 'pos'
void DLL::erase(const int pos) {
	if (pos == 0) {
		popFront();
	} else if (pos == _size - 1) {
		popBack();
	} else {
		// Remove specified node
		Node* prevNode = getStartingNode(pos - 1);
		Node* nodeToErase = prevNode->_next;
		prevNode->_next = nodeToErase->_next;
		nodeToErase->_next->_prev = prevNode;
		delete nodeToErase;

		// Reflect removed element on size
		--_size;
	}
}

// Prepends the given 'data' to the beginning of the list
void DLL::pushFront(const int& data) {
	// Create a new node with the given data
	Node* newNode = new Node(data);

	// Case: empty list
	if (_size == 0) {
		_head = _tail = newNode;
	} else {
		// Push front
		_head->_prev = newNode;
		newNode->_next = _head;
		_head = newNode;
	}

	// Reflect new element on size
	++_size;
}

// Removes the first element of the list
void DLL::popFront() {
	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the head pointer to the next node
	Node* temp = _head;
	_head = _head->_next;
	_head->_prev = nullptr;
	delete temp;

	// Reflect removed element on size
	--_size;
}

// Appends the given 'data' to the end of the list
void DLL::pushBack(const int& data) {
	// Create a new node with the given data
	Node* newNode = new Node(data);

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

	// Reflect new element on size
	++_size;
}

// Removes the last element of the list
void DLL::popBack() {
	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the tail pointer to the previous node
	_tail = _tail->_prev;
	delete _tail->_next;
	_tail->_next = nullptr;

	// Reflect removed element on size
	--_size;
}

// Reverses the order of the elements in the list
void DLL::reverse() {
	// Case: empty list, single element
	if (!_head || !_head->_next) { return; }
	
	// Preliminaries
	Node* curr = _head;
	Node* temp = nullptr;

	for (; curr; ) {
		// Swap prev and next via temp
		temp = curr->_prev;
		curr->_prev = curr->_next;
		curr->_next = temp;

		// Move iterating node ahead
		curr = curr->_prev;
	}

	// Swap the head and tail pointers
	temp = _head;
	_head = _tail;
	_tail = temp;
}

// Replaces the contents with 'size' copies of 'data'
void DLL::assign(int size, const int& data) {
	// Clear the existing contents
	clear();

	// Add 'size' nodes with 'data'
	for (int i = 0; i < size; ++i) { pushBack(data); }
}

// Replaces the contents with copies of those in the range [first, last)
//void DLLL::assign(const_iterator first, const_iterator last);

// Erases all elements from the list
void DLL::clear() {
	// Traverse the list and deallocate memory for each node
	for ( ; _head; ) {
		Node* curr = _head;
		_head = _head->_next;
		delete curr;
	}

	// Reset the list to an empty state
	_size = 0;
	_tail = _head = nullptr;
}

// Resizes the list to contain 'size' elements
void DLL::resize(int size, const int& data) {
	// Case 1: new size is the same 
	if (size == _size) { return; }

	// Case 2: new size is smaller
	if (size < _size) {
		// Get the end
		Node* curr = _head;
		for (int i = 1; i < size; ++i) { curr = curr->_next; }

		// Delete excessive nodes and upd ptr
		Node* toDelete = curr->_next;
		curr->_next = nullptr; // detach the rest of the list
		_tail = curr; // upd end

		// Delete remaining nodes
		for (; toDelete; ) {
			Node* temp = toDelete;
			toDelete = toDelete->_next;
			delete temp;
		}

	} else if (size > _size) {
		// Case 3: new size is greater

		// Get the end
		Node* curr = _tail;

		// Case: empty list
		if (!curr) {
			_head = new Node(data);
			curr = _head;
			_tail = _head;
		}

		// Add new nodes until reaching new size
		for (int i = _size; i < size; ++i) {
			Node* newNode = new Node(data);
			curr->_next = newNode;
			newNode->_prev = curr;
			curr = newNode;
		}

		// Update the tail to the last added node
		_tail = curr;
	}

	// Update size to the new size
	_size = size;
}

// Exchanges the contents of the list with those of 'other'
void DLL::swap(DLL& other) {
	// Case: the same list
	if (this == &other) { return; }

	// Swap the head pointers
	Node* tempHead = _head;
	_head = other._head;
	other._head = tempHead;

	// Swap the tail pointers
	Node* tempTail = _tail;
	_tail = other._tail;
	other._tail = tempTail;

	// Swap the sizes
	int tempSize = _size;
	_size = other._size;
	other._size = tempSize;
}