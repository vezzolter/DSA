// Header file for simplified ADT: Singly Linked List
// by vezzolter
// February 3, 2024

#ifndef SLL_H
#define SLL_H

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
		Node(const T& newData, Node* nextNode = nullptr) : _data(newData), _next(nextNode) {}
		Node()                           = default;
		Node(const Node& src)            = delete;
		Node& operator=(const Node& rhs) = delete;
	};

	Node<T>* _head;
	int _size;

public:
	// Special Member Functions
	SLL();
	~SLL();

	// Element Access
	T& operator[](const int index);
	T& operator[](const int index) const;
	T& front();

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void clear();
	void insertAfter(const int index, const T& newData);
	void eraseAfter(const int index);
	void pushFront(const T& newData);
	void pop_front();

	// Operations
	void merge();
	void remove();
	void reverse();
	void unique();
	void sort();
};

#include "SinglyLinkedList.cpp"

#endif