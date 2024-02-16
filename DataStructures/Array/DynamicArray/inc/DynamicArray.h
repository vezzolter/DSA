// Header file for simplified ADT: Dynamic Array
// by vezzolter
// January 31, 2024

#pragma once

class DynArr
{
private:
	int _size;
	int* _data;

public:
	// Special Member Functions
	explicit DynArr();
	explicit DynArr(int size, int defVal = 0);
	explicit DynArr(const DynArr& rhs);
	DynArr& operator=(const DynArr& rhs);
	~DynArr();

	// Element Access
	int& operator[](const int index);
	int& operator[](const int index) const;
	int front();
	int back();

	// Capacity
	bool empty() const;
	int size() const;
	
	// Modifiers
	void insert(int index, int val);
	void remove(int index);
	void resize(int newSize);
	void clear();

};