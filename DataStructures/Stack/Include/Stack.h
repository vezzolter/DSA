// Title:   Header file for Stack
// Authors: by vezzolter
// Date:    March 2, 2024
// ----------------------------------------------------------------------------


#ifndef STACK_H
#define STACK_H


template<class T>
class Stack {
private:
	class Node {
	public:
		T _data;
		Node* _next;

		Node(T data) : _data(data), _next(nullptr) {}
		Node()                           = default;
		Node(const Node& rhs)            = delete;
		Node& operator=(const Node& rhs) = delete;
	};

	int _size;
	Node* _top;

public:
	// Special Member Functions
	Stack();
	Stack(const Stack& rhs);
	Stack& operator=(const Stack& rhs);
	~Stack();

	// Element Access
	T& peek();
	const T& peek() const;

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void push(const T& newData);
	void pop();
};


#endif