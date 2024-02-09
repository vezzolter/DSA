// Header file for simplified ADT: Singly Linked List
// by vezzolter
// February 3, 2024

#pragma once


#include "SinglyLinkedList.h"

template<class T>
class SLL
{
private:
	template<class T>
	struct Node {
	public:
		Node* _next;
		T _data;

		// Special Member Functions
		Node(const T& newData, Node* nextNode = nullptr): _data(newData), _next(nextNode) {}
		Node()                           = default;
		Node(const Node& src)            = delete;
		Node& operator=(const Node& rhs) = delete;
	}

	Node* _head;

public:
	// Special Member Functions
	explicit SLL();
	~SLL();

	// Element Access
	T& operator[](const int index);
	T& front();

	// Capacity 
	bool empty() const;
	int size();

	// Modifiers
	void clear();
	void insert(const int index, const T& value);
	void erase(const int index);
	void push_front(const T& newData);
	void pop_front();

	// Operations
	void merge();
	void remove();
	void reverse();
	void unique();
	void sort();
};