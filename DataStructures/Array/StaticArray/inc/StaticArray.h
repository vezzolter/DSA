// Header file for simplified ADT: Static Array
// by vezzolter
// January 29, 2024

#ifndef SA_H
#define SA_H


template<class T, int MAX_SIZE>
class SA {
private:
	int _size;
	T _data[MAX_SIZE];

public:
	// Special Member Functions
	SA();
	SA(int size);
	SA(const SA& rhs);
	SA& operator=(const SA& rhs);
	~SA() = default;

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
};


#include "StaticArray.cpp"

#endif