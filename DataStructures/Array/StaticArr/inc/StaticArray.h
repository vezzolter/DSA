// Header file for simplified ADT: Static Array
// by vezzolter
// January 29, 2024

#pragma once

class StaticArr
{
private:
	static const int MAX_SIZE = 100;  // Maximum size for the static array
	int _data[MAX_SIZE];  // Static array to store elements
	int _size;  // Current size of the array
	

public:
	// Special Member Functions
	explicit StaticArr();
	explicit StaticArr(int size); 
	explicit StaticArr(const StaticArr& src) = default;
	StaticArr& operator=(const StaticArr& rhs) = default;
	~StaticArr();


	// Element Access
	int& operator[](const int pos);
	int front();
	int back();


	// Capacity
	bool empty() const;
	int size() const;
};