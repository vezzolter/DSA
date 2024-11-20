// Title:   Header file for Static Array
// Authors: by vezzolter
// Date:    January 29, 2024
// ----------------------------------------------------------------------------


#ifndef SA_H
#define SA_H


class SA {
private:
	static const int _SIZE = 10; // since no heap/template
	int _data[_SIZE];

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	SA();
	SA(const SA& other);
	SA(SA&& other)          = delete;
	SA& operator=(const SA& rhs);
	SA& operator=(SA&& rhs) = delete;
	~SA()                   = default;

	// -----------
	//  Iterators
	// -----------
	class Iterator;
	using iterator = Iterator;
	iterator begin();
	iterator end();
	class ConstIterator;
	using const_iterator = ConstIterator;
	const_iterator cbegin() const;
	const_iterator cend() const;

	// ----------------
	//  Element Access
	// ----------------
	int& operator[](const int pos);
	const int& operator[](const int pos) const;
	int& front();
	const int& front() const;
	int& back();
	const int& back() const;

	// ----------
	//  Capacity
	// ----------
	bool empty() const;
	int size() const;

	// -----------
	//  Modifiers
	// -----------
	void assign(int val);
	void swap(SA& other);
};


class SA::Iterator {
private:
	int* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	Iterator()                                 = default;
	explicit Iterator(int* ptr) : _ptr(ptr) {}
	Iterator(const Iterator& other)            = default;
	Iterator(Iterator&& other)                 = default;
	Iterator& operator=(const Iterator& rhs)   = default;
	Iterator& operator=(Iterator&& rhs)        = default;
	~Iterator()                                = default;

	// ----------------------
	//  Overloaded Operators
	// ----------------------

	// Returns a reference to the element pointed to by the iterator
	int& operator*() { return *_ptr; }

	// Advances the iterator to the next element and returns a reference to it
	Iterator& operator++() {
		++_ptr;
		return *this;
	}

	// Returns a copy of the iterator and then advances to the next element
	Iterator operator++(int) {
		Iterator temp(*this);
		++_ptr;
		return temp;
	}

	// Moves the iterator to the previous element and returns a reference to it
	Iterator& operator--() {
		--_ptr;
		return *this;
	}

	// Returns a copy of the iterator and then moves to the previous element
	Iterator operator--(int) {
		Iterator temp(*this);
		--_ptr;
		return temp;
	}

	// Returns true if two iterators point to the same element
	friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
		return lhs._ptr == rhs._ptr;
	}

	// Returns true if two iterators point to different elements
	friend bool operator!=(const Iterator& lhs, const Iterator& rhs) {
		return lhs._ptr != rhs._ptr;
	}
};


class SA::ConstIterator {
private:
	const int* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	ConstIterator()                                      = default;
	explicit ConstIterator(const int* ptr) : _ptr(ptr) {}
	ConstIterator(const ConstIterator& other)            = default;
	ConstIterator(ConstIterator&& other)                 = default;
	ConstIterator& operator=(const ConstIterator& rhs)   = default;
	ConstIterator& operator=(ConstIterator&& rhs)        = default;
	~ConstIterator()                                     = default;

	// ----------------------
	//  Overloaded Operators
	// ----------------------

	// Returns a const reference to the element pointed to by the iterator
	const int& operator*() { return *_ptr; }

	// Advances the iterator to the next element and returns a reference to it
	ConstIterator& operator++() {
		++_ptr;
		return *this;
	}

	// Returns a copy of the iterator and then advances to the next element
	ConstIterator operator++(int) {
		ConstIterator temp(*this);
		++_ptr;
		return temp;
	}

	// Moves the iterator to the previous element and returns a reference to it
	ConstIterator& operator--() {
		--_ptr;
		return *this;
	}

	// Returns a copy of the iterator and then moves to the previous element
	ConstIterator operator--(int) {
		ConstIterator temp(*this);
		--_ptr;
		return temp;
	}

	// Returns true if two iterators point to the same element
	friend bool operator==(const ConstIterator& lhs, const ConstIterator& rhs) {
		return lhs._ptr == rhs._ptr;
	}

	// Returns true if two iterators point to different elements
	friend bool operator!=(const ConstIterator& lhs, const ConstIterator& rhs) {
		return lhs._ptr != rhs._ptr;
	}
};


#endif // SA_H