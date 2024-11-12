// Title:   Header file for Doubly Linked List
// Authors: by vezzolter
// Date:    February 13, 2024
// ----------------------------------------------------------------------------


#ifndef DLL_H
#define DLL_H


class DLL {
private:
	struct Node;
	int _size;
	Node* _head;
	Node* _tail;

	// Facilitator methods
	Node* getStartingNode(int pos) const;

public:
	// --------------------
	//  Compiler Generated
	// --------------------
	DLL();
	//DLL(int size, int val);
	DLL(const DLL& other);
	DLL(const DLL&& other)          = delete;
	DLL& operator=(const DLL& rhs);
	DLL& operator=(const DLL&& rhs) = delete;
	~DLL();

	// ----------------
	//  Element Access
	// ----------------
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
	void insert(const int pos, const int& data);
	void erase(const int pos);
	void pushFront(const int& data);
	void popFront();
	void pushBack(const int& data);
	void popBack();
	//void reverse();
	//void assign(int size, const int& data);
	//void assign(const_iterator first, const_iterator last);
	void clear();
	//void resize(int size, const int& data);
	//void swap(DLL& other);
};


struct DLL::Node {
public:
	int _data;
	Node* _next;
	Node* _prev;

	// --------------------
	//  Compiler Generated
	// --------------------
	Node()                              = default;
	Node(const int& data, Node* next = nullptr, Node* prev = nullptr)
		: _data(data), _next(next), _prev(prev) {}
	Node(const Node& other)             = delete;
	Node(const Node&& other)            = delete;
	Node& operator=(const Node& rhs)    = delete;
	Node& operator=(const Node&& rhs)   = delete;
	~Node()                             = default;
};


#endif // DLL_H