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

An array is a fundamental concept in computer programming. Arrays are widely used not only because they provide a natural, structured way to organize and access data, they also serve as a lower-level mechanism for memory management. The concept of an array encompasses both a basic data structure, as a part of programming language, and an abstract data structure (ADT), which involves a conceptual representation that defines operations without specifying the implementation details. As a part of this repository, this subsection explores the ADT through the illustration of an arrays, because it not only simplifies comprehension, but also establishes a solid foundation for approaching more intricate data structures.


<p align="center"><img src="./img/memoryCells.png"/></p>

---

**Array** — is a linear data structure that collects elements of the same data type and stores them in contiguous and adjacent memory locations. It introduces the following essential terms:
- **Element** — each individual data value contained within the array. These data values can be anything from promitive types such as integers to more complex types like instances of classes. Since elements don't have their unique names, the only way to access them is through their respective indices.
- **Index** — integer value which specifies the element's position within the array, usually starting with the first as $0$ and concluding with the last as $length-1$.
- **Length (Size)** — is a number of elements contained in the array.
- **Capacity** — is the maximum number of possilbe elements for which there is currently allocated memory within array. This term is primarily associated with dynamic arrays because they aim to minimize frequent resize operations by reserving additional space for potential future elements.

<p align="center"><img src="./img/arrayIndices.png"/></p>

---

In C++, name of an array generates a pointer to the first element of the array (index 0), leading to one of the most prominent features of arrays, among various others — the combination of address arithmetic and array indexing.

<p align="center"><img src="./img/addressArithmetic.png"/></p>

**Address (Pointer) Arithmetic** — is a concept of manipulating memory addresses using arithmetic operations, which allows for efficient navigation through data structure.

```cpp
int value = 5;
int *ptr = &value; // points onto variable of type 'int'                         >>>   002CF9A4
cout << ptr + 1;   // point onto next value of int (+4 bytes)                          002CF9A8
cout << ptr - 1;   // point onto prev value of int (-4 bytes)                          002CF9A0
```

**Array Indexing** — process of accessing elements within an array, typically achieved internally through address arithmetic.
```cpp
int arr[5] = {7, 8, 2}; // simple static array                value:    7     8    2
cout << array[1];   //  this                                  index:    0     1    2
cout << *(array+1); //  equals to this                   expression: array  a+1  a+2
```

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


# &#x1F4BB; Implementation 
Discussing ADT, it's evident that well-established and widely recognized implementations already exist for both static and dynamic arrays. In the context of C++, `std::array` is a representative of static arrays, and `std::vector` stands as the counterpart for dynamic arrays. It's commonly recommended to rely on these proven implementations rather than reinventing the wheel. However, within the scope of this subsection, we'll take a closer look at simplified versions of these arrays. This exploration is aimed at gaining a deeper understanding of the fundamental concepts that underlie them.However, within the scope of this subsection, we will closely examine simplified versions of these arrays. This exploration with simplification is aimed at gaining a deeper understanding of the fundamental concepts that underlie them.



## 🧍‍♂️ Static Array

**Detailed Overview**:
1. In order to prioritize simplicity and highlight data structure itself, `int` is picked as sole data type.
2. As mentioned earlier, a crucial aspect of arrays lies in the synergy between array indexing and address arithmetic. The illustration of a static array in C++, exemplified by `std::array`, achieves this through the utilization of the entire iterator class as one of its components. In this specific implementation, the iterator related functionality was omitted to streamline the focus on learning ADT basics, e.g. even methods like `int* begin();`, `const int* cbegin() const;`, or `int* rbegin();` are absent.

<p align="center"><img src="./img/stdArrIt.png"/></p>

3. Additionally, various types of bounds checking were omitted due to the situational nature of error resolution. As an instance of this omission, one of the ways of element access, known as method `at()` in `std::array` was skipped.

<p align="center"><img src="./img/stdArrAt.png"/></p>

4. The ADT is implemented within the class named `StaticArr`, and this class is divided into two distinct files - header and source. This is done because of encapsulation, modularity and compilation efficiency.
5. The declaration of the class is presented in `StaticArr.h`:

```cpp
class StaticArr
{
private:
	int mLength;
	int* mArr;

public:
	// Special Member Functions
	explicit StaticArr();
	explicit StaticArr(int length); 
	explicit StaticArr(const StaticArr& src) = default;
	StaticArr& operator=(const StaticArr& rhs) = default;
	~StaticArr();


	// Element Access
	int& operator[](const int index);
	int front();
	int back();


	// Capacity
	bool isEmpty() const;
	int size() const;


	// Operations
	void fill(const int val);
};
```

