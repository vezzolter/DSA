# &#128209; Table of Contents
- [💡 Overview](#-overview)
- [💻 Implementation](#-implementation)
	- [Singly Linked List](#singly-linked-list)
	- [Doubly Linked List](#doubly-linked-list)
	- [Circular Linked List](#circular-linked-list)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
The **Linked List** stands out as one of the most fundamental abstract data type (ADT) in computer science, that serves as a linear collection of elements, which becomes particularly valuable when the primary objective involves traversing a collection of items sequentially, one by one. It is named this way, because of the way how elements are connected via links to each other. This subsection explores the linked list not only to enhance comprehension of its concepts, but also to establish a solid foundation for a more complex algorithmic designs and problem-solving strategies.
<p align="center"><img src="./img/LinkedList.png"/></p>

---
**Essential Terminology:**
- **Collection** — is a data structure (or container), which is used to group multiple elements together.
  - **Linear Collection** — is a type of collection, where elements are arranged in linear sequence, i.e. each element has a predecessor and a succressor, except for the first and last elements.
- **Linked List** — is a linear collection, consists of elements named as nodes that are linked together using pointers, because they are not necessarily adjacent in memory.
- **Node** — is an each individual element contained within the list, which consists of two main components:
  - **Data** — is an actual information stored within the element.
  - **Pointer** — is a pointer or reference, that stores the memory address of the next node in the sequence.
- **Head** — is the first node in the list.
- **Tail** — is the last node in the list.

---
**Common Operations for ADT Linked List:**
- **Traversal** — iterating through the elements of the list.
- **Acess** — retrieving or updating the value of an existing element.
- **Insertion** — adding a new element to the list.
- **Deletion** — removing an element from the list.
- **Search** — locating a specific element within the list.
- **Sorting** — arranging the elements of the list in a specific order.
- **Merging** — combining two lists into one.
- **Splitting** — dividing the list into two or more parts.
- **Filtering** — selecting specific elements based on certain criteria.

---
Lists provide **sequential access** meaning that we need to traverse the list's elements one by one in order to access them, which certainly requires time. Furthermore, as as the number of nodes in the list increases, the time required to traverse to a particular location also does. This results in the conclusion, that linked lists are not the preferred option in scenarios where you have to perform lots of operation that dona lot or the data structure size remains constant, although they still can be a natural fit for some cases.
<p align="center"><img src="./img/TraversalProcess.png"/></p>

---
The true power of linked lists lies in the flexible nature of the size. Dynamic memory allocation of lists allow for flexible resizing, making them suitable for scenarios where the size of the data structure needs to change frequently. All of the "size-manipulating operations" are based on the the principle of "updating" nodes' pointers. Rather than delving into the intricacies of every possible operation, I'll illustrate a fundamental example of deleting an element that encapsulates the essence of the concept.
<p align="center"><img src="./img/DeletionProcess.png"/></p>

---
When it comes to classification, there are broadly three types of lists: singly linked list, doubly linked list and cirular linked list. While these types share some common ideas, each possesses distinctive characteristics. The choice between them depends on the specific requirements of the case at hand.

**Singly Linked List** — is a list, each node contains only one pointer to the next node in the sequence, enabling unidirectional traversal: forward from the head to the tail. The last node's "next pointer" points to nullptr, indicating the end of the list.
<p align="center"><img src="./img/StructureSLL.png"/></p>

**Doubly Linked List** — is a list, where each node contains an additional pointer to the previous node in the sequence enabling bidirectional traversal: forward from the head to the tail and backward from the tail to the head. The first node's "previous pointer" and the last node's "next pointer" point to nullptr, indicating the start and end of the list, respectively.
<p align="center"><img src="./img/StructureDLL.png"/></p>

**Circular Linked List** — is a list, where the last node points back to the head node. Allow for circular traversal, which can be unidirectional (if nodes are singly linked) or bidirectional (if nodes are doubly linked).
<p align="center"><img src="./img/StructureCLL.png"/></p>

# &#x1F4BB; Implementation 
Discussing ADT, it's evident that well-established and widely recognized implementations already exist for singly, doubly and circular linked lists. In the context of C++, `std::forward_list` is a representative of singly linked list, and `std::list` stands as the counterpart for doubly linked list. Both of them, can be altered to create circular structure via manual pointers manipulation.  It's commonly recommended to rely on these proven implementations rather than reinventing the wheel. However, within the scope of this subsection, we'll take a closer look at simplified versions of these lists. This exploration is aimed at gaining a deeper understanding of the fundamental concepts that underlie them.



##  Singly Linked List
Keeping its educational aim in mind, the `SLL` class developed here closely resembles the behavior of `std::forward_list`, with minor adjustments aimed at emphasizing simplicity and focusing on the core aspects of the data structure.
<p align="center"><img src="./img/LibraryFlistItr.png"/></p>

One significant simplification is the omission of the iterator classes as a member variables. This decision was made to avoid the complexities associated with navigating the intricate hierarchy of iterator classes and templates found in `std::forward_list`, allowing to maintain focus on the key features of the ADT.

---
<p align="center"><img src="./img/DemonstrationSLL.png"/></p>

**Detailed Overview:**
1. The `SLL` class is declared in `SinglyLinkedList.h` header file and defined in `SinglyLinkedList.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Testing of the class functionalities is conducted within the `main()` function located in the `Main.cpp` file.
2. Whole class declaration:
```cpp
template<class T>
class SLL {
private:
	struct Node {
	public:
		T _data;
		Node* _next;

		// Special Member Functions
		Node(const T& newData, Node* nextNode = nullptr)
			: _data(newData), _next(nextNode) {}
		Node()                           = default;
		Node(const Node& rhs)            = delete;
		Node& operator=(const Node& rhs) = delete;
	};

	int _size;
	Node* _head;

public:
	// Special Member Functions
	SLL();
	// SLL(const std::initializer_list<T>& initList); remove due to init list
	SLL(const SLL& rhs);
	SLL& operator=(const SLL& rhs);
	~SLL();

	// Element Access
	T& operator[](const int index);
	const T& operator[](const int index) const;
	T& front();
	const T& front() const;

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void clear();
	void insertAfter(const int index, const T& newData);
	void eraseAfter(const int index);
	void pushFront(const T& newData);
	void popFront();
};
```

3. Special member functions:
```cpp
// Default Constructor
template<typename T>
SLL<T>::SLL() : _size(0), _head(nullptr) {}

//// Parametrized constructor
//template<class T>
//SLL<T>::SLL(const std::initializer_list<T>& initList) { }

// Deep copy constructor 
template<class T>
SLL<T>::SLL(const SLL& rhs) : _size(rhs._size) {
	// Case: empty list
	if (rhs._head == nullptr) {
		_head = nullptr;
		return;
	}

	// Create corresponding first node
	_head = new Node(rhs._head->_data);

	// Initialize traversal pointers
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;

	// Copy other nodes
	while (currentRhs) {
		current->_next = new Node(currentRhs->_data);
		current = current->_next;
		currentRhs = currentRhs->_next;
	}
}

// Deep copy assignment operator
template<class T>
SLL<T>& SLL<T>::operator=(const SLL& rhs) {
	// Self-assignment guard
	if (this == &rhs)
		return *this;

	// Ensure that the destination list doesn't retain any of its existing elements
	clear();
	// Set corresponding size
	_size = rhs._size;

	// Case: empty list
	if (rhs._head == nullptr) {
		_head = nullptr;
		return *this;
	}

	// Create corresponding first node
	_head = new Node<T>(rhs._head->_data);

	// Initialize traversal pointers
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;

	// Copy other nodes
	while (currentRhs) {
		current->_next = new Node<T>(currentRhs->_data);
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Maintain the proper reference to the head
	_head = current;

	return *this;
}

// Destructor
template<typename T>
SLL<T>::~SLL() { clear(); }
```

4. Element access:
```cpp
// Accesses the element at the specified index, no range check, allows modification
template<class T>
T& SLL<T>::operator[](const int index) {
	// Initialize traversal variables
	int counter = 0;
	Node* current = _head;

	while (current != nullptr) {
		// Return value of matched node
		if (counter == index) {
			return current->_data;
		}
		// Otherwise keep traversing
		current = current->_next;
		counter++;
	}
}

// Accesses the element at the specified index, no range check, denies modification
template<class T>
const T& SLL<T>::operator[](const int index) const {
	// TODO: range check

	// Initialize traversal variables
	int counter = 0;
	Node* current = _head;

	while (current != nullptr) {
		// Return value of matched node
		if (counter == index) {
			return current->_data;
		}
		// Otherwise keep traversing
		current = current->_next;
		counter++;
	}
}

// Accesses the first element in the container, no range check, allows modification
template<class T>
T& SLL<T>::front() { return _head->_data; }

// Accesses the first element in the container, no range check, denies modification
template<class T>
const T& SLL<T>::front() const { return _head->_data; }
```

5. Capacity methods:
```cpp
// Checks if the container has no elements
template<class T>
bool SLL<T>::empty() const { return _size == 0; }

// Returns the number of elements in the container
template<typename T>
int SLL<T>::size() const { return _size; }
```

6. Modifiers:
```cpp
// Erases all elements from the container
template<typename T>
void SLL<T>::clear() {
	// Case: empty list
	if (!_head)
		return;

	// Traverse the list and deallocate memory for each node
	while (_head) {
		Node* current = _head;
		_head = _head->_next;
		delete current;
	}

	// Update the state of list
	_size = 0;
	_head = nullptr;
}

// Inserts elements after the specified position in the container
// Note: with no bounds check, assumes that index is correct
template<class T>
void SLL<T>::insertAfter(const int index, const T& newData) {
	if (index == 0) {
		pushFront(newData);
	}
	else {
		// Create a new node with the given data
		Node* newNode = new Node(newData);

		// Find the node at the specified index
		Node* current = _head;
		for (int i = 0; i < index - 1; i++) {
			current = current->_next;
		}

		// Insert the new node after the current one
		newNode->_next = current->_next;
		current->_next = newNode;

		// Update the size
		++_size;
	}
}

// Removes an element at the specified position
// Note: with no bounds check, assumes that index is correct
template<class T>
void SLL<T>::eraseAfter(const int index) {
	if (index == 0) {
		popFront();
	}
	else {
		// Traverse to the node before the node to be erased
		Node* current = _head;
		for (int i = 0; i < index; ++i) {
			current = current->_next;
		}

		// Remove
		Node* nodeToDelete = current->_next;
		current->_next = nodeToDelete->_next;
		delete nodeToDelete;

		// Update the size
		--_size;
	}
}

// Prepends the given element value to the beginning of the container
template<typename T>
void SLL<T>::pushFront(const T& newData) {
	// Create a new node with the given data
	Node* newNode = new Node(newData);

	// Case: empty list
	if (_size == 0) {
		_head = newNode;
	}
	else {
		// Push front
		newNode->_next = _head;
		_head = newNode;
	}

	// Update the size
	++_size;
}

// Removes the first element of the container
// Note: with no bounds check, assumes that list contains at least 1 element
template<class T>
void SLL<T>::popFront() {
	// TODO: range check

	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the head pointer to the next node
	Node* temp = _head;
	_head = _head->_next;
	delete temp;

	// Update the size
	--_size;
}
```



##  Doubly Linked List
Keeping its educational aim in mind, the `DLL` class developed here closely resembles the behavior of `std::list`, with minor adjustments aimed at emphasizing simplicity and focusing on the core aspects of the data structure.
<p align="center"><img src="./img/LibraryListItr.png"/></p>

One significant simplification is the omission of the iterator classes as a member variables. This decision was made to avoid the complexities associated with navigating the intricate hierarchy of iterator classes and templates found in `std::list`, allowing to maintain focus on the key features of the ADT.

---
<p align="center"><img src="./img/DemonstrationDLL.png"/></p>

**Detailed Overview:**
1. The `DLL` class is declared in `DoublyLinkedList.h` header file and defined in `DoublyLinkedList.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Testing of the class functionalities is conducted within the `main()` function located in the `Main.cpp` file.
2. Whole class declaration:
```cpp
template<class T>
class DLL {
private:
	struct Node {
	public:
		T _data;
		Node* _next;
		Node* _prev;

		// Special Member Functions
		Node(const T& newData, Node* nextNode = nullptr, Node* prevNode = nullptr)
			: _data(newData), _next(nextNode), _prev(prevNode) {}
		Node()                           = default;
		Node(const Node& rhs)            = delete;
		Node& operator=(const Node& rhs) = delete;
	};

	int _size;
	Node* _head;
	Node* _tail;

	// Facilitator method
	Node* getStartingNode(int index) const;

public:
	// Special Member Functions
	DLL();
	// DLL(const std::initializer_list<T>& initList); remove due to init list
	DLL(const DLL& rhs);
	DLL& operator=(const DLL& rhs);
	~DLL();

	// Element Access
	T& operator[](const int index);
	const T& operator[](const int index) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	// Capacity 
	bool empty() const;
	int size() const;

	// Modifiers
	void clear();
	void insert(const int index, const T& newData);
	void erase(const int index);
	void pushFront(const T& newData);
	void popFront();
	void pushBack(const T& newData);
	void popBack();
};
```

3. Facilitator Method (replaces iterator functionaly of determining whether to start from head or tail):
```cpp
// Determine whether to start traversal from the head or tail
template<typename T>
typename DLL<T>::Node* DLL<T>::getStartingNode(int index) const {
	Node* startingNode;
	int distanceFromHead = index;
	int distanceFromTail = _size - index - 1;

	if (distanceFromHead <= distanceFromTail) {
		startingNode = _head;
		for (int i = 0; i < index; ++i) {
			startingNode = startingNode->_next;
		}
	}
	else {
		startingNode = _tail;
		for (int i = _size - 1; i > index; --i) {
			startingNode = startingNode->_prev;
		}
	}

	return startingNode;
}
```

4. Special member functions:
```cpp
// Default constructor
template<typename T>
DLL<T>::DLL() : _size(0), _head(nullptr), _tail(nullptr) {}

//// Parametrized constructor
//template<class T>
//DLL<T>::DLL(const std::initializer_list<T>& initList) { }

// Deep copy constructor
template<class T>
DLL<T>::DLL(const DLL& rhs) : _size(rhs._size) {
	// Case: empty list
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return;
	}

	// Create corresponding first node
	_head = new Node(rhs._head->_data);

	// Initialize traversal pointers
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;

	// Copy other nodes
	while (currentRhs) {
		current->_next = new Node(currentRhs->_data);
		current->_next->_prev = current;
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Maintain proper reference to the end
	_tail = current;
}

// Deep copy assignment operator
template<class T>
DLL<T>& DLL<T>::operator=(const DLL& rhs) {
	// Self-assignment guard
	if (this == &rhs)
		return *this;

	// Ensure that the destination list doesn't retain any of its existing elements
	clear();

	// Set corresponding size
	_size = rhs._size;

	// Case: empty list
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return *this;
	}

	// Create corresponding first node
	_head = new Node(rhs._head->_data);

	// Initialize traversal pointers
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;

	// Copy other nodes
	while (currentRhs) {
		current->_next = new Node(currentRhs->_data);
		current->_next->_prev = current;
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Maintain proper reference to the end
	_tail = current;

	return *this;
}

// Destructor
template<typename T>
DLL<T>::~DLL() { clear(); }
```

5. Element access:
```cpp
// Accesses the element at the specified index, no range check, allows modification
template<class T>
T& DLL<T>::operator[](const int index) {
	// Traverse to the required node
	Node* current = getStartingNode(index);
	return current->_data;
}

// Accesses the element at the specified index, no range check, denies modification
template<class T>
const T& DLL<T>::operator[](const int index) const {
	// Traverse to the required node
	Node* current = getStartingNode(index);
	return current->_data;
}

// Accesses the first element in the container, no range check, allows modification
template<class T>
T& DLL<T>::front() { return _head->_data; }

// Accesses the first element in the container, no range check, denies modification
template<class T>
const T& DLL<T>::front() const { return _head->_data; }

// Accesses the last element in the container, no range check, allows modification
template<class T>
T& DLL<T>::back() { return _tail->_data; }

// Accesses the last element in the container, no range check, denies modification
template<class T>
const T& DLL<T>::back() const { return _tail->_data; }
```

6. Capacity methods:
```cpp
// Checks if the container has no elements
template<class T>
bool DLL<T>::empty() const { return _size == 0; }

// Returns the number of elements in the container
template<typename T>
int DLL<T>::size() const { return _size; }
```

7. Modifiers:
```cpp
// Erases all elements from the container
template<typename T>
void DLL<T>::clear() {
	// Case: empty list
	if (!_head)
		return;

	// Traverse the list and deallocate memory for each node
	while (_head) {
		Node* current = _head;
		_head = _head->_next;
		delete current;
	}

	// Update the state
	_size = 0;
	_tail = _head = nullptr;
}

// Inserts elements after the specified position in the container
// Note: with no bounds check, assumes that index is correct
template<class T>
void DLL<T>::insert(const int index, const T& newData) {
	if (index == 0) {
		pushFront(newData);
	}
	else if (index == _size - 1) {
		pushBack(newData);
	}
	else {
		// Insert new node at specified position
		Node* prevNode = getStartingNode(index - 1);
		Node* newNode = new Node(newData);
		newNode->_next = prevNode->_next;
		newNode->_prev = prevNode;
		prevNode->_next = newNode;

		// Update the size
		++_size;
	}
}

// Removes an element at the specified position
// Note: with no bounds check, assumes that index is correct
template<class T>
void DLL<T>::erase(const int index) {
	if (index == 0) {
		popFront();
	}
	else if (index == _size - 1) {
		popBack();
	}
	else {
		// Remove specified node
		Node* prevNode = getStartingNode(index - 1);
		Node* nodeToErase = prevNode->_next;
		prevNode->_next = nodeToErase->_next;
		nodeToErase->_next->_prev = prevNode;
		delete nodeToErase;

		// Update the size
		--_size;
	}
}

// Prepends the given element value to the beginning of the container
template<typename T>
void DLL<T>::pushFront(const T& newData) {
	// Create a new node with the given data
	Node* newNode = new Node(newData);

	// Case: empty list
	if (_size == 0) {
		_head = _tail = newNode;
	}
	else {
		// Push front
		_head->_prev = newNode;
		newNode->_next = _head;
		_head = newNode;
	}

	// Update the size
	++_size;
}

// Removes the first element of the container
// Note: with no bounds check, assumes that list contains at least 1 element
template<class T>
void DLL<T>::popFront() {
	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the head pointer to the next node
	Node* temp = _head;
	_head = _head->_next;
	_head->_prev = nullptr;
	delete temp;

	// Update the size
	--_size;
}

// Appends the given element to the end of the container
template<class T>
void DLL<T>::pushBack(const T& newData) {
	// Create a new node with the given data
	Node* newNode = new Node(newData);

	// Case: empty list
	if (_size == 0) {
		_head = _tail = newNode;
	}
	else {
		// Push back
		_tail->_next = newNode;
		newNode->_prev = _tail;
		_tail = newNode;
	}

	// Update the size
	++_size;
}

// Removes the last element of the container
// Note: with no bounds check, assumes that list contains at least 1 element
template<class T>
void DLL<T>::popBack() {
	// Case: one element
	if (_size == 1) {
		clear();
		return;
	}

	// Move the tail pointer to the previous node
	_tail = _tail->_prev;
	delete _tail->_next;
	_tail->_next = nullptr;

	// Update the size
	--_size;
}
```


##  Circular Linked List
Circular linked lists can be implemented based on either singly or doubly linked lists. This implementation doesn't fundamentally alter the functionality; rather, it changes how operations are performed. Unlike standard linked lists, there isn't a built-in container for circular linked lists in the STL. Therefore, I chose to implement it based on a doubly linked list for personal preference.
<p align="center"><img src="./img/DemonstrationCLL.png"/></p>

The concept behind creating this type of container revolves around ensuring that the tail node's next pointer points to the head and vice versa. This necessitates minor adjustments to the overall structure to avoid circular references. Specifically, it means you can't iterate through the list by checking for nullptr, and it requires assigning proper values to the pointers after making corresponding changes. For the complete implementation, please refer to the [project's directory](https://github.com/vezzolter/DSA/tree/main/DataStructures/LinkedList/CircularLinkedList). Here, I'll provide a simple examples:

You can't iterate via check for nullptr:
```cpp
// Deep copy assignment operator
template<class T>
CLL<T>& CLL<T>::operator=(const CLL& rhs) {
	// Self-assignment guard
	if (this == &rhs)
		return *this;

	clear();
	_size = rhs._size;

	// Case: empty list
	if (rhs._head == nullptr) {
		_head = _tail = nullptr;
		return *this;
	}

	_head = new Node(rhs._head->_data);
	Node* currentRhs = rhs._head->_next;
	Node* current = _head;
	Node* originalHead = rhs._head; // Save the original head of the list

	while (currentRhs != originalHead) {
		current->_next = new Node(currentRhs->_data);
		current->_next->_prev = current;
		current = current->_next;
		currentRhs = currentRhs->_next;
	}

	// Make the list circular
	_tail = current;
	_tail->_next = _head;
	_head->_prev = _tail;

	return *this;
}
```

You have to ensure, that referrences to the tail/head are proper:
```cpp
// Prepends the given element value to the beginning of the container
template<typename T>
void CLL<T>::pushFront(const T& newData) {
	Node* newNode = new Node(newData);

	// Case: empty list
	if (_size == 0) {
		_head = _tail = newNode;
		newNode->_next = newNode->_prev = newNode; // Make the list circular
	}
	else {
		// Push front
		newNode->_next = _head;
		newNode->_prev = _tail;
		_head->_prev = newNode;
		_head = newNode;

		// Update the tail's next pointer to point to the new head
		_tail->_next = _head;
	}

	++_size;
}
```



# &#128202; Analysis
**Advantages:**
- **Efficient Element Rearraging** — elements is efficient due to simple change of pointers, e.g. insertion and deletion takes $O(1)$ time.
- **Diverse Memory Allocation** — in some scenarios, where it is hard to allocate a single-block of memory, linked list can come in handy, due to the distribution of cells throughout the memory.
- **Minimizing Unused Space** — unused nodes can be removed, preventing them from occupying memory cells intended for other data.

---
**Disadvantages:**
- **Inefficient Sequential Access** — in order to reach a specific element, it is necessary to traverse through the other elements first, e.g. access and search takes $O(n)$ time.
- **Additional Memory Consumption** — each node requires memory allocation not only for the data but also for the pointers.



# &#128221; Application
**Some of the Most Well-Known Use Cases:**
- **Algorithms and Data Structures** — graph path traversal algorithms and various data structures like stacks, queues, hash tables, tree and graphs representations often use lists as their underlying structure.
- **Back/Next Functionality** — linked lists are commonly utilized in implementing back/next navigating functionality, such as in web browsers with nodes as web pages or music players with nodes as songs.
- **Undo/Redo Functionality** — something similar to previous point, but desribes the cases, where each action performed by the user is stored as a node in separate linked lists, therefore allowing users to revert to previous states of the application or redo previously undone actions by traversing the respective lists.
- **Scheduling/Ordering** — each task or element is represented as a node in the linked list, and scheduling decisions are made based on the order (by priority, arrival time, or other criteria) of nodes in the list. 
- **File System Management** — lists used in file system management for maintaining directory structures, file metadata, and file allocation tables, where each directory entry or file descriptor is stored as a node, facilitating efficient traversal and manipulation of file system objects.

---
**Common Practical Problems:**
- Reverse a linked list.
- Delete without head pointer.
- Remove duplicate elements from sorted linked list.
- Mergea linked list into another linked list at alternate positions.
- Finding the length of a loop in linked list.
- Occurence of an integer in a Linked List.
- Convert singly linked list into circular linked list.
- Merge two sorted linked lists.
- Intersection point of two Linked Lists.
- Swap Kth node from beginning with Kth node from end in a Linked List.
- Convert a given Binary Tree to Doubly Linked List.
- Rearrange a given linked list in-place.
- Flattening a Linked List.
- Partition a linked list around a given value.
- Move Last Element of Linked List to Front.
- Sort a Linked List which is already sorted on absolute values.


# &#x1F559; Origins
The concept of linked lists, renowned for their efficient dynamic memory management, has evolved over time and there is no single individual behind them, especially because historical origins are not always well-recorded. Documented mention of them comes from **Hans Peter Luhn** in **1953**, who conceived of linked lists as a solution for Chained Hash Maps. Nevertheless, the first notable contribution to the practical implementation of this concept in the field of programming comes from **Allen Newell**, **Cliff Shaw** and **Herbert Alexander Simon**, who developed Information Processing Language in **1955–1956** at RAND Corporation and Carnegie Mellon University. From that point on in programming history, 
linked lists quickly gained widespread adoption and underwent continuous development by programmers worldwide, becoming a fundamental component in various programming languages and data structures.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 10.2: Linked Lists
  - Section 10.3: Implementing Pointers and Objects
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 3.1: Building Blocks
  - Section 3.3: Linked Lists
  - Section 3.4: Elementary List Processing
  - Section 3.5: Memory Allocation for Lists
  - Section 4: Abstract Data Types
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 3.1: Abstract Data Types
  - Section 3.2: The List ADT
  - Section 3.3: `vector` and `list` in the STL
  - Section 3.5: Implementation of `list`
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 3.1: Contiguous vs. Linked Data Structures
- **"The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd Edition)** — by Donald Ervin Knuth 
  - Section 2.2: Linear Lists
  - Section 2.4: Multilinked Structures
  - Section 2.5: Dynamic Storage Allocation
  - Section 2.6: History and Bibliography

---
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 11: Linked List
   - Section 12: Sparse Matrix and Polynomial using Linked List
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) from Coursera
   - Course 2.1: Linear Structures

---  
&#127760; **Web-Resources:**  
- [Linked List](https://en.wikipedia.org/wiki/Linked_list) (Wikipedia)
- [How Linked Lists Work](https://www.freecodecamp.org/news/how-linked-lists-work/)
- [Linked List Data Structure](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)
- [Linked Lists](https://sbme-tutorials.github.io/2020/data-structure-FALL/notes/week03b.html#:~:text=of%20the%20list.-,Singly%20Linked%20Lists,is%20known%20as%20the%20tail.)
- [std::forward_list](https://en.cppreference.com/w/cpp/container/forward_list)
- [std::list](https://en.cppreference.com/w/cpp/container/list)
- [Advantages and Disadvantages of Linked List](https://www.geeksforgeeks.org/advantages-and-disadvantages-of-linked-list/)
- [Practice Coding Problems on Linked List](https://iq.opengenus.org/list-of-linked-list-problems/)
- [Top 50 Problems on Linked List Data Structure asked in SDE Interviews](https://www.geeksforgeeks.org/top-20-linked-list-interview-question/)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)