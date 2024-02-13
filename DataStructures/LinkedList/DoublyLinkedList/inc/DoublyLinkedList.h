// Header file for simplified ADT: Doubly Linked List
// by vezzolter
// February 13, 2024

#ifndef DLL_H
#define DLL_H

template<class T>
class DLL
{
private:
	template<class T>
	struct Node {
	public:
		T _data;
		Node* _next;
		Node* _prev;
		
		// Special Member Functions
		Node(const T& newData, Node* nextNode = nullptr, Node* prevNode = nullptr)
			: _data(newData), _next(nextNode), _prev(prevNode) {}
		Node() = default;
		Node(const Node& rhs) = delete;
		Node& operator=(const Node& rhs) = delete;
	};

	int _size;
	Node<T>* _head;
	Node<T>* _tail;

public:
	// Special Member Functions
	DLL();
	// DLL(const std::initializer_list<T>& initList); remove due to init list
	DLL(const DLL& rhs);
	DLL& operator=(const DLL& rhs);
	~DLL();

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
	void popFront();
	void pushBack(const T& newData);
	void popBack();
};

#include "DoublyLinkedList.cpp"

#endif