6. While the definition is in `StaticArr.cpp`:

```cpp
// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
StaticArr::StaticArr() : mLength(0), mArr(nullptr) {}

// Parameterized constructor without bounds checking
StaticArr::StaticArr(int length) : mLength(length)
{
	if (length > 0) { mArr = new int[length]; }
	else { mArr = nullptr; }
}

// Destructor
StaticArr::~StaticArr() { delete[] mArr; }


// --------------
// Element Access
// --------------

// Access the element at the specified index without bounds checking
int& StaticArr::operator[](const int index) { return mArr[index]; }

// Access the first element of the container without bounds checking
int StaticArr::front() { return mArr[0]; }

// Access the last element of the container without bounds checking
int StaticArr::back() { return mArr[mLength - 1]; }



// --------
// Capacity
// --------

// Check if the container is empty
bool StaticArr::isEmpty() const { return (mLength == 0); }

// Get the size of the container
int StaticArr::size() const { return (isEmpty() ? 0 : mLength); }


// ----------
// Operations
// ----------

// Fill the container with specified value
void StaticArr::fill(const int val)
{
	for (int i = 0; i < mLength; ++i)
		mArr[i] = val;
}
```

7. A demonstration of the array's capabilities is showcased in the `main()` function, situated within the `main.cpp` file.
```cpp
int main()
{
	// Greetings
	std::cout << "Welcome to the 'Static Array' console application!\n\n";

	// Create the array with 10 uninitialized elements
	StaticArr myArr(10);

	// Fill the array with numbers (0-10)
	for (int i = 0; i < 10; i++)
		myArr[i] = i + 1;

	// Display the array
	std::cout << "Array: ";
	for (int i = 0; i < myArr.size(); i++)
		std::cout << myArr[i] << " ";
	std::cout << std::endl;

	// Showcase of the capacity
	if (myArr.isEmpty()) { std::cout << "The array is empty. It has " << myArr.size() << " elements.\n"; }
	else { std::cout << "The array is not empty. It has " << myArr.size() << " elements.\n"; }

	// Showcase of the element access
	std::cout << "First elements is: " << myArr.front() << std::endl;
	std::cout << "Second elements is: " << myArr[1] << std::endl;
	std::cout << "Last elements is: " << myArr.back() << std::endl;

	// Showcase of the operations
	myArr.fill(1);
	std::cout << "Filling the array with 1: ";
	for (int i = 0; i < myArr.size(); i++)
		std::cout << myArr[i] << " ";
	std::cout << std::endl;

	// Exiting
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}
```
<p align="center"><img src="./img/staticArr.png"/></p>

## 🚶‍♂️ Dynamic Array

**Detailed Overview**:
1. In order to prioritize simplicity and highlight data structure itself, `int` is picked as sole data type.
2. As mentioned earlier, a crucial aspect of arrays lies in the synergy between array indexing and address arithmetic. The illustration of a dynamicarray in C++, exemplified by `std::vector`, achieves this through the utilization of the entire iterator classes as one of its components. In this specific implementation, the iterator related functionality was omitted to streamline the focus on learning ADT basics, e.g. even methods like `int* begin();`, `const int* cbegin() const;`, or `int* rbegin();` are absent.

<p align="center"><img src="./img/stdVecIt.png"/></p>

3. Additionally, various types of bounds checking were omitted due to the situational nature of error resolution. As an instance of this omission, one of the ways of element access, known as method `at()` in `std::vector` was skipped.

<p align="center"><img src="./img/stdVecAt.png"/></p>

4. Key difference between static and dynamic ADT lies in the implementation of the memory management. The well-known `std::vector` operates on the principle of capacity, meaning _"The storage of the vector is handled automatically, being expanded as needed. Vectors usually occupy more space than static arrays, because more memory is allocated to handle future growth. This way a vector does not need to reallocate each time an element is inserted, but only when the additional memory is exhausted — cppreference"_. At first glance, I thought I will just double the capacity each time it requires more for explanatory purposes, but I guess it may lead to misinformation, so I just chosen to implement solely based on the length. Even though it contradics the main principle, it doesn't abstruct to grasp the idea behind other memory management. This resulted in some type of misleading nature of some methods, thus I've placed notes, where it does so.

