// Title:   Source file for Circular Linked List
// Authors: by vezzolter
// Date:    February 15, 2024
// ----------------------------------------------------------------------------


#include "CircularLinkedList.h"


// --------------------
//  Compiler Generated
// --------------------

// Constructs an empty list
CLL::CLL() : _size(0), _head(nullptr) {}

// Constructs a list with 'size' copies of elements with 'val'
CLL::CLL(int size, int val)  : _size(size), _head(nullptr) {
	_head = new Node(val);

	Node* curr = _head;
	for (int i = 1; i < size; ++i) {
		curr->_next = new Node(val);
		curr = curr->_next;
	}

	// Last node should point to the first one
	curr->_next = _head;
}

// Constructs a list with the contents of 'other'
CLL::CLL(const CLL& other) : _size(other._size) {
	if (!other._head) {
		_head = nullptr;
		return;
	}

	_head = new Node(other._head->_data);

	// Iteration should be circular, i.e. until head again
	Node* currOther = other._head->_next;
	Node* curr = _head;
	for (; currOther != other._head; ) {
		curr->_next = new Node(currOther->_data);
		curr = curr->_next;
		currOther = currOther->_next;
	}

	// Last node should point to the first one
	curr->_next = _head;
}

// Replaces the contents with a copy of the contents of 'rhs'
CLL& CLL::operator=(const CLL& rhs) {
	if (this == &rhs) { return *this; }
	clear();
	_size = rhs._size;
	if (rhs._head == nullptr) {
		_head = nullptr;
		return *this;
	}

	_head = new Node(rhs._head->_data);

	// Iteration should be circular, i.e. until head again
	Node* currRhs = rhs._head->_next;
	Node* curr = _head;
	for (; currRhs != rhs._head; ) { 
		curr->_next = new Node(currRhs->_data);
		curr = curr->_next;
		currRhs = currRhs->_next;
	}

	// Last node should point to the first one
	curr->_next = _head;

	return *this;
}

// Performs final cleanup and terminates the object
CLL::~CLL() {
	Node* curr = _head;
	for (Node* next = nullptr; ; ) {
		next = curr->_next;
		delete curr;
		if (next == _head) { break; } // stop when loop back to the head
		curr = next;
	}

	_head = nullptr;
	_size = 0;
}


// -----------
//  Iterators
// -----------

// Returns an iterator to the first element of the list
CLL::Iterator CLL::begin() { return iterator(_head, _head); }

// Returns an iterator to one past the last element of the list
CLL::Iterator CLL::end() { return iterator(nullptr, _head); }

// Returns a const iterator to the first element of the list
CLL::ConstIterator CLL::begin() const { return const_iterator(_head, _head); }

// Returns a const iterator to one past the last element of the list
CLL::ConstIterator CLL::end() const { return const_iterator(nullptr, _head); }

// Explicitly returns a const iterator to the first element of the list
CLL::ConstIterator CLL::cbegin() const { return const_iterator(_head, _head); }

// Explicitly returns a const iterator to one past the last element of the list
CLL::ConstIterator CLL::cend() const { return const_iterator(nullptr, _head); }


// ----------------
//  Element Access
// ----------------

// Returns a modifiable reference to the first element
int& CLL::front() { return _head->_data; }

// Returns a non-modifiable reference to the first element
const int& CLL::front() const { return _head->_data; }


// ----------
//  Capacity
// ----------

// Returns true if list has no elements
bool CLL::empty() const { return _size == 0; }

// Returns the number of stored elements (nodes)
int CLL::size() const { return _size; }


// -----------
//  Modifiers
// -----------

// Inserts a copy of 'val' after 'pos'
void CLL::insertAfter(iterator pos, const int& val) {
	// Case: invalid or end iterator
	if (pos == this->end() || _head == nullptr) { return; }

	Node* curr = pos.operator->();
	Node* newNode = new Node(val);

	// Handle circularity: check if inserting after the last node
	if (curr->_next == _head) {
		newNode->_next = _head;
		curr->_next = newNode;
	} else {
		newNode->_next = curr->_next;
		curr->_next = newNode;
	}

	++_size;
}

// Removes the element after 'pos'.
void CLL::eraseAfter(iterator pos) {
	// Case: wrong iterator
	if (pos == this->end()) { return; }

	Node* curr = pos.operator->();

	// Remove node (if there is one after the current)
	if (curr->_next) {
		Node* nodeToDelete = curr->_next;

		// Handle circularity: check if deleting the last node
		if (nodeToDelete == _head) {
			curr->_next = _head->_next;
			delete _head;
			_head = curr->_next;
		} else {
			curr->_next = nodeToDelete->_next;
			delete nodeToDelete;
		}
	}

	--_size;
}


