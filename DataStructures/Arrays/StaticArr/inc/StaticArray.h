// Header file for simplified ADT: Static Array
// by vezzolter
// January 29, 2024

#pragma once

class StaticArr
{
private:
	int mLength;
	int* mArr;

public:
	// Special Member Functions
	explicit StaticArr();
	explicit StaticArr(int length); 
	explicit StaticArr(const StaticArr& src) = default;
	StaticArr& operator=(const StaticArr& rhs) = default;
	~StaticArr();


	// Element Access
	int& operator[](const int index);
	int front();
	int back();


	// Capacity
	bool isEmpty() const;
	int size() const;


	// Operations
	void fill(const int val);
};