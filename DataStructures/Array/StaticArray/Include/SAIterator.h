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
	SAIterator();
	SAIterator(int* ptr);

	SAIterator(const SAIterator& rhs) = default;
	SAIterator& operator=(const SAIterator& rhs) = default;
	SAIterator(SAIterator&& rhs) = delete;
	SAIterator& operator=(SAIterator&& rhs) = delete;
	~SAIterator() = default;


	// Overloaded Operators
	int& operator*() const;
	SAIterator& operator++();
	SAIterator operator++(int);
	bool operator==(const SAIterator& other) const;
	bool operator!=(const SAIterator& other) const;
};


#endif // SAITERATOR_H