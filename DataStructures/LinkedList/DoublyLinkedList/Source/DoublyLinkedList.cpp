// Title:   Source file for Doubly Linked List
// Authors: by vezzolter
// Date:    February 13, 2024
// ----------------------------------------------------------------------------


#include "DoublyLinkedList.h"


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

	// Copy rest of nodes
	Node* currSrc = other._head->_next;
	Node* curr = _head;
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
	// // Prepare: check for self-assignment and deallocate any old memory
	if (this == &rhs) { return *this; }
	clear();

	// Set corresponding size
	_size = rhs._size;

	// Case: empty list
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return *this;
	}

	// Copy head node
	_head = new Node(rhs._head->_data);

	// Copy rest of nodes
	Node* currentRhs = rhs._head->_next;
	Node* curr = _head;
	for (; currentRhs; ) {
		curr->_next = new Node(currentRhs->_data);
		curr->_next->_prev = curr;
		curr = curr->_next;
		currentRhs = currentRhs->_next;
	}

	// Maintain proper reference to the end
	_tail = curr;

	return *this;
}

// Destructs the list
DLL::~DLL() {
	Node* curr = _head;
	for(; curr; ) {
		Node* next = curr->_next;
		delete curr;
		curr = next;
	}
	_head = _tail = nullptr;
	_size = 0;
}


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the list
DLL::Iterator DLL::begin() { return iterator(_head); }

// Returns an iterator to one past the last element of the list
DLL::Iterator DLL::end() { return iterator(nullptr); }

// Returns a const iterator to the first element of the list
DLL::ConstIterator DLL::cbegin() const { return const_iterator(_head); }

// Returns a const iterator to one past the last element of the list
DLL::ConstIterator DLL::cend() const { return const_iterator(nullptr); }


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
void DLL::insert(iterator pos, const int& data) {
	Node* nextNode = pos.operator->();
	Node* prevNode = nextNode->_prev;

	// Create the new node
	Node* newNode = new Node(data);
	newNode->_next = nextNode;
	newNode->_prev = prevNode;

	// Update pointers
	if (prevNode) { prevNode->_next = newNode; }
	if (nextNode) { nextNode->_prev = newNode; }

	// Reflect new element on size
	++_size;
}

// Removes the element at 'pos'
void DLL::erase(iterator pos) {
	// Case: wrong iterator
	if (pos == this->end()) { return; }

	Node* nodeToErase = pos.operator->();
	Node* prevNode = nodeToErase->_prev;
	Node* nextNode = nodeToErase->_next;

	// Update pointers to bypass nodeToErase
	if (prevNode) { prevNode->_next = nextNode; }
	if (nextNode) { nextNode->_prev = prevNode; }

	// Delete the specified node
	delete nodeToErase;

	// Reflect removed element on size
	--_size;
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
	// Case: empty list
	if (!_head) { return; }

	// Case: one element
	if (_size == 1) {
		delete _head;
		_head = _tail = nullptr; 
		_size = 0;
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
	// Case: empty list
	if (!_head) { return; }

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
void DLL::assign(const_iterator first, const_iterator last) {
	// Clear the existing contents
	clear();

	// Add each element from the iterator range
	for (auto it = first; it != last; ++it) { pushBack(*it); }
}

// Erases all elements from the list
void DLL::clear() {
	// Case: empty list
	if (!_head) { return; }

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
			--size; // adjust to account first node
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