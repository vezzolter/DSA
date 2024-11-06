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
	// Compiler Generated
	SLL();
	SLL(int size, int val);
	SLL(const SLL& src);
	SLL(const SLL&& src) = delete;
	SLL& operator=(const SLL& rhs);
	SLL& operator=(const SLL&& rhs) = delete;
	~SLL();

	// Iterators
	class Iterator;
	using iterator = Iterator;
	iterator begin();
	iterator end();

	// Element Access
	int& front();
	const int& front() const;

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void insertAfter(const int pos, const int& data);
	void eraseAfter(const int pos);
	void pushFront(const int& data);
	void popFront();
	void assign(int size, const int& data);
	void clear();
	void resize(int size, const int& data = 0);
	void swap(SLL& src);
};


struct SLL::Node {
public:
	int _data;
	Node* _next;

	// Compiler Generated
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
	// Compiler Generated
	Iterator()                               = default;
	explicit Iterator(Node* ptr) : _ptr(ptr) {}
	Iterator(const Iterator& src)            = default;
	Iterator& operator=(const Iterator& rhs) = default;
	Iterator(Iterator&& src)                 = default;
	Iterator& operator=(Iterator&& rhs)      = default;
	~Iterator()                              = default;

	// Overloaded Operators
	int& operator*();
	Node* operator->();
	Iterator& operator++();
	Iterator operator++(int);
	friend bool operator==(const Iterator& lhs, const Iterator& rhs);
	friend bool operator!=(const Iterator& lhs, const Iterator& rhs);
};

// Returns a reference to the data of a node
int& SLL::Iterator::operator*() { return _ptr->_data; }

// Returns a pointer to the entire node, allowing access to its members
SLL::Node* SLL::Iterator::operator->() { return _ptr; }

// Advances the iterator to the next element (pre-increment)
SLL::Iterator& SLL::Iterator::operator++() {
	_ptr = _ptr->_next;
	return *this;
}

// Advances the iterator to the next element, returning the previous state
SLL::Iterator SLL::Iterator::operator++(int) {
	Iterator temp = *this;
	_ptr = _ptr->_next;
	return temp;
}

// Returns true if two iterators point to the same element
bool operator==(const SLL::Iterator& lhs, const SLL::Iterator& rhs) {
	return lhs._ptr == rhs._ptr;
}

// Returns true if two iterators point to different elements
bool operator!=(const SLL::Iterator& lhs, const SLL::Iterator& rhs) {
	return lhs._ptr != rhs._ptr;
}


#endif // SLL_H