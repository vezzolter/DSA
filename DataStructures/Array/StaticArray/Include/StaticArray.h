// Header file Static Array
// by vezzolter
// January 29, 2024


#ifndef SA_H
#define SA_H


class SA {
private:
	int _size;
	int _data[100];

public:
	// Special Member Functions
	SA();
	SA(int size);
	SA(const SA& rhs);
	SA(SA&&) = delete;
	SA& operator=(const SA& rhs);
	SA& operator=(SA&&) = delete;
	~SA() = default;

	// Element Access
	//int& at(const int index);
	//const int& at(const int index) const;
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
	//void assign();
	//void swap();
};


#endif // SA_H