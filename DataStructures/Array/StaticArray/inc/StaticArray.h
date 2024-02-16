// Header file for simplified ADT: Static Array
// by vezzolter
// January 29, 2024

#pragma once

class SA
{
private:
	static const int MAX_SIZE = 100;
	int _data[MAX_SIZE];
	int _size;


public:
	// Special Member Functions
	SA();
	SA(int size);
	SA(const SA& rhs)            = default;
	SA& operator=(const SA& rhs) = default;
	~SA()                        = default;

	// Element Access
	int& operator[](const int index);
	const int& operator[](const int index) const;
	int front();
	const int front() const;
	int back();
	const int back() const;

	// Capacity
	bool empty() const;
	int size() const;
};