5. The ADT is implemented within the class named `DynArr`, and this class is divided into two distinct files - header and source. This is done because of encapsulation, modularity and compilation efficiency.
6. The declaration of the class is presented in `DynamicArray.h`:

```cpp
class DynArr
{
private:
	int* _data;
	int _size;

public:
	// Special Member Functions
	explicit DynArr();
	explicit DynArr(int size, int defVal = 0);
	explicit DynArr(const DynArr& src);
	DynArr& operator=(const DynArr& rhs);
	~DynArr();

	// Element Access
	int& operator[](const int index);
	int front();
	int back();

	// Capacity
	bool empty() const;
	int size() const;
	void resize(int newSize);

	// Operations
	void clear();
	void remove(int pos);
	void insert(int pos, int val);
};
```

6. While the definition is in `DynamicArray.cpp`:

```cpp
// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
DynArr::DynArr() : _data(nullptr), _size(0) {}

// Parameterized constructor
// Note: without bounds checking
DynArr::DynArr(int size, int defVal) : _size(size)
{
    _data = new int[size];
    for (int i = 0; i < size; ++i)
        _data[i] = defVal;
}

// Copy constructor
DynArr::DynArr(const DynArr& src) : _size(src._size)
{
    // Shallow Copy
    _size = src._size;

    // Deep Copy if has data
    if (src._data)
    {
        // Allocate new array
        _data = new int[_size];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            _data[i] = src._data[i];
    }
    else
        _data = nullptr;
}

// Copy Assignment Operator
DynArr& DynArr::operator=(const DynArr& rhs)
{
    // Self assignment check
    if (this == &rhs)
        return *this;

    // Prevent memory leak
    delete[] _data;

    // Shallow copy
    _size = rhs._size;

    // Deep Copy is has data
    if (rhs._data)
    {
        // Allocate new array
        _data = new int[_size];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            _data[i] = rhs._data[i];
    }
    else
        _data = nullptr;
        
    return *this;
}

// Destructor
DynArr::~DynArr() { delete[] _data; }


// --------------
// Element Access
// --------------

// Access the element at the specified index without bounds checking
int& DynArr::operator[](const int index) { return _data[index]; }

// Access the first element of the container without bounds checking
int DynArr::front() { return _data[0]; }

// Access the last element of the container without bounds checking
int DynArr::back() { return _data[_size - 1]; }



// --------
// Capacity
// --------

// Check if the container has elements
bool DynArr::empty() const { return (_size == 0); }

// Get the size of the container
int DynArr::size() const { return _size; }


// Changes the size of an array exactly to the given
// Note: without potential memory-reserving adjustments
void DynArr::resize(int newSize)
{
    // Either already required or leads to deleting
    if (newSize <= _size)
        return;
     
    // Greater, every element preserves
    if (newSize > _size)
    {
        // Allocate new array
        int* newData = new int[newSize];

        // Copy the elements
        for (int i = 0; i < _size; ++i)
            newData[i] = _data[i];

        // Manage memory
        delete[] _data;
        _data = newData;
        _size = newSize;
    }
}


// ----------
// Operations
// ----------

// Clears the entire content of the dynamic array, freeing memory.
// Note: without potential memory-reserving adjustments
void DynArr::clear()
{
    delete[] _data;
    _data = nullptr;
    _size = 0;
}


// Removes an element at the specified position
// Note: without potential memory-reserving adjustments and bounds checking
void DynArr::remove(int pos)
{
    // Sole element
    if (_size == 1)
    {
        clear();
        return;
    }

    // New array, one element less
    int* data = new int[_size - 1];

    // Copy until position
    for (int before = 0; before < pos; ++before)
        data[before] = _data[before];

    // Copy after position
    for (int after = pos + 1; after < _size; ++after)
        data[after - 1] = _data[after];

    // Manage memory
    delete[] _data;
    _data = data;
    --_size;
}

// Inserts a new element at the specified position, shifting other elements as needed.
// Note: without potential memory-reserving adjustments and bounds checking
void DynArr::insert(int pos, int val)
{
    // New array, one element more
    int* newData = new int[_size + 1];

    // Copy elements before the position
    for (int before = 0; before < pos; ++before)
        newData[before] = _data[before];

    // Insert the new value at the specified position
    newData[pos] = val;

    // Copy elements after the position
    for (int after = pos; after < _size; ++after)
        newData[after + 1] = _data[after];

    // Manage memory
    delete[] _data;
    _data = newData;
    ++_size;
}
```

