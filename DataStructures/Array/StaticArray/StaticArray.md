# &#128209; Table of Contents
- [💡 Overview](#-overview)
	- [Important Details](#important-details)
	- [Container Methods](#container-methods)
- [💻 Implementation](#-implementation)
	- [Design Decisions](#design-decisions)
	- [Container Implementation](#container-implementation)
	- [Iterators Implementations](#iterators-implementations)
- [📊 Analysis](#-analysis)
	- [Characteristics](#characteristics)
	- [Trade-Offs](#trade-offs)
- [📝 Application](#-application)
	- [Common Use Cases](#common-use-cases)
	- [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
**Static array** is an implementation of an array where the size is fixed, meaning it can't be changed during runtime. Its name comes from this fact. Knowledge and understanding of it lay a solid foundation in designing data structures and optimizing their application.
<p align="center"><img src="./Images/StaticArray.png"/></p>


## Important Details
1. **Size (Fixed)** — static array has a fixed size, meaning the size can't be changed during runtime.

2. **Time for Allocation (Compile)** — static array requires knowing size at a compile time, meaning its size can only be based on values known during the compilation phase.

3. **Place for Allocation (Stack)** — static array usually allocated in the stack memory section, limiting its size to relatively small amounts (since stack memory is limited). However, static arrays can also be allocated in the global/static/heap memory section, though this is less common.

4. **Memory Management (Automatic)** — static array allocated on stack doesn't require manual memory management, meaning the system automatically handles allocation and deallocation, avoiding risks such as dangling pointers or memory leaks.

5. **Speed of Allocation (Fast)** — static array's allocation on the stack is faster than on the heap, because it doesn't require additional operations or resources to manage memory.


## Container Methods
When working with static array, it's important to note that there is no universal standard defining a strict list of operations or guidelines for how they should be implemented. The design and functionality of a container can vary depending on several factors, such as the programming language, the purpose of the library, performance considerations, etc. Despite these variations, there are still common operations found across most implementations, typically derived from the fundamental needs of data manipulation, like accessing, modifying, or iterating over elements. Since this repository is dedicated to C++, the operations provided will closely resemble those found in `std::array`.

---
**Compiler Generated:**
- `Default Constructor` — creates an empty array.
- `Parametrized Constructors` — there are usually many ways to construct and initialize the container, and it’s often up to the developer to decide which ones to implement based on the container’s needs.
- `Copy Constructor` — creates a new array by copying the structure and values of another array.
  - if the other array is empty, initializes an empty array.
- `Move Constructor` — creates a new array by transferring ownership of the memory from another array, leaving the original array in a valid but unspecified state.
  - if the other array is empty, initializes an empty array.
- `Copy Assignment Operator` — overwrites each element of already existing array with the corresponding element of another array by copying them.
  - if the other array is empty, initializes an empty array.
- `Move Assignment Operator` — overwrites each element of already existing array with the corresponding element of another array by transferring ownership of the memory from another array, leaving the original array in a valid but unspecified state.
  - if the other array is empty, initializes an empty array.
- `Destructor` — releases the array's allocated memory, calling destructors for complex data types to ensure proper cleanup of resources.

---
<p align="center"><img src="./Images/OperationsIterators.png"/></p>

**Iterators:**
- `begin`, `cbegin` — returns an iterator (or constant iterator) to the first element.
- `end`, `cend` — returns an iterator (or constant iterator) to the position one past the last element, making range $[begin, end)$ easy for traversal.
- `rbegin`, `crbegin` — returns an iterator (or constant one) to the last element.
- `rend`, `crend` — returns an iterator (or constant one) to the position one before the first element, making range $[rend, rbegin)$ easy for traversal.

---
<p align="center"><img src="./Images/OperationsAccess.png"/></p>

**Element Access:**
- `at()` — returns specified element with bounds checking.
  - if the specified element is out of range, throws an exception.
- `operator[]` — returns specified element without bounds checking.
  - accessing an element outside the range of the container results in undefined behavior
- `front()` — returns the first element in the container.
  - calling on an empty container results in undefined behavior.
- `back()` — returns the last element in the container.
  - calling on an empty container results in undefined behavior.

---
**Capacity:**
- `empty()` — returns `true` if container is empty, otherwise `false`.
- `size()` — returns the total number of elements in the array, equivalent to the distance between `begin` and `end`.
- `maxSize()` — returns the maximum number of elements the container is able to hold theoretically based on system's memory limitations, if all available memory were dedicated to that single container.

---
**Modifiers:**
- `fill()` — assigns the given value to the elements; any previous values will be replaced; invalidates any references, pointers, and iterators referring to contained elements.
- `swap()` — exchanges the contents of the container with other given container; doesn't cause iterators and references to associate with the other container.



# &#x1F4BB; Implementation 
The implemented console application demonstrates the basic functionality of the static array by performing various operations and interactions with it. The program provides a clear view of changes made during usage, displaying the state of the data at different stages to illustrate its simplified behavior and characteristics.
<p align="center"><img src="./Images/Demonstration.png"/></p>


## Design Decisions
To prioritize simplicity and emphasize data structure itself, several design decisions were made:
- Resembling the behavior of `std::array` to provide familiarity for users.
- Opting to use constant as a size of the container.
- Implementing only regular and const iterators (no reverse versions).
- Limiting iterator functions to regular iterators to avoid templates.
- Restricting the container to `int` to avoid templates.
- Omitting cases where the container (object itself) is created on the heap.
- Excluding move semantics to keep the focus on fundamental mechanics.
- Relying on manual memory management without using smart pointers.
- Avoiding any exception handling, thus certain range validations.
- Omitting certain possible optimizations to the container.


## Container Implementation
The container is implemented within the `SA` class, which is declared in [StaticArray.h](https://github.com/vezzolter/DSA/blob/main/DataStructures/Array/StaticArray/Include/StaticArray.h) header file and defined in [StaticArray.cpp](https://github.com/vezzolter/DSA/blob/main/DataStructures/Array/StaticArray/Source/StaticArray.cpp) source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. To see the container's functionality in action, you can examine the `main()` function located in the [Main.cpp](https://github.com/vezzolter/DSA/blob/main/DataStructures/Array/StaticArray/Source/Main.cpp) file. The full implementation can be found in the corresponding files, while the class declaration below offers a quick overview:

```cpp
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

	// -----------
	//  Modifiers
	// -----------
	void fill(int val);
	void fill(iterator first, iterator last);
	void swap(SA& other);
};
```


## Iterators Implementations
Since there are various types of iterators that can be implemented (e.g. the image below shows the iterators for `std::array`), it's common practice to define them in separate classes and files. However, despite being implemented separately, their underlying principles are usually similar, with only slight adjustments for specific purposes. To keep things simpler and avoid cluttering the core concepts, this container implements regular and constant iterator classes. Those iterators cover the basic $[begin, end)$ range and demonstrates how typical iterators operations are handled, as well as how the iterators classes are integrated into the static array container.
<p align="center"><img src="./Images/LibraryIterators.png"/></p>

---
The `Iterator` class is defined as a public nested class within the `SA` container. This design makes `Iterator` accessible to users, enabling them to traverse and interact with array elements directly. Given the simplicity of the `Iterator` class, its functions are defined inline within the container's header file.

```cpp
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
```

---
The `ConstIterator` class is defined as a public nested class within the `SA` container. This design makes `ConstIterator` accessible to users, enabling them to traverse and interact with array elements directly. Given the simplicity of the `ConstIterator` class, its functions are defined inline within the container's header file.

```cpp
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
```



# &#128202; Analysis
Understanding how to analyze the particular container is crucial for optimizing performance and ensuring efficient resource utilization within the constraints of the given environment. Additionally, knowing its strengths and weaknesses allows for more informed decisions, helping to select the most suitable container for a given problem among similar options.


## Characteristics
🚀 **Time Complexities:**
 - **Access** $O(1)$ — because the address can be computed directly for any position, without needing to traverse the collection.
 - **Insertion** $O(-)$ — because the size of a static array cannot be changed, so deletion is not possible.
 - **Deletion** $O(-)$ — because the size of a static array cannot be changed, so deletion is not possible.
 - **Other** — while more operations exist, they are generally not considered core functionalities to pick a container for.

---
🧠 **Space Expenses:**
- **No overhead** — both operations are conducted and elements are stored without any additional memory (e.g., pointers, extra structures, etc.) required beyond the data itself.


## Trade-Offs
➕ **Advantages:**
- **Compile-Time Storage** — static arrays allow the storage of values at compile time, which removes the need for runtime memory allocation. This leads to better memory management and increased stability in situations where data size and content are known ahead and fixed during program execution.
- **Efficient Random Access** — static arrays facilitate efficient access to the elements within the collection. Regardless of the array's length, accessing elements has a constant time complexity.
- **Efficient Memory Utilization** — static arrays store data in contiguous memory locations, preventing additional memory wastage for tracking elements. Also, ability for the allocation of memory in a single block, reduces memory fragmentation.

---
➖ **Disadvantages:**
- **Compile-Time Storage** — static arrays don't allow to change size, thus insert and delete elements. Additionally, it requires the size to be known ahead, which is not always possible.
- **Enormous Single Block** — static arrays with large size can be problematic to allocate due to contiguous memory locations, which potentially can cause a crash.
- **Wasted Space** — static arrays that are not not fully populated, may leave lots of memory unused.
- **Out-of-Bound Access** — static arrays make it easy to miscalculate an index, leading to access outside the valid range and causing undefined behavior.



# &#128221; Application
Understanding some of the most well-known use cases of a container is crucial for grasping its practical relevance and potential impact in real-world scenarios. Additionally, familiarizing oneself with common practical problems and practicing their solutions ensures that you remember the essential details and develop a deep, intuitive understanding of the functionality and limitations.


## Common Use Cases
As mentioned in the [Array.md](https://github.com/vezzolter/DSA/blob/main/DataStructures/Array/Array.md), the concrete use cases (and anti use cases) directly derive from the advantages (and disadvantages) of the container, so there is no need for this sort of rephrasing. Since static arrays share the foundational principles of the general concept of arrays, their common usage is best described in the [arrays respective section](../Array.md#-application).


## Some Practical Problems
Since static arrays share the foundational principles of the general concept of arrays, their common problems is best described in the [arrays respective section](../Array.md#-application).



# &#x1F559; Origins
Since static arrays share the foundational principles of the general concept of arrays, their historical development is best described in the [arrays origins section](../Array.md#-origins).



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contacts).



# &#128591; Credits
Since static arrays share the foundational principles of the general concept of arrays, the resources that contributed to their understanding are best described in the [arrays credits section](../Array.md#-credits).



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)