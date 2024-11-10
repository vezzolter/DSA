// Title:   Header file for Singly Linked List
// Authors: by vezzolter
// Date:    February 3, 2024
// ----------------------------------------------------------------------------


#ifndef SLL_H
#define SLL_H


class SLL {
private:
	struct Node;
	int _size;
	Node* _head;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	SLL();
	SLL(int size, int val);
	SLL(const SLL& src);
	SLL(const SLL&& src)            = delete;
	SLL& operator=(const SLL& rhs);
	SLL& operator=(const SLL&& rhs) = delete;
	~SLL();

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
	void insertAfter(const int pos, const int& data);
	void eraseAfter(const int pos);
	void pushFront(const int& data);
	void popFront();
	void assign(int size, const int& data);
	void clear();
	void resize(int size, const int& data);
	void swap(SLL& src);
};


struct SLL::Node {
public:
	int _data;
	Node* _next;

	// --------------------
	//  Compiler Generated
	// --------------------
	Node()                            = default;
	Node(const int& data, Node* next = nullptr) : _data(data), _next(next) {}
	Node(const Node& src)             = delete;
	Node& operator=(const Node& rhs)  = delete;
	Node(const Node&& src)            = delete;
	Node& operator=(const Node&& rhs) = delete;
	~Node()                           = default;
};


class SLL::Iterator {
private:
	Node* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	Iterator()                               = default;
	explicit Iterator(Node* ptr) : _ptr(ptr) {}
	Iterator(const Iterator& src)            = default;
	Iterator& operator=(const Iterator& rhs) = default;
	Iterator(Iterator&& src)                 = default;
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
	friend bool operator==(const SLL::Iterator& lhs, const SLL::Iterator& rhs) {
		return lhs._ptr == rhs._ptr;
	}

	// Returns true if two iterators point to different elements
	friend bool operator!=(const SLL::Iterator& lhs, const SLL::Iterator& rhs) {
		return lhs._ptr != rhs._ptr;
	}
};


class SLL::ConstIterator {
private:
	const Node* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	ConstIterator()                                    = default;
	explicit ConstIterator(const Node* ptr) : _ptr(ptr) {}
	ConstIterator(const ConstIterator& src)            = default;
	ConstIterator& operator=(const ConstIterator& rhs) = default;
	ConstIterator(ConstIterator&& src)                 = default;
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
	friend bool operator==(const SLL::ConstIterator& lhs, const SLL::ConstIterator& rhs) {
		return lhs._ptr == rhs._ptr;
	}

	// Returns true if two iterators point to different elements
	friend bool operator!=(const SLL::ConstIterator& lhs, const SLL::ConstIterator& rhs) {
		return lhs._ptr != rhs._ptr;
	}
};



#endif // SLL_H