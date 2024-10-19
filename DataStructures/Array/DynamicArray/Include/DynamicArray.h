// Header file for Dynamic Array
// by vezzolter
// January 31, 2024


#ifndef DA_H
#define DA_H


#include "DAIterator.h"


class DA {
private:
	int _size;
	int* _data;

public:
	// Compiler Generated
	DA();
	DA(int newSize, int newData);
	DA(const DA& rhs);
	DA& operator=(const DA& rhs);
	DA(const DA&& rhs) = delete;
	DA& operator=(const DA&& rhs) = delete;
	~DA();

	// Iterators

	// Element Access
	//int& at(const int index); // throws exceptions
	//const int& at(const int index) const; // throws exceptions
	int& operator[](const int index);
	const int& operator[](const int index) const;
	int& front();
	const int& front() const;
	int& back();
	const int& back() const;

	// Capacity
	bool empty() const;
	int size() const;
	
	// Operations
	void pushBack(const int& newData);
	void insert(int index, const int& newData);
	void remove(int index);
	void resize(int newSize);
	void clear();
};


#endif // DA_H