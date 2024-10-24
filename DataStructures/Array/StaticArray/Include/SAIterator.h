// Title:   Header file for Static Array Iterator
// Authors: by vezzolter
// Date:    October 13, 2024
// ----------------------------------------------------------------------------


#ifndef SAITERATOR_H
#define SAITERATOR_H


class SAIterator {
private:
	int* _ptr = nullptr;

public:
	// Compiler Generated
	SAIterator() = default;
	SAIterator(int* ptr);
	SAIterator(const SAIterator& rhs) = default;
	SAIterator& operator=(const SAIterator& rhs) = default;
	SAIterator(SAIterator&& rhs) = default;
	SAIterator& operator=(SAIterator&& rhs) = default;
	~SAIterator() = default;

	// Overloaded Operators
	int& operator*();
	//const int& operator*() const; // instead use dedicated const itr
	SAIterator& operator++();
	SAIterator operator++(int);
	SAIterator& operator--();
	SAIterator operator--(int);
	friend bool operator==(const SAIterator& lhs, const SAIterator& rhs);
	friend bool operator!=(const SAIterator& lhs, const SAIterator& rhs);
};


#endif // SAITERATOR_H