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
		T _data; 
		Node* _next;

		// Special Member Functions
		Node(const T& newData, Node* nextNode = nullptr) 
			: _data(newData), _next(nextNode) {}
		Node()                           = default;
		Node(const Node& rhs)            = delete;
		Node& operator=(const Node& rhs) = delete;
	};

	int _size;
	Node<T>* _head;

public:
	// Special Member Functions
	SLL();
	// SLL(const std::initializer_list<T>& initList); remove due to init list
	SLL(const SLL& rhs);
	SLL& operator=(const SLL& rhs);
	~SLL();

	// Element Access
	T& operator[](const int index);
	const T& operator[](const int index) const;
	T& front();
	const T& front() const;

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void clear();
	void insertAfter(const int index, const T& newData);
	void eraseAfter(const int index);
	void pushFront(const T& newData);
	void popFront();
};

#include "SinglyLinkedList.cpp"

#endif