7. A demonstration of the array's capabilities is showcased in the `main()` function, situated within the `main.cpp` file.
```cpp
int main()
{
	// Greetings
	std::cout << "Welcome to the 'Dynamic Array' console application!\n\n";

	// Showcase default constructor
	DynArr arr_1;

	// Fill the array with numbers (0-10)
	for (int i = 0; i < 10; i++)
		arr_1.insert(i, i+1);

	// Display the array
	std::cout << "Array #1: ";
	for (int i = 0; i < arr_1.size(); i++)
		std::cout << arr_1[i] << " ";
	std::cout << std::endl;

	// Showcase of the element access
	std::cout << "First elements is: " << arr_1.front() << std::endl;
	std::cout << "Second elements is: " << arr_1[1] << std::endl;
	std::cout << "Last elements is: " << arr_1.back() << std::endl;
	std::cout << std::endl;

	// Showcase of the capacity
	if (!arr_1.empty())
	{
		std::cout << "As long as array is not empty (it has " << arr_1.size() << " elements).\n";
		arr_1.resize(15);
		std::cout << "We can resize it to " << arr_1.size() << " elements.\n\n";
	}

	std::cout << "Additionally, we can copy initial array and shorten them:\n";
	// Showcase copy constructor
	DynArr arr_2(arr_1);

	// Shorten an array #2 to 7 elements
	for (int i = arr_2.size() - 1; i >= 7; --i)
		arr_2.remove(i);

	// Display the array #2
	std::cout << "Array #2: ";
	for (int i = 0; i < arr_2.size(); i++)
		std::cout << arr_2[i] << " ";
	std::cout << std::endl;

	// Showcase copy assignment
	DynArr arr_3;
	arr_3 = arr_1;

	// Shorten an array #3 to 3 elements
	for (int i = arr_3.size() - 1; i >= 3; --i)
		arr_3.remove(i);

	// Display the array
	std::cout << "Array #3: ";
	for (int i = 0; i < arr_3.size(); i++)
		std::cout << arr_3[i] << " ";
	std::cout << std::endl;


	// Exiting
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.clear(); // ensure that stream is in a good state
	std::cin.ignore(32767, '\n'); // clear from any remaining chars
	std::cin.get();
	return 0;
}
```
<p align="center"><img src="./img/dynamicArr.png"/></p>


# &#128202; Analysis
Currently in Progress...


# &#128221; Application

Types of Operations:
- Traversal — traverse through the elements of an array.
- Insertion — inserting a new element in an array.
- Deletion — deleting element from the array.
- Searching — search for an element in the array.
- Sorting — maintaining the order of elements in the array.

---





# &#x23F3; Historical Notes
Currently in Progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



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
  
&#127891;**Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/?LSNPUBID=JVFxdTr9V80&ranEAID%3B=JVFxdTr9V80&ranMID%3B=39197&ranSiteID%3B=JVFxdTr9V80-_3GVcwGZFWT4XsSuZYrgGA&utm_source=adwords&utm_medium=udemyads&utm_campaign=DSA_Catchall_la.EN_cc.ROW&utm_content=deal4584&utm_term=_._ag_88010211481_._ad_535397282064_._kw__._de_c_._dm__._pl__._ti_dsa-406594358574_._li_9061020_._pd__._&matchtype=&gad_source=1&gclid=CjwKCAiA3aeqBhBzEiwAxFiOBgRFL7RkV-WJI9tPKml75et478Ai5oJigSKAivJ2txZ9Jhi0mhsTdxoC_foQAvD_BwE) on Udemy
   - Section 6: Arrays Representations
   - Section 7: Array ADT
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) from Coursera
   - Course 2: Ordered Data Structures
  
&#127760;**Web-Resources:**
- [Introduction to Arrays](https://www.geeksforgeeks.org/introduction-to-arrays-data-structure-and-algorithm-tutorials/)
- [Pointer Arithmetic](https://hackingcpp.com/cpp/lang/pointer_arithmetic.html)
- [Array (ADT)](https://brilliant.org/wiki/arrays-adt/#:~:text=The%20array%20is%20a%20basic,types%20like%20instances%20of%20classes.)
- [Difference between Static Arrays and Dynamic Arrays](https://www.geeksforgeeks.org/difference-between-static-arrays-and-dynamic-arrays/)
- [std::array](https://en.cppreference.com/w/cpp/container/array)
- [std::vector](https://en.cppreference.com/w/cpp/container/vector)

# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)