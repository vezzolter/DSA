# &#128209; Table of Contents
- [💡 What is the Array as ADT](#-what-is-the-array-as-adt)
- [💻 Implementation](#-implementation)
  - [🧍‍♂️ Static Array](#️-static-array)
  - [🚶‍♂️ Dynamic Array](#️-dynamic-array)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is the Array as ADT

An array is a fundamental concept in computer programming. Arrays are widely used not only because they provide a natural, structured way to organize and access data, they also serve as a lower-level mechanism for memory management. The concept of an array encompasses both a basic data structure, as a part of programming language, and an abstract data structure (ADT), which involves a conceptual representation that defines operations without specifying the implementation details.

This subsection explores the ADT of Arrays not only to enhance understanding, but also to establish a solid foundation for approaching more intricate data structures.


<p align="center"><img src="./img/memoryCells.png"/></p>

---

**Array** — is a linear data structure that collects elements of the same data type and stores them in contiguous and adjacent memory locations. It introduces the following essential terms:
- **Element** — each individual data value contained within the array. These data values can be anything from promitive types such as integers to more complex types like instances of classes. Since elements don't have their unique names, the only way to access them is through their respective indices.
- **Index** — integer value which specifies the element's position within the array, usually starting with the first as $0$ and concluding with the last as $length-1$.
- **Length (Size)** — is a number of elements contained in the array.
- **Capacity** — is the maximum number of possilbe elements for which there is currently allocated memory within array. This term is primarily associated with dynamic arrays because they aim to minimize frequent resize operations by reserving additional space for potential future elements.

<p align="center"><img src="./img/arrayIndices.png"/></p>

---
When it comes to implementation, arrays can be broadly classified into two types: static and dynamic. While these types share some common ideas, each possesses distinctive characteristics. The choice between them depends on the specific requirements of the case at hand.

<p align="center"><img src="./img/heapStack.png"/></p>

1. **Static Array** — array with a fixed nature, possesses the following properties:
    - memory is allocated on the stack during compile time;
    - automatic memory management;
    - length can not be changed during runtime.

2. **Dynamic Array** — array with a flexible nature, possesses the following properties:
    - memory is allocated on the heap during runtime;
    - manual memory management (potential issues like dangling pointers and memory leaks);
    - length cannot be changed during runtime, but there is a resourceful alternative: creating a new one, copying values, and performing respective memory operations.

---

**Common Operations for ADT Array:**
- **Traversal** — iterating through the elements of the array.
- **Acess** — retrieving or updating the value of an existing element.
- **Insertion** — adding a new element to the array.
- **Deletion** — removing an element from the array.
- **Search** — locating a specific element within the array.
- **Sorting** — arranging the elements of the array in a specific order.
- **Merging** — combining two arrays into one.
- **Splitting** — dividing the array into two or more parts.
- **Filtering** — selecting specific elements based on certain criteria.

---

**"Size-Consistent" Operations**

One of the most prominent feature of the arrays is that they provide efficient **random (direct) access**. It is mainly possible, because of the fact, that name of an array generates a pointer to the first element of the array (index 0), which results in synergy for address arithmetic and array indexing.


**Address (Pointer) Arithmetic** — is a concept of manipulating memory addresses using arithmetic operations, which allows for efficient navigation through data structure.

```cpp
int value = 5;
int *ptr = &value; // points onto variable of type 'int'                         >>>   002CF9A4
cout << ptr + 1;   // point onto next value of int (+4 bytes)                          002CF9A8
cout << ptr - 1;   // point onto prev value of int (-4 bytes)                          002CF9A0
```
<p align="center"><img src="./img/addressArithmetic.png"/></p>

**Array Indexing** — process of accessing elements within an array, typically achieved internally through address arithmetic.
```cpp
int arr[5] = {7, 8, 2}; // simple static array                value:    7     8    2
cout << array[1];   //  this                                  index:    0     1    2
cout << *(array+1); //  equals to this                   expression: array  a+1  a+2
```

---

**"Size-Manipulating" Operations**

Because arrays use single-block memory allocation, any operation that alters their size requires the resource-intensive process of allocating a new array, copying values, and deallocating the previous one. While dynamic arrays address this inefficiency to some extent with their capacity feature, the need to 'move' arrays still exists, albeit less frequently.

```cpp
// Simple mimic of how push back function of a std::vector works for adding new element
void push_back(const T& element)
{
	// If capacity is insufficient,
    if (size >= capacity)
	{
		// Create new array with doubled capacity
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[capacity];

        // Copy existing elements to new array
        for (size_t i = 0; i < size; ++i)
            newData[i] = data[i];

        // Add new element to the end
        newData[size] = element;

        // Delete old array and update pointer
        delete[] data;
        data = newData;
    }
	else
	{
        // Add new element to existing array
        data[size] = element;
    }
    ++size;
}
```


# &#x1F4BB; Implementation 
Discussing ADT, it's evident that well-established and widely recognized implementations already exist for both static and dynamic arrays. In the context of C++, `std::array` is a representative of static arrays, and `std::vector` stands as the counterpart for dynamic arrays. It's commonly recommended to rely on these proven implementations rather than reinventing the wheel. However, within the scope of this subsection, we'll take a closer look at simplified versions of these arrays. This exploration is aimed at gaining a deeper understanding of the fundamental concepts that underlie them.



## 🧍‍♂️ Static Array

**Detailed Overview**:
1. Keeping its educational aim in mind, the `SA` class developed here closely resembles the behavior of `std::array`, with minor adjustments aimed at emphasizing simplicity and focusing on the core aspects of the data structure.

2. One significant simplification is the omission of the iterator classes as a member variables. This decision was made to avoid the complexities associated with navigating the intricate hierarchy of iterator classes and templates found in `std::vector`, allowing to maintain focus on the key features of the ADT.

<p align="center"><img src="./img/stdArrIt.png"/></p>

3. Additionally, various types of bounds checking were omitted due to the situational nature of error resolution. As an instance of this omission, one of the ways of element access, known as method `at()` in `std::array` was skipped.

<p align="center"><img src="./img/stdArrAt.png"/></p>

4. The `SA` class is declared in `StaticArray.h` header file and defined in `StaticArray.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Testing of the class functionalities is conducted within the `main()` function located in the `Main.cpp` file.

5. Whole class declaration:
```cpp
template<class T, int MAX_SIZE>
class SA {
private:
	int _size;
	T _data[MAX_SIZE];

public:
	// Special Member Functions
	SA();
	SA(int size);
	SA(const SA& rhs);
	SA& operator=(const SA& rhs);
	~SA() = default;

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
};
```

6. Special member functions:
```cpp
// Default constructor
template<class T, int MAX_SIZE>
SA<T, MAX_SIZE>::SA() : _size(0) {
    for (int i = 0; i < MAX_SIZE; ++i)
        _data[i] = 0;
}

// Parameterized constructor, no range check
template<class T, int MAX_SIZE>
SA<T, MAX_SIZE>::SA(int size) : _size(size) {
    for (int i = 0; i < MAX_SIZE; ++i)
        _data[i] = 0;
}

// Shallow copy constructor
template<class T, int MAX_SIZE>
SA<T, MAX_SIZE>::SA(const SA& rhs) : _size(rhs._size) {
    for (int i = 0; i < _size; ++i)
        _data[i] = rhs._data[i];
}

// Shallow copy assignment operator
template<class T, int MAX_SIZE>
SA<T, MAX_SIZE>& SA<T, MAX_SIZE>::operator=(const SA& rhs) {
    // Self-assignment guard
    if (this == &rhs)
        return *this;

    _size = rhs._size;
    for (int i = 0; i < _size; ++i)
        _data[i] = rhs._data[i];

    return *this;
}
```

7. Element access:
```cpp
// Accesses the element at the specified index, allows modification, no range check
template<class T, int MAX_SIZE>
T& SA<T, MAX_SIZE>::operator[](const int index) { return _data[index]; }

// Accesses the element at the specified index, denies modification, no range check
template<class T, int MAX_SIZE>
const T& SA<T, MAX_SIZE>::operator[](const int index) const { return _data[index]; }

// Accesses the first element in the container, allows modification, no range check
template<class T, int MAX_SIZE>
T& SA<T, MAX_SIZE>::front() { return _data[0]; }

// Accesses the first element in the container, denies modification, no range check
template<class T, int MAX_SIZE>
const T& SA<T, MAX_SIZE>::front() const { return 0; }

// Accesses the last element in the container, allows modification, no range check
template<class T, int MAX_SIZE>
T& SA<T, MAX_SIZE>::back() { return _data[_size - 1]; }

// Accesses the last element in the container, denies modification, no range check
template<class T, int MAX_SIZE>
const T& SA<T, MAX_SIZE>::back() const { return 0; }
```

8. Capacity methods:
```cpp
// Checks if the container has no elements
template<class T>
bool DA<T>::empty() const { return (_size == 0); }

// Returns the number of elements in the container
template<class T>
int DA<T>::size() const { return _size; }
```

9. Demonstration:
```cpp
void printArray(const SA<int, 100>& arr) {
	std::cout << "Elements:\t";
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Static Array' console application!\n";

	// Create initial array #1
	std::cout << "\nCreating & filling initial array #1...\n";
	SA<int, 100> arr1(9);
	for (int i = 0; i < 9; i++)
		arr1[i] = i + 1;
	
	// Show array #1
	std::cout << "Is it empty:\t" << arr1.empty() << std::endl;
	printArray(arr1);

	// Access elements
	std::cout << " - first:\t" << arr1.front() << std::endl;
	std::cout << " - middle:\t" << arr1[arr1.size() / 2] << std::endl;
	std::cout << " - last:\t" << arr1.back() << std::endl;

	// Modify array #1
	std::cout << "\nChange first ('1') and last ('9') element to '0'...\n";
	arr1[0] = arr1[arr1.size() - 1] = 0;
	printArray(arr1);

	// Copy functionality
	std::cout << "\nCreate an array copies and compare...\n";
	SA<int, 100> arr2(arr1);
	SA<int, 100> arr3 = arr1;
	printArray(arr1);
	printArray(arr2);
	printArray(arr3);

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}
```

<p align="center"><img src="./img/demoSA.png"/></p>



## 🚶‍♂️ Dynamic Array

**Detailed Overview**:
1. Keeping its educational aim in mind, the `DA` class developed here closely resembles the behavior of `std::vector`, with minor adjustments aimed at emphasizing simplicity and focusing on the core aspects of the data structure.

2. One significant simplification is the omission of the iterator classes as a member variables. This decision was made to avoid the complexities associated with navigating the intricate hierarchy of iterator classes and templates found in `std::vector`, allowing to maintain focus on the key features of the ADT.

<p align="center"><img src="./img/stdVecIt.png"/></p>

3. Additionally, various types of bounds checking were omitted due to the situational nature of error resolution. As an instance of this omission, one of the ways of element access, known as method `at()` in `std::vector` was skipped.

<p align="center"><img src="./img/stdVecAt.png"/></p>

4. Key difference between static and dynamic ADT lies in the implementation of the memory management. The well-known `std::vector` operates on the principle of capacity, meaning _"The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to reallocate each time an element is inserted, but only when the additional memory is exhausted — cppreference"_. At first glance, I thought I will just double the capacity each time it requires more for explanatory purposes, but I guess it may lead to misinformation, so I just chosen to implement solely based on the length. Even though it contradics the main principle, it doesn't abstruct to grasp the idea behind other memory management. This resulted in some type of misleading nature of some methods, thus I've placed notes, where it does so.
   
5. The `DA` class is declared in `DynamicArray.h` header file and defined in `DynamicArray.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Testing of the class functionalities is conducted within the `main()` function located in the `Main.cpp` file.

6. Whole class declaration:
```cpp
template<class T>
class DA
{
private:
	int _size;
	T* _data;

public:
	// Special Member Functions
	DA();
	DA(int newSize, T newData = T());
	DA(const DA& rhs);
	DA& operator=(const DA& rhs);
	~DA();

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
	void pushBack(const T& newData);
	void insert(int index, const T& newData);
	void remove(int index);
	void resize(int newSize);
	void clear();
};
```

7. Special member functions:
```cpp
// Default constructor
template<class T>
DA<T>::DA() : _size(0), _data(nullptr) {}

// Parameterized constructor, no range check
template<class T>
DA<T>::DA(int newSize, T newData) : _size(size) {
    // Allocate memory for new array
    _data = new T[size];

    // Fill with elements
    for (int i = 0; i < size; ++i) {
        _data[i] = newData;
    }
        
}

// Deep copy constructor
template<class T>
DA<T>::DA(const DA& rhs) : _size(rhs._size) {
    if (rhs._data) {
        // Allocate memory for new array
        _data = new T[_size];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            _data[i] = rhs._data[i];
    }
    else {
        _data = nullptr;
    }
        
}

// Deep copy assignment operator
template<class T>
DA<T>& DA<T>::operator=(const DA& rhs) {
    // Self-assignment guard
    if (this == &rhs)
        return *this;
        
    // Prevent memory leak
    delete[] _data;
    // Set corresponding size
    _size = rhs._size;

    if (rhs._data) {
        // Allocate memory for new array
        _data = new T[_size];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            _data[i] = rhs._data[i];
    }
    else {
        _data = nullptr;
    }
        
    return *this;
}

// Destructor
template<class T>
DA<T>::~DA() { delete[] _data; }
```

8. Element access:
```cpp
// Accesses the element at the specified index, allows modification, no range check
template<class T>
T& DA<T>::operator[](const int index) { return _data[index]; }

// Accesses the element at the specified index, denies modification, no range check
template<class T>
const T& DA<T>::operator[](const int index) const { return _data[index]; }

// Accesses the first element in the container, allows modification, no range check
template<class T>
T& DA<T>::front() { return _data[0]; }

// Accesses the first element in the container, denies modification, no range check
template<class T>
const T& DA<T>::front() const { return _data[0]; }

// Accesses the last element in the container, allows modification, no range check
template<class T>
T& DA<T>::back() { return _data[_size - 1]; }

// Accesses the last element in the container, denies modification, no range check
template<class T>
const T& DA<T>::back() const { return _data[_size - 1]; }
```

9. Capacity methods:
```cpp
// Checks if the container has no elements
template<class T>
bool DA<T>::empty() const { return (_size == 0); }

// Returns the number of elements in the container
template<class T>
int DA<T>::size() const { return _size; }
```

10. Modifiers:
```cpp
// Appends the given element to the end of the container
// Note: without potential memory-reserving adjustments and bounds checking
template<class T>
void DA<T>::pushBack(const T& newData) {
    // Allocate memory for new array, one element more
    T* newArray = new T[_size + 1];

    // Copy elements
    for (int i = 0; i < _size; ++i)
        newArray[i] = _data[i];

    // Insert the new value at the end
    newArray[_size] = newData;

    // Manage memory and pointers
    delete[] _data; // dealloc
    _data = newArray; // point to new
    ++_size; // reflect change on the size

}

// Inserts elements at the specified position, shifting other elements as needed.
// Note: without potential memory-reserving adjustments and bounds checking
template<class T>
void DA<T>::insert(int index, const T& newData) {
    if (index == _size - 1) {
      pushBack(newData);
    }
    else {
        // Allocate memory for new array, one element more
        T* newArray = new T[_size + 1];

        // Copy elements before the position
        for (int before = 0; before < index; ++before)
            newArray[before] = _data[before];

        // Insert the new value at the specified position
        newArray[index] = newData;

        // Copy elements after the position
        for (int after = index; after < _size; ++after)
            newArray[after + 1] = _data[after];

        // Manage memory and pointers
        delete[] _data; // dealloc
        _data = newArray; // point to new
        ++_size; // reflect change on the size
    }
}

// Removes an element at the specified position
// Note: without potential memory-reserving adjustments and bounds checking
template<class T>
void DA<T>::remove(int index) {
    // Case: one element
    if (_size == 1) {
        clear();
        return;
    }

    // Allocate memory for new array, one element less
    T* newArray = new T[_size - 1];

    // Copy before position
    for (int before = 0; before < index; ++before)
        newArray[before] = _data[before];

    // Copy after position
    for (int after = index + 1; after < _size; ++after)
        newArray[after - 1] = _data[after];

    // Manage memory and pointers
    delete[] _data; // dealloc
    _data = newArray; // point to new
    --_size; // reflect change on the size
}

// Changes the size of an array exactly to the given
// Note: without potential memory-reserving adjustments
template<class T>
void DA<T>::resize(int newSize) {
    // Case: already required size
    if (newSize <= _size) {
        return;
    }

    if (newSize > _size) {
        // Allocate memory for new array
        T* newArray = new T[newSize];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            newArray[i] = _data[i];

        // Manage memory and pointers
        delete[] _data; // dealloc
        _data = newArray; // point to new
        _size = newSize; // reflect change on the size
    }
}

// Clears the entire content of the dynamic array, freeing memory.
// Note: without potential memory-reserving adjustments
template<class T>
void DA<T>::clear() {
    delete[] _data; // dealloc
    _data = nullptr; // avoid dangling pointer
    _size = 0; // reflect change on the size
}
```

11. Demonstration:
```cpp
void printArray(const DA<int>& arr) {
	std::cout << "Elements:\t";
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	// Greet
	std::cout << "\tWelcome to the 'Dynamic Array' console application!\n";

	// Create initial array #1
	std::cout << "\nCreating & filling initial array #1...\n";
	DA<int> arr1;
	for (int i = 0; i < 10; i++)
		arr1.pushBack(i);

	// Show array #1
	std::cout << "Is it empty:\t" << arr1.empty() << std::endl;
	printArray(arr1);


	// Modify array #1
	std::cout << "\nChange first ('1') and last ('10') element to '0'...\n";
	arr1[0] = arr1[arr1.size() - 1] = 0;
	printArray(arr1);

	// Deep copy functionality
	std::cout << "\nCreate an array copies and compare...\n";
	DA<int> arr2(arr1);
	DA<int> arr3 = arr1;
	printArray(arr1);
	printArray(arr2);
	printArray(arr3);

	// Remove functionality
	std::cout << "\nShorten an array #2 to 7 elements, and #3 to 3 elements...\n";
	for (int i = arr2.size() - 1; i >= 7; --i)
		arr2.remove(i);
	for (int i = arr3.size() - 1; i >= 3; --i)
		arr3.remove(i);
	printArray(arr1);
	printArray(arr2);
	printArray(arr3);

	// Clear
	std::cout << "\nClear array #2 and #3...\n";
	arr2.clear();
	arr3.clear();
	printArray(arr1);
	printArray(arr2);
	printArray(arr3);
	std::cout << "Are they empty: ";
	std::cout << arr1.empty();
	std::cout << arr2.empty();
	std::cout << arr3.empty();
	std::cout << std::endl;

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}
```

<p align="center"><img src="./img/demoDA.png"/></p>



# &#128202; Analysis

**Advantages:**
- **Efficient Random Acess** — arrays facilitate efficient access to the elements within the collection. Regardless of the array's length, accessing elements has a constant time complexity of $(O(1))$.
- **Efficiency Memory Utilization** — as arrays store data in contiguous memory locations, preventing additional memory wastage. Also, ability for the allocation of memory in a single block, reduces memory fragmentation.
- **Convenient Multi-Dimensional Representations** — arrays provide a straightforward and natural way to represent multi-dimensional data structures, especially some type of grids or matries.

---

**Disadvantages:**
- **Allocated Memory is Static** — in scenarios where the size needs adjustments or insertion leads to the shift of other elements, then resourceful operation of creating a new array and copying data arises, e.g. insertion and deletion takes $O(n)$ time.
- **Enourmous Single Block** — allocating a large array can be problematic, especially in systems with limited memory, which potentially can cause a crash.
- **Wasted Space** — if an array is not fully populated, there may be wasted space in the allocated memory. This can be a concern in memory-constrained environments.
- **Out-of-Bound Access** — if an index outside the valid range is used, it can lead to unpredictable behavior or even program crashes.



# &#128221; Application

**Some of the Most Well-Known Use Cases:**
- **Data Storage** — arrays are fundamental for storing collections of data, such as lists of numbers, strings, or objects. They provide a structured and efficient way to organize and access this information.

- **Algorithms and Data Structures** — many algorithms and data structures rely on arrays. Sorting algorithms, searching algorithms, and various data structures like stacks, queues, and hash tables often use arrays as their underlying structure.

- **Image and Signal Processing** — arrays are commonly used to represent images or signals in applications like computer vision and audio processing. The pixel values of an image or the samples of a signal can be stored in arrays.

- **Text Processing** — arrays are extensively used in handling strings and characters. Text processing tasks, like searching, parsing, or manipulating strings, often involve the use of arrays.

- **Matrices and Linear Algebra** — matrices, a specialized form of 2D arrays, are fundamental in linear algebra. They are extensively used in scientific computing, graphics, physics simulations, and machine learning.

- **Database Management** — arrays play a role in managing and processing data within databases. Tabular data, such as rows and columns in a database table, can be represented using arrays.

- **Game Development** — arrays are crucial in game development for managing various game elements, such as characters, items, or terrain data. They provide a structured way to organize and manipulate in-game entities.

- **Embedded Systems** — in embedded systems programming, arrays are often used to manage sensor data, control outputs, or store configuration information due to their simplicity and efficiency.

---

**Common Practical Problems:**
- Reverse the array.
- Find the Kth largest and Kth smallest number in an array.
- Find the occurrence of an integer in the array.
- Subarray with given Sum.
- Find duplicates in an array.
- Find GCD of all elements in an array.
- Finding LCM of an array of numbers.
- Find the missing integer.
- Find the factorial of a large number.
- Minimum number of jumps to reach the end.
- Find whether an array is a subset of another array.
- Maximum Index.
- Coin Change Problem.
- Longest Alternating subsequence.
- Stock buy and sell Problem.
- Move negative elements to front of array.



# &#x23F3; Historical Notes
The concept of organizing data into ordered sequences has evolved over time and there is no single individual behind array. Even though, the early assembly languages and machine languages also had primitive constructs for managing memory, but they lacked the high-level abstraction and expressiveness that arrays provide in modern programming languages. One notable early contribution to this concept, in the field of programming, comes from the **Fortran** programming language, which in the 1957 provided array notation and syntax for working with vectors and matrices efficiently.


# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contact Information
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contact-information).



# &#128591; Credits
&#128218; **Books:**
- **"Grokking Algorithms"** — by Aditya Bhargava
  - Section 2.1: How memory works
  - Section 2.2: Arrays and linked lists
- **"Algorithms in C++, Parts 1-4"** — by Robert Sedgewick
  - Section 3.2: Arrays
- **"Data Structures and Algorithm Analysis in C++""** — by Mark A. Weiss
  - Section 3.1: Abstract Data Types
  - Section 3.3: `vector` and `list` in the STL
  - Section 3.4: implementation of `vector`
  
&#127891;**Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/?LSNPUBID=JVFxdTr9V80&ranEAID%3B=JVFxdTr9V80&ranMID%3B=39197&ranSiteID%3B=JVFxdTr9V80-_3GVcwGZFWT4XsSuZYrgGA&utm_source=adwords&utm_medium=udemyads&utm_campaign=DSA_Catchall_la.EN_cc.ROW&utm_content=deal4584&utm_term=_._ag_88010211481_._ad_535397282064_._kw__._de_c_._dm__._pl__._ti_dsa-406594358574_._li_9061020_._pd__._&matchtype=&gad_source=1&gclid=CjwKCAiA3aeqBhBzEiwAxFiOBgRFL7RkV-WJI9tPKml75et478Ai5oJigSKAivJ2txZ9Jhi0mhsTdxoC_foQAvD_BwE) on Udemy
   - Section 6: Arrays Representations
   - Section 7: Array ADT
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) from Coursera
   - Course 2.1: Linear Structures
  
&#127760;**Web-Resources:**
- [Array (data structure)](https://en.wikipedia.org/wiki/Array_(data_structure)#:~:text=In%20computer%20science%2C%20an%20array,one%20array%20index%20or%20key.) (Wikipedia)
- [Introduction to Arrays](https://www.geeksforgeeks.org/introduction-to-arrays-data-structure-and-algorithm-tutorials/)
- [Pointer Arithmetic](https://hackingcpp.com/cpp/lang/pointer_arithmetic.html)
- [Array (ADT)](https://brilliant.org/wiki/arrays-adt/#:~:text=The%20array%20is%20a%20basic,types%20like%20instances%20of%20classes.)
- [Difference between Static Arrays and Dynamic Arrays](https://www.geeksforgeeks.org/difference-between-static-arrays-and-dynamic-arrays/)
- [std::array](https://en.cppreference.com/w/cpp/container/array)
- [std::vector](https://en.cppreference.com/w/cpp/container/vector)
- [Applications, Advantages and Disadvantages of Array](https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-array-data-structure/)
- [What are the Advantages and Disadvantages of Arrays?](https://www.prepbytes.com/blog/arrays/advantages-and-disadvantages-of-arrays/)
- [List of 50+ Array Coding Interview Problems](https://iq.opengenus.org/list-of-array-problems/)
- [Top 50 Array Coding Problems for Interviews](https://www.geeksforgeeks.org/top-50-array-coding-problems-for-interviews/)

# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)