// Prepends the given 'val' to the beginning of the list
void CLL::pushFront(const int& val) {
	Node* newNode = new Node(val);

	if (!_head) {
		// Case: empty list
		newNode->_next = newNode; // point to itself to maintain circularity
		_head = newNode;         
	} else {
		// Maintain circularity via tail pointer,
        // whose _next will allow to link back
		Node* tail = _head;
		for (; tail->_next != _head; ) { tail = tail->_next; }
		newNode->_next = _head;
		tail->_next = newNode;
		_head = newNode;  
	}

	++_size;
}


// Removes the first element of the list
void CLL::popFront() {
	// Case: empty list
	if (!_head) { return; }

	// Case: one element
	if (_size == 1) {
		delete _head;
		_head = nullptr;
		_size = 0;
		return;
	}

	// Maintain circularity via tail pointer,
	// whose _next will allow to link back
	Node* temp = _head;
	Node* tail = _head;
	for (; tail->_next != _head; ) { tail = tail->_next; }
	_head = _head->_next;
	tail->_next = _head;
	delete temp;

	--_size;
}

// Reverses the order of the elements in the list
void CLL::reverse() {
	// Case: empty list or single-element list
	if (!_head || _head->_next == _head) { return; }

	Node* prev = nullptr;
	Node* curr = _head;
	Node* next = nullptr;

	do {
		next = curr->_next; 
		curr->_next = prev; 
		prev = curr;       
		curr = next;        
	} while (curr != _head); // stop when loop back to the head

	// Last node should point to the first one
	_head->_next = prev; 
	_head = prev;        
}

// Replaces the contents with 'size' copies of 'val'
void CLL::assign(int size, const int& val) {
	clear();

	// Create the first node
	_head = new Node(val);
	Node* curr = _head;

	// Advance the iterator and construct the rest of the list
	for (int i = 1; i < size; ++i) {
		curr->_next = new Node(val);
		curr = curr->_next;
	}

	// Last node should point to the first one
	curr->_next = _head;

	_size = size;
}

// Replaces the contents with copies of those in the range [first, last)
void CLL::assign(iterator first, iterator last) {
	clear();

	// Create the first node
	_head = new Node(*first);
	Node* curr = _head;
	_size = 1; // Initialize size since we've added the first node

	// Advance the iterator and construct the rest of the list
	for (auto it = ++first; it != last; ++it) {
		curr->_next = new Node(*it);
		curr = curr->_next;
		++_size;
	}

	// Last node should point to the first one
	curr->_next = _head;
}

// Erases all elements from the list
void CLL::clear() {
	// Case: empty list
	if (!_head) { return; }

	// Break the circular connection first
	Node* tail = _head;
	for (; tail->_next != _head; ) { tail = tail->_next; }
	tail->_next = nullptr;

	for (; _head; ) {
		Node* curr = _head;
		_head = _head->_next;
		delete curr;
	}

	_size = 0;
	_head = nullptr;
}


// Resizes the list to contain 'size' elements
void CLL::resize(int size, const int& val) {
	// Case 1: new size is the same 
	if (size == _size) { return; }

	// Case 2: new size is smaller
	if (size < _size) {
		Node* curr = _head;
		for (int i = 1; i < size; ++i) { curr = curr->_next; }

		Node* toDelete = curr->_next;
		curr->_next = _head; // Maintain circularity
		for (; toDelete; ) {
			Node* temp = toDelete;
			toDelete = toDelete->_next;
			delete temp;
		}

	} else if (size > _size) {
		// Case 3: new size is greater

		if (!_head) {
			_head = new Node(val);
			_head->_next = _head; // Maintain circularity
			Node* curr = _head;

			for (int i = 1; i < size; ++i) {
				Node* newNode = new Node(val);
				curr->_next = newNode;
				newNode->_next = _head; // Maintain circularity
				curr = newNode;
			}

		} else {
			// Get the tail of the current list
			Node* curr = _head;
			for (; curr->_next != _head;) { curr = curr->_next; }

			for (int i = _size; i < size; ++i) {
				Node* newNode = new Node(val);
				curr->_next = newNode;
				newNode->_next = _head; // Maintain circularity
				curr = newNode;
			}
		}
	}

	_size = size;
}

// Exchanges the contents of the list with those of 'other'
void CLL::swap(CLL& other) {
	// Case: the same list
	if (this == &other) { return; }

	Node* head = _head;
	_head = other._head;
	other._head = head;

	int size = _size;
	_size = other._size;
	other._size = size;
}