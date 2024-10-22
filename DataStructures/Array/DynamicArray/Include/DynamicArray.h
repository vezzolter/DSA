// Header file for Dynamic Array
// by vezzolter
// January 31, 2024


#ifndef DA_H
#define DA_H


#include "DAIterator.h"


class DA {
private:
	int _size;
	int _capacity;
	int* _data;

public:
	// Compiler Generated
	DA();
	DA(int size, int data);
	DA(const DA& rhs);
	DA& operator=(const DA& rhs);
	DA(const DA&& rhs) = delete;
	DA& operator=(const DA&& rhs) = delete;
	~DA();

	// Iterators

	// Element Access
	//int& at(const int pos); // throws exceptions
	//const int& at(const int pos) const; // throws exceptions
	int& operator[](const int pos);
	const int& operator[](const int pos) const;
	int& front();
	const int& front() const;
	int& back();
	const int& back() const;

	// Capacity
	bool empty() const;
	int size() const;
	int capacity() const;
	void reserve(int cap);
	void shrinkToFit();
	
	// Operations
	void insert(int pos, const int& data);
	void pushBack(const int& data);
	void popBack();
	void erase(int pos);
	void clear();
	void assign(int val);
	void swap(DA& other);
	void resize(int size);
};


#endif // DA_H