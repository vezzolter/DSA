// Title:   Header file for Stack (Array-Based)
// Authors: by vezzolter
// Date:    March 2, 2024
// ----------------------------------------------------------------------------


#ifndef STACK_H
#define STACK_H


class Stack {
private:
	int _size;
	int _capacity;
	int* _data;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	Stack();
	Stack(const Stack& other);
	Stack(Stack&& other)          = delete;
	Stack& operator=(const Stack& rhs);
	Stack& operator=(Stack&& rhs) = delete;
	~Stack();

	// ----------------
	//  Element Access
	// ----------------
	int& top();
	const int& top() const;

	// ----------
	//  Capacity
	// ----------
	bool empty() const;
	int size() const;

	// -----------
	//  Modifiers
	// -----------
	void push(const int& val);
	void pop();
	void swap(Stack& other);
};


#endif