// Header file Static Array Iterator
// by vezzolter
// October 13, 2024


#ifndef SAITERATOR_H
#define SAITERATOR_H


class SAIterator {
private:
	int* _ptr = nullptr;

public:
	// Compiler Generated
	SAIterator() = default;
	SAIterator(int* ptr);
	SAIterator(const SAIterator& rhs);
	SAIterator& operator=(const SAIterator& rhs) = default;
	SAIterator(SAIterator&& rhs) = delete;
	SAIterator& operator=(SAIterator&& rhs) = delete;
	~SAIterator() = default;


	// Overloaded Operators
	int& operator*();
	const int& operator*() const;
	SAIterator& operator++();
	//SAIterator operator++(int); // could require disabling the RVO or using move cstr
	SAIterator& operator--();
	//SAIterator operator--(int); // could require disabling the RVO or using move cstr
	friend bool operator==(const SAIterator& lhs, const SAIterator& rhs);
	friend bool operator!=(const SAIterator& lhs, const SAIterator& rhs);
};


#endif // SAITERATOR_H