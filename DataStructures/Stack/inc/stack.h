// Header file for simplified ADT: Stack
// by vezzolter
// March 2, 2024

#ifndef STACK_H
#define STACK_H


template<class T>
class Stack {
private:
public:
	// Special Member Functions
	Stack();
	Stack(const Stack& rhs);
	Stack& operator=(const Stack& rhs);
	~Stack();

	// Element Access
	T& top();
	const T& top() const;

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void push(const T& newData);
	void pop();
};


#include "Stack.cpp"

#endif