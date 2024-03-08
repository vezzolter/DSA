// Header file for simplified ADT: Linear Queue
// by vezzolter
// March 2, 2024

#ifndef LQ_H
#define LQ_H


template<class T>
class LQ {
private:
	struct Node {
		T _data;
		Node* _next;

		Node(const T& newData) : _data(newData), _next(nullptr) {}
		Node()                           = default;
		Node(const Node& rhs)            = delete;
		Node& operator=(const Node& rhs) = delete;
	};

	size_t _size;
	Node* _front;
	Node* _rear;

public:
	// Special Member Functions
	LQ();
	LQ(const LQ& rhs);
	LQ& operator=(const LQ& rhs);
	~LQ();

	// Element Access
	T& front();
	const T& front() const;
	T& rear();
	const T& rear() const;

	// Capacity 
	bool empty() const;
	size_t size() const;

	// Modifiers
	void push(const T& newData);
	void pop();
};


#include "LinearQueue.cpp"

#endif