// Title:   Header file for Circular Linked List
// Authors: by vezzolter
// Date:    February 15, 2024
// ----------------------------------------------------------------------------


#ifndef CLL_H
#define CLL_H


class CLL {
private:
	struct Node;
	int _size;
	Node* _head;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	CLL();
	CLL(int size, int data);
	CLL(const CLL& other);
	CLL(CLL&& other)          = delete;
	CLL& operator=(const CLL& rhs);
	CLL& operator=(CLL&& rhs) = delete;
	~CLL();

	// -----------
	//  Iterators
	// -----------
	class Iterator;
	using iterator = Iterator;
	iterator begin();
	iterator end();
	class ConstIterator;
	using const_iterator = ConstIterator;
	const_iterator cbegin() const;
	const_iterator cend() const;

	// ----------------
	//  Element Access
	// ----------------
	int& front();
	const int& front() const;

	// ----------
	//  Capacity
	// ----------
	bool empty() const;
	int size() const;

	// -----------
	//  Modifiers
	// -----------
	void insertAfter(iterator pos, const int& data);
	void eraseAfter(iterator pos);
	void pushFront(const int& data);
	void popFront();
	void reverse();
	void assign(int size, const int& data);
	void assign(const_iterator first, const_iterator last);
	void clear();
	void resize(int size, const int& data);
	void swap(CLL& other);
};


struct CLL::Node {
public:
	int _data;
	Node* _next;

	// --------------------
	//  Compiler Generated
	// --------------------
	Node() : _data(0), _next(nullptr) {}
	Node(const int& data, Node* next = nullptr) : _data(data), _next(next) {}
	Node(const Node& other)          = delete;  // no copying/moving to
	Node(Node&& other)               = delete;  // ensure uniqueness of 
	Node& operator=(const Node& rhs) = delete;  // the node within the list
	Node& operator=(Node&& rhs)      = delete;  // and prevent accidental 
	~Node()                          = default; // duplicates or dangling nodes
};


class CLL::Iterator {
private:
	Node* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	Iterator()                               = default;
	explicit Iterator(Node* ptr) : _ptr(ptr) {}
	Iterator(const Iterator& other)          = default;
	Iterator(Iterator&& other)               = default;
	Iterator& operator=(const Iterator& rhs) = default;
	Iterator& operator=(Iterator&& rhs)      = default;
	~Iterator()                              = default;

	// ----------------------
	//  Overloaded Operators
	// ----------------------

	// Returns a reference to the data of a node
	int& operator*() { return _ptr->_data; }

	// Returns a pointer to the entire node, allowing access to its members
	Node* operator->() { return _ptr; }

	// Advances the iterator to the next element (pre-increment)
	Iterator& operator++() {
		_ptr = _ptr->_next;
		return *this;
	}

	// Advances the iterator to the next element, returning the previous state
	Iterator operator++(int) {
		Iterator temp = *this;
		_ptr = _ptr->_next;
		return temp;
	}

	// Returns true if two iterators point to the same element
	friend bool operator==(const CLL::Iterator& lhs, const CLL::Iterator& rhs) {
		return lhs._ptr == rhs._ptr;
	}

	// Returns true if two iterators point to different elements
	friend bool operator!=(const CLL::Iterator& lhs, const CLL::Iterator& rhs) {
		return lhs._ptr != rhs._ptr;
	}
};


class CLL::ConstIterator {
private:
	const Node* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	ConstIterator()                                    = default;
	explicit ConstIterator(const Node* ptr) : _ptr(ptr) {}
	ConstIterator(const ConstIterator& other)          = default;
	ConstIterator(ConstIterator&& other)               = default;
	ConstIterator& operator=(const ConstIterator& rhs) = default;
	ConstIterator& operator=(ConstIterator&& rhs)      = default;
	~ConstIterator()                                   = default;

	// ----------------------
	//  Overloaded Operators
	// ----------------------

	// Returns a const reference to the data of a node
	const int& operator*() const { return _ptr->_data; }

	// Returns a const pointer to the entire node, allowing access to its members
	const Node* operator->() const { return _ptr; }

	// Advances the iterator to the next element (pre-increment)
	ConstIterator& operator++() {
		_ptr = _ptr->_next;
		return *this;
	}

	// Advances the iterator to the next element, returning the previous state
	ConstIterator operator++(int) {
		ConstIterator temp = *this;
		_ptr = _ptr->_next;
		return temp;
	}

	// Returns true if two iterators point to the same element
	friend bool operator==(const CLL::ConstIterator& lhs, const CLL::ConstIterator& rhs) {
		return lhs._ptr == rhs._ptr;
	}

	// Returns true if two iterators point to different elements
	friend bool operator!=(const CLL::ConstIterator& lhs, const CLL::ConstIterator& rhs) {
		return lhs._ptr != rhs._ptr;
	}
};


#endif // CLL_H