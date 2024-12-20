// Title:   Header file for String
// Authors: by vezzolter
// Date:    November 28, 2024
// ----------------------------------------------------------------------------


#ifndef STR_H
#define STR_H


class Str {
private:
	int _size;
	int _capacity;
	char* _data;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	Str();
	//explicit Str(const std::string& str);
	explicit Str(const char* str);
	Str(const Str& other);
	Str(Str&& other)          = delete;
	Str& operator=(const Str& rhs);
	Str& operator=(Str&& rhs) = delete;
	~Str();
	
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
	char& operator[](const int pos);
	const char& operator[](const int pos) const;
	char& front();
	const char& front() const;
	char& back();
	const char& back() const;
	char* data();
	const char* data() const;

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
	void insert(iterator pos, const char& val);
	void erase(iterator pos);
	void pushBack(const char& val);
	void popBack();
	void assign(int size, const char& val);
	void assign(Iterator first, Iterator last);
	void clear();
	void resize(int size, const char& val = ' ');
	void swap(Str& other);

	// ------------
	//  Operations
	// ------------

	// ---------------------
	//  Numeric Conversions
	// ---------------------
};


class Str::Iterator {
private:
	char* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	Iterator()                               = default;
	Iterator(char* ptr) : _ptr(ptr) {}
	Iterator(const Iterator& other)          = default;
	Iterator(Iterator&& other)               = default;
	Iterator& operator=(const Iterator& rhs) = default;
	Iterator& operator=(Iterator&& rhs)      = default;
	~Iterator()                              = default;

	// ----------------------
	//  Overloaded Operators
	// ----------------------

	// Returns a reference to the element pointed to by the iterator
	char& operator*() { return *_ptr; }

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


class Str::ConstIterator {
private:
	const char* _ptr = nullptr;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	ConstIterator()                                    = default;
	ConstIterator(const char* ptr) : _ptr(ptr) {}
	ConstIterator(const ConstIterator& other)          = default;
	ConstIterator(ConstIterator&& other)               = default;
	ConstIterator& operator=(const ConstIterator& rhs) = default;
	ConstIterator& operator=(ConstIterator&& rhs)      = default;
	~ConstIterator()                                   = default;

	// ----------------------
	//  Overloaded Operators
	// ----------------------

	// Returns a const reference to the element pointed to by the iterator
	const char& operator*() { return *_ptr; }

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



#endif // STR_H
