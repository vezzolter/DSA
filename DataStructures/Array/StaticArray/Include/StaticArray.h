// Header file for Static Array
// by vezzolter
// January 29, 2024


#ifndef SA_H
#define SA_H


//#include <initializer_list>
#include "SAIterator.h"


class SA {
private:
	static const int _SIZE = 9; // since no heap/template
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
	void assign(int val);
	void swap(SA& other);
};


#endif // SA_H