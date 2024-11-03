// Title:   Header file for Singly Linked List
// Authors: by vezzolter
// Date:    February 3, 2024
// ----------------------------------------------------------------------------


#ifndef SLL_H
#define SLL_H


#include "SLLIterator.h"


class SLL {
private:
	struct Node {
	public:
		int _data;
		Node* _next;

		Node(const int& data, Node* node = nullptr)
			: _data(data), _next(node) {}
		Node() = default;
		Node(const Node& rhs) = delete;
		Node& operator=(const Node& rhs) = delete;
	};

	int _size;
	Node* _head;

public:
	// Compiler Generated
	SLL();
	SLL(int size, int val);
	// SLL(const std::initializer_list<T>& list); // external dependencies
	SLL(const SLL& rhs);
	SLL(const SLL&& rhs) = delete;
	SLL& operator=(const SLL& rhs);
	SLL& operator=(const SLL&& rhs) = delete;
	~SLL();

	// Iterators
	//using iterator = SLLIterator;

	// Element Access
	int& front();
	const int& front() const;

	// Capacity 
	bool empty() const;
	int size() const;
	//long long maxSize() const;

	// Modifiers
	void insertAfter(const int pos, const int& data);
	void eraseAfter(const int pos);
	void pushFront(const int& data);
	void popFront();
	void assign();
	void clear();
	void resize();
	void swap();
};


#endif // SLL_H