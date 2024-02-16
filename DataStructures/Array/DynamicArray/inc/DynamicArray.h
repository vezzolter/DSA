// Header file for simplified ADT: Dynamic Array
// by vezzolter
// January 31, 2024

#ifndef DA_H
#define DA_H

template<class T>
class DA
{
private:
	int _size;
	T* _data;

public:
	// Special Member Functions
	DA();
	DA(int newSize, T newData = T());
	DA(const DA& rhs);
	DA& operator=(const DA& rhs);
	~DA();

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
	
	// Modifiers
	void pushBack(const T& newData);
	void insert(int index, const T& newData);
	void remove(int index);
	void resize(int newSize);
	void clear();
};


#include "DynamicArray.cpp"

#endif