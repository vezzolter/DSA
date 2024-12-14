// Title:   Header file for Dynamic Array
// Authors: by vezzolter
// Date:    January 31, 2024
// ----------------------------------------------------------------------------


#ifndef DA_H
#define DA_H


class DA {
private:
	int _size;
	int _capacity;
	int* _data;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	DA();
	DA(int size);
	DA(int size, int val);
	DA(const DA& other);
	DA(DA&& other)          = delete;
	DA& operator=(const DA& rhs);
	DA& operator=(DA&& rhs) = delete;
	~DA();

	// -----------
	//  Iterators
	// -----------
	class Iterator;
	using iterator = Iterator;
	iterator begin();
	iterator end();
	class ConstIterator;
	using const_iterator = ConstIterator;
	const_iterator begin() const;
	const_iterator end() const;
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
	int capacity() const;
	void reserve(int capacity);
	void shrinkToFit();
	
	// -----------
	//  Modifiers
	// -----------
	void insert(iterator pos, const int& val);
	void erase(iterator pos);
	void pushBack(const int& val);
	void popBack();
	void assign(int size, const int& val);
	void assign(Iterator first, Iterator last);
	void clear();
	void resize(int size, const int& val = 0);
	void swap(DA& other);
};


class DA::Iterator {
private:
	int* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------

	Iterator()                               = default;
	Iterator(int* ptr) : _ptr(ptr) {}
	Iterator(const Iterator& other)          = default;
	Iterator(Iterator&& other)               = default;
	Iterator& operator=(const Iterator& rhs) = default;
	Iterator& operator=(Iterator&& rhs)      = default;
	~Iterator()                              = default;

	// ----------------------
	//  Overloaded Operators
	// ----------------------

	// Returns a reference to the element pointed to by the iterator
	int& operator*() { return *_ptr; }

	// Subtraction operator for random access
	// P.s. ptrdiff_t is much better type due to semantics and portability
	int operator-(const Iterator& other) const { return _ptr - other._ptr; }

	// Advances the iterator to the next element (pre-increment)
	Iterator& operator++() {
		++_ptr;
		return *this;
	}

	// Advances the iterator to the next element, returning the previous state
	Iterator operator++(int) {
		Iterator temp(*this);
		++_ptr;
		return temp;
	}

	// Moves the iterator to the previous element (pre-decrement)
	Iterator& operator--() {
		--_ptr;
		return *this;
	}

	// Moves the iterator to the previous element, returning the previous state
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


class DA::ConstIterator {
private:
	const int* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------

	ConstIterator()                                    = default;
	ConstIterator(const int* ptr) : _ptr(ptr) {}
	ConstIterator(const ConstIterator& other)          = default;
	ConstIterator(ConstIterator&& other)               = default;
	ConstIterator& operator=(const ConstIterator& rhs) = default;
	ConstIterator& operator=(ConstIterator&& rhs)      = default;
	~ConstIterator()                                   = default;

	// ----------------------
	//  Overloaded Operators
	// ----------------------
	
	// Returns a const reference to the element pointed to by the iterator
	const int& operator*() { return *_ptr; }

	// Subtraction operator for random access
	// P.s. ptrdiff_t is much better type due to semantics and portability
	int operator-(const ConstIterator& other) const { return _ptr - other._ptr; }

	// Advances the iterator to the next element (pre-increment)
	ConstIterator& operator++() {
		++_ptr;
		return *this;
	}

	// Advances the iterator to the next element, returning the previous state
	ConstIterator operator++(int) {
		ConstIterator temp(*this);
		++_ptr;
		return temp;
	}

	// Moves the iterator to the previous element (pre-decrement)
	ConstIterator& operator--() {
		--_ptr;
		return *this;
	}

	// Moves the iterator to the previous element, returning the previous state
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


#endif // DA_H