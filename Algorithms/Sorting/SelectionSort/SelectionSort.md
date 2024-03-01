# &#128209; Table of Contents
- [💡 What is the Selection Sort](#-what-is-the-selection-sort)
- [💻 Implementation](#-implementation)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is the Selection Sort
The **Selection Sort** stands out as one of the simplest and earliest known sorting technique, renowned for its straightforward implementation. The algorithm is named for its method of selecting the smallest (or largest) elements from a collection. Knowledge and understanding of it, lays the foundation for tackling more complex sorting methods and problem-solving strategies.
<p align="center"><img src="./img/selectionSort.png"/></p>

---

**Selection Sort** treats a collection as two parts: sorted and unsorted. The algorithm iterates over the unsorted elements, selecting the lowest (or highest) value and exchanging it with the element at the beginning of the unsorted part, thus forming the sorted portion; much like the intuitive process of arranging books on a shelf from shortest to tallest. It consists of the following steps:
1. Assume that all elements belong to the unsorted part, thus start with the first one in it.
2. Select the element with the smallest (or highest) value.
3. Exchange it with the first element of the unsorted part; thus form a sorted part.
4. Proceed to the next unsorted element.
5. Repeat this process until there are no elements remaining in the unsorted part.



# &#x1F4BB; Implementation
The program initializes an array of specified integers, performs ascending order sorting using the selection sort algorithm, and finally displays the result.
<p align="center"><img src="./img/demonstration.png"/></p>

To prioritize simplicity and emphasize algorithm itself, several design decisions were made:
- Utilizing an integer array as a fundamental data structure.
- Exclusively implementing sorting in ascending order.
- Omitting certain optimizations from the algorithm.

---

Sorting algorithm implemented within the function `selectionSort()`, which is declared in `SelectionSort.h` header file and defined in `SelectionSort.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Examination of sorting technique is conducted within the `main()` function located in the `Main.cpp` file.

**The complete implementation of a sorting function:**
```cpp
void selectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {

		int min = i;
		for (int j = i + 1; j < size; j++) {
			// Descending: arr[j] > arr[min]
			if (arr[j] < arr[min]) {
				min = j;
			}
		}

		// Can be optimized via swap
		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
```

---

**The Detailed Algorithm Overview:**
1. Iterate over the unsorted elements, excluding the last one `size - 1`, as it is going to be at correct position, naturally after all the previous iterations.
```cpp
	for (int i = 0; i < size - 1; i++) {
```

2. Select the index of first element from the unsorted part as the minimum, because there are no other known elements at this stage.
```cpp
	int min = i;
```

3. Iterate over the remaining unsorted elements to determine if there is a lower value, by comparing value of current minimum element with the rest of remaining unsorted elements. By starting at `j = i + 1`, we ensure that we don't compare the already previously selected element with itself.
```cpp
	for (int j = i + 1; j < size; j++) {
		// Descending: arr[j] > arr[min]
		if (arr[j] < arr[min]) {
			min = j;
		}
	}
```

4. Finally, we swap the selected minimum element with the first element from the unsorted part if they are different. While this check provides more 'adaptive' behavior, the overall adaptability of the algorithm doesn't change, because the number of comparisons, which mostly contribute to the time complexity, stays the same.
```cpp
	// Can be optimized via swap
	if (min != i) {
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
```



# &#128202; Analysis
- **Comparison Approach:** 
  - **Comparison-Based** — operates by comparing elements pairwise to arrange them in order.

- **Time Complexity:**
     - Worst Case: $O(n^2)$ — data is in reverse sorted order (or almost); algorithm traverses over elements and compares each element with min.
     - Average Case: $O(n^2)$ — data is randomly shuffled; algorithm traverses over elements and compares each element with min.
     - Best Case: $O(n^2)$ — data is already sorted (or almost); algorithm traverses over elements and compares each element with min.

- **Auxiliary Space Complexity:** 
  - $O(1)$ — no additional space is required beyond the input collection.

- **Stability:** 
  - **Unstable** — doesn't guarantee the preservation of the relative order of equal elements, because the algorithm doesn't consider the original positions of equal elements when performing swaps.

- **Adaptabillity:** 
  - **Non-adaptive** — always performs the same sequence of comparisons regardless of the characteristics of the input data, although number of swaps is adaptive.



# &#128221; Application
Selection Sort's utility is limited in modern software development contexts due to its inefficiency. Even for niche applications, there are better alternatives readily available, making Bubble Sort largely obsolete. Its primary relevance lies solely in educational purpose.




# &#x23F3; Historical Notes
The idea of Selection Sort can be observed in many real life activities due to its simplicity, such as arranging playing cards in a hand, sorting stones by size, or organizing items in a list. These and many other manual sortings involve repeatedly selecting the smallest/highest elements and moving to the start/end. In terms of computer science, Selection Sort was one of the earliest sorting algorithms to be implemented in early computer programs. Its origin cannot be attributed to a single individual, rather it reflects the collective ingenuity of humanity.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contact Information
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contact-information).



# &#128591; Credits
&#128218; **Books:**
- **"Grokking Algorithms"** — by Aditya Bhargava
  - Section 2: Selection Sort
- **"Algorithms in C++, Parts 1-4 (Ed. 3)"** — by Robert Sedgewick
  - Section 6.2: Selection Sort
- **"The Art of Computer Programming" (Vol. 3, Ed. 2)** — by Donald Ervin Knuth
  - Section 5.2.3: Sorting by Selection

&#127891;**Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 20: Sorting Techniques
  
&#127760;**Web-Resources:**  
- [Selection Sort](https://en.wikipedia.org/wiki/Selection_sort) (Wikipedia)
- [How does Selection Sort Algorithm work?](https://www.geeksforgeeks.org/selection-sort/)
- [Selection Sort Algorithm](https://www.tutorialspoint.com/data_structures_algorithms/selection_sort_algorithm.htm)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)