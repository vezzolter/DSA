// Header file for simplified ADT: Circular Linked List
// by vezzolter
// February 13, 2024

#ifndef CLL_H
#define CLL_H


template<class T>
class CLL
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

	// Facilitator method
	Node<T>* getStartingNode(int index) const;

public:
	// Special Member Functions
	CLL();
	// CLL(const std::initializer_list<T>& initList); remove due to init list
	CLL(const CLL& rhs);
	CLL& operator=(const CLL& rhs);
	~CLL();

	// Element Access
	T& operator[](const int index);
	const T& operator[](const int index) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void clear();
	void insert(const int index, const T& newData);
	void erase(const int index);
	void pushFront(const T& newData);
	void popFront();
	void pushBack(const T& newData);
	void popBack();
};


#include "CircularLinkedList.cpp"

#endif