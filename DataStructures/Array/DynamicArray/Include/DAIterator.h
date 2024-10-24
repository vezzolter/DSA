// Title:   Header file for Dynamic Array Iterator
// Authors: by vezzolter
// Date:    October 19, 2024
// ----------------------------------------------------------------------------


#ifndef DAITERATOR_H
#define DAITERATOR_H


class DAIterator {
private:
	int* _ptr = nullptr;

public:
    // Compiler Generated
    DAIterator() = default;
    DAIterator(int* ptr);
    DAIterator(const DAIterator& rhs) = default;
    DAIterator& operator=(const DAIterator& rhs) = default;
    DAIterator(DAIterator&& rhs) = default;
    DAIterator& operator=(DAIterator&& rhs) = default;
    ~DAIterator() = default;

    // Overloaded Operators
    int& operator*();
    //const int& operator*() const; // instead use dedicated const itr
    DAIterator& operator++();
    DAIterator operator++(int);
    DAIterator& operator--();
    DAIterator operator--(int);
    friend bool operator==(const DAIterator& lhs, const DAIterator& rhs);
    friend bool operator!=(const DAIterator& lhs, const DAIterator& rhs);
};


#endif // DAITERATOR_H