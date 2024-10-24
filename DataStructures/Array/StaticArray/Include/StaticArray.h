// Title:   Header file for Static Array
// Authors: by vezzolter
// Date:    January 29, 2024
// ----------------------------------------------------------------------------


#ifndef SA_H
#define SA_H


//#include <initializer_list>
#include "SAIterator.h"


class SA {
private:
	static const int _SIZE = 10; // since no heap/template
	int _data[_SIZE];

public:
	// Compiler Generated 
	SA();
	//SA(std::initializer_list<int> values); // external dependencies
	SA(const SA& rhs);
	SA& operator=(const SA& rhs);	
	SA(SA&& rhs) = delete;
	SA& operator=(SA&& rhs) = delete;
	~SA() = default;

	// Iterators
	using iterator = SAIterator;
	iterator begin();
	iterator end();

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

	// Operations
	void assign(int val);
	void swap(SA& other);
};


#endif // SA_H