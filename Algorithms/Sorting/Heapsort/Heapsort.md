# &#128209; Table of Contents
- [💡 Overview](#-overview)
- [💻 Implementation](#-implementation)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
The **Heapsort** stands out as one of the most well-known and efficient sorting techniques. The algorithm is named for its use of the heap data structure property, which implies that the keys of parent nodes are either greater than or equal to those of their children (in a max heap) or less than or equal to those of their children (in a min heap). This subsection explores the idea of heapsort not only to enhance comprehension of its concepts, but also to establish a solid foundation for more complex algorithmic designs and problem-solving strategies.
<p align="center"><img src="./img/Heapsort.png"/></p>

---
The **Heapsort** converts the original data into a heap data structure, divides its input into a sorted and an unsorted region, and iteratively shrinks the unsorted region by extracting the largest element (the root) from the heap and moving it to the sorted region.

**Algorithm Steps:**
1. Convert the input data into a max heap, so that the largest value is at the root.
2. Swap the root with the last element of the unsorted portion, thus moving the root to the sorted part.
3. Remove the swapped root from the heap.
4. Perform a heapify operation to ensure that the remaining elements maintain the heap property.
5. Repeat this process until there are no elements remaining in the unsorted part.



# &#x1F4BB; Implementation
The program initializes an array of specified integers, performs ascending order sorting using the heapsort algorithm, and finally displays the result.
<p align="center"><img src="./img/Demonstration.png"/></p>

To prioritize simplicity and emphasize algorithm itself, several design decisions were made:
- Utilizing an integer array as a collection.
- Exclusively implementing sorting in ascending order.
- Omitting certain optimizations to the algorithm.

---
Sorting algorithm implemented within the `heapsort()` function with a few helper ones `swap()`, `buildMaxHeap()` and `heapify`, which are declared `Heapsort.h` header file and defined in `Heapsort.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Examination of sorting technique is conducted within the `main()` function located in the `Main.cpp` file.

**Complete Implementation:**
```cpp
void heapify(int arr[], int size, int i) {
	int largest = i;      
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < size && arr[left] > arr[largest]) {
  		largest = left;
	}   

	// If right child is larger than largest
	if (right < size && arr[right] > arr[largest]) {
  		largest = right;
	}
        
	// If largest is not root
	if (largest != i) {
	  	swap(arr[i], arr[largest]);
	  	heapify(arr, size, largest);
	}
}

void buildMaxHeap(int arr[], int size) {
	int startIdx = (size / 2) - 1; // index of the last non-leaf node

	// Heapify via reverse level order traversal
	for (int i = startIdx; i >= 0; i--) {
	  	heapify(arr, size, i);
	}
}

void heapsort(int arr[], int size) {
  	buildMaxHeap(arr, size);

  	for (int i = size - 1; i > 0; i--) {
  	    swap(arr[0], arr[i]);
  	    heapify(arr, i, 0);
  	}
}
```

---
**Detailed Walkthrough:**  
1. Start by building a max heap from the input array. This process takes place in a separate from `heapsort()` function and ensures that the largest element is at the root of the heap.
```cpp
	buildMaxHeap(arr, size);
```
2. The `buildMaxheap()` function starts by calculating the index of the last non-leaf node in the heap. This is done to begin heapifying from the bottom up.
```cpp
	int startIdx = (size / 2) - 1; // index of the last non-leaf node
```
3. Perform a reverse level order traversal from the last non-leaf node to the root, calling the `heapify()` function on each node. This ensures that the entire array satisfies the max heap property.
```cpp
	// Heapify via reverse level order traversal
	for (int i = startIdx; i >= 0; i--) {
	  	heapify(arr, size, i);
	}
```
4. In the `heapify()` function, initialize the largest variable as the current node index. This variable will be used to track the largest value among the node and its children. Also calculate the indices of the left and right children of the current node via respective formulas (i.e. total number of positions occupied by nodes and their children up to $i$ is $2*i$, left child would be the very next position ($+1$), and right next to the left ($+1$ once more))
```cpp
	int largest = i;      
	int left = 2 * i + 1;
	int right = 2 * i + 2;
```
5. Then simply Compare the value of the left child with the value of the current node. If the left child's value is greater, update largest to the index of the left child. Do the same for right child.
```cpp
	// If left child is larger than root
	if (left < size && arr[left] > arr[largest]) {
		largest = left;
	}   

	// If right child is larger than largest
	if (right < size && arr[right] > arr[largest]) {
		largest = right;
	}
```
6. If the largest value is not the current node, swap the values of the current node and the largest node. Then, recursively call heapify on the affected subtree to ensure it maintains the max heap property.
```cpp
	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, size, largest);
	}
```
7. Once the max heap is built, proceed to sort the array. This is done by repeatedly extracting the largest element (the root of the heap) and moving it to the end of the array.
```cpp
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
```



# &#128202; Analysis
> Note: Some of the aspects described here are subject to implementation. Many sources may exploit this to their advantage, resulting in varying information for what appears to be the same concept. This can easily lead to confusion, so I highly encourage you to examine your specific case, filter through several sources, and adhere to the one that appears most accurate. I would like to discuss this topic with anyone who has related questions.

---
- **Comparison Approach:**
  - **Comparison-Based** — algorithm operates by comparing elements pairwise to arrange them in order.

- **Time Complexity:**
  - **All Cases** $O(n \log n)$ — occurs because the heapify process always takes $O(\log n)$ time, and this process is applied $n$ times.

- **Space Complexity:**
  - **Array Implementation** — algorithm requires a constant amount of additional space $O(1)$ as it sorts the array in place.

- **Stability:**
  - **Unstable** — algorithm can swap two equal elements, thus altering their relative order. This happens because of the heapify process, which does not guarantee that equal elements will maintain their relative positions.

- **Adaptability:**
  - **Non-Adaptive** — algorithm does not inherently adapt its strategy to different input distributions, i.e., it processes data through the same path of steps, regardless of their values.

- **Directness:**
  - **Direct** — algorithm sorts elements by directly manipulating themselves.

- **Storage:**
  - **Internal** — algorithm typically implemented to be an internal sorting.



# &#128221; Application
**Some of the Most Well-Known Use Cases:**
- **Resource-Constrained Environments** — heapsort is used in scenarios where efficient sorting with minimal memory consumption is required. Unlike mergesort, which requires additional memory, heapsort operates in-place and still provides excellent performance; e.g. embedded systems, operating systems.
- **Guaranteed Performance** — heapsort is used when guaranteed performance is more critical than speed. While generally slower than quicksort, heapsort avoids the risk of excessive recursion depth, which can be problematic for quicksort in certain cases; e.g. introsort.



# &#x1F559; Origins
Heapsort was invented by British computer scientist **John William Joseph (Bill) Williams** in **1964**. Williams introduced Heapsort in a paper titled «Algorithm 232: Heapsort», published in the Communications of the ACM (Association for Computing Machinery) journal. He developed the algorithm to leverage the binary heap data structure, which he also introduced. The key idea was to efficiently sort data by first constructing a max heap from the input array and then repeatedly extracting the maximum element to achieve a sorted array, much like selection sort. Heapsort remains an important algorithm in computer science education and specific practical contexts, despite being less commonly used than quicksort and mergesort for general-purpose sorting.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 6: Heapsort
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 9.4: Heapsort
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 7.5: Quicksort
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 4.3: Heapsort: Fast Sorting via Data Structures
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 5.2.3: Sorting by Selection

---  
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 19: Heap

---  
&#127760; **Web-Resources:**  
- [Heapsort](https://en.wikipedia.org/wiki/Heapsort) (Wikipedia)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)