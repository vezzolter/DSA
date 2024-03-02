// Header file for simplified ADT: Linear Queue
// by vezzolter
// March 2, 2024

#ifndef LQ_H
#define LQ_H


template<class T>
class LQ {
private:

public:
	// Special Member Functions
	LQ();
	LQ(const LQ& rhs);
	LQ& operator=(const LQ& rhs);
	~LQ();

	// Element Access
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void push(const T& newData);
	void pop();
};


#include "LinearQueue.cpp"

#endif