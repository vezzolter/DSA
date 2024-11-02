// Title:   Header file for Singly Linked List Iterator
// Authors: by vezzolter
// Date:    November 2, 2024
// ----------------------------------------------------------------------------


#ifndef SLLITERATOR_H
#define SLLITERATOR_H


class SLLIterator {
private:
	int* _ptr = nullptr;

public:
	// Compiler Generated
	SLLIterator() = default;
	SLLIterator(int* ptr);
	SLLIterator(const SLLIterator& rhs) = default;
	SLLIterator& operator=(const SLLIterator& rhs) = default;
	SLLIterator(SLLIterator&& rhs) = default;
	SLLIterator& operator=(SLLIterator&& rhs) = default;
	~SLLIterator() = default;

	// Overloaded Operators
	int& operator*();
	//const int& operator*() const; // instead use dedicated const itr
	SLLIterator& operator++();
	SLLIterator operator++(int);
	//SLLIterator& operator--(); // no back traversal
	//SLLIterator operator--(int); // no back traversal
	friend bool operator==(const SLLIterator& lhs, const SLLIterator& rhs);
	friend bool operator!=(const SLLIterator& lhs, const SLLIterator& rhs);
};


#endif // SLLITERATOR_H