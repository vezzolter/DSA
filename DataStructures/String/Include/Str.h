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
	Str(Str&& other)                = delete;
	Str& operator=(const Str& rhs);
	Str& operator=(Str&& rhs)       = delete;
	~Str();
	

	// -----------
	//  Iterators
	// -----------

	// ----------------
	//  Element Access
	// ----------------

	// ----------
	//  Capacity
	// ----------

	// -----------
	//  Modifiers
	// -----------

	// ------------
	//  Operations
	// ------------

	// ---------------------
	//  Numeric Conversions
	// ---------------------
};


#endif // STR_H
