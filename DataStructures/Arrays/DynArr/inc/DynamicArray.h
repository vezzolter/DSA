// Header file for simplified ADT: Dynamic Array
// by vezzolter
// January 31, 2024

#pragma once

class DynArr
{
private:
	int* _data;
	int _size;

public:
	// Special Member Functions
	explicit DynArr();
	explicit DynArr(int size, int defVal = 0);
	explicit DynArr(const DynArr& src);
	DynArr& operator=(const DynArr& rhs);
	~DynArr();

	// Element Access
	int& operator[](const int index);
	int front();
	int back();

	// Capacity
	bool empty() const;
	int size() const;
	void resize(int newSize);

	// Operations
	void clear();
	void remove(int pos);
	void insert(int pos, int val);
};