# &#128209; Table of Contents
- [💡 What is the Bubble Sort](#-what-is-the-bubble-sort)
- [💻 Implementation](#-implementation)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is the Bubble Sort
The **Bubble Sort** stands out as one of the simplest and earliest known sorting technique, renowned for its straightforward implementation. The algorithm is named for the way the larger elements "bubble" up (move) to the top of the list. Knowledge and understanding of it, lays the foundation for tackling more complex sorting methods and problem-solving strategies.
<p align="center"><img src="./img/bubbleSort.png"/></p>

---
**Bubble Sort** iterates over a collection, comparing adjacent elements and swapping them if they are in the wrong order. This way, in each pass of the algorithm, the largest unsorted element move to its correct position at the end of the collection, much like bubbles gradually rising in water. It consists of the following steps:
1. Start at the beginning of the collection.
2. Compare the first two elements.
3. If the order of them is wrong, swap them; otherwise skip this step.
4. Move to the next pair.
5. Repeat this process until no more swaps are needed.



# &#x1F4BB; Implementation
The program initializes an array of specified integers, performs ascending order sorting using the bubble sort algorithm, and finally displays the result.
<p align="center"><img src="./img/demonstration.png"/></p>

To prioritize simplicity and emphasize algorithm itself, several design decisions were made:
- Utilizing an integer array as a fundamental data structure.
- Exclusively implementing sorting in ascending order.
- Omitting certain optimizations from the algorithm.

---
Sorting algorithm implemented within the function `bubbleSort()`, which is declared in `BubbleSort.h` header file and defined in `BubbleSort.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Examination of sorting technique is conducted within the `main()` function located in the `Main.cpp` file.

**The complete implementation of a sorting function:**
```cpp
void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		bool swapped = false; 

		for (int j = 0; j < size - i - 1; j++) {
			// For descending order: arr[j] < arr[j + 1]
			if (arr[j] > arr[j + 1]) {
				// Can be optimized via swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}
```

---
**The Detailed Algorithm Overview:**
1. We manage the overall passes through the **entire collection** using `size - 1` because, after each pass, the largest element is guaranteed to be at its correct position. Therefore, there is no need to iterate over the already sorted elements.
```cpp
for (int i = 0; i < size - 1; i++) {
```

2. In the program, we utilize the variable `swapped` to facilitate loop termination. By initializing it with a value of `false`, we ensure that no swaps have occurred initially. This enables us to monitor whether any swaps take place during each pass.
```cpp
bool swapped = false; 
```

3. Within each pass of the collection, we start another loop to **compare and move** elements using `size - i - 1`. This enables us to skip iterating over elements that are already sorted in previous passes and the current one.
```cpp
for (int j = 0; j < size - i - 1; j++) {
```

4. Next, we compare the current element with the next one. If their order is incorrect, we swap the elements and update the indicator state; if their order is correct, we skip these actions. This process can be optimized by swapping elements, not copying.
```cpp
// For descending order: arr[j] < arr[j + 1]
if (arr[j] > arr[j + 1]) {
	// Can be optimized via swap
	int temp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = temp;

	swapped = true;
}
```

5. Finally, after completing a pass through the collection, we check if any swaps were made. If no swaps were made, it indicates that the elements are already sorted, and we can exit the loop.
```cpp
if (!swapped) {
	break;
}
```



# &#128202; Analysis
- **Comparison Approach:** 
  - **Comparison-Based** — operates by comparing elements pairwise to arrange them in order.

- **Time Complexity:**
     - Worst Case: $O(n^2)$ — data is in reverse sorted order (or almost), nested loop's operations are used nearly each iteration.
     - Average Case: $O(n^2)$ — data is randomly shuffled, nested loop's operations are used frequently enough.
     - Best Case: $O(n)$ — data is already sorted (or almost), nested loop's operations are rarely used.

- **Auxiliary Space Complexity:** 
  - $O(1)$ — no additional space is required beyond the input collection.

- **Stability:** 
  - **Stable** — if two elements are equal, they are not swapped, thus preserving their relative order.

- **Adaptabillity:** 
  - **Non-adaptive** — while it does avoid swaps for elements that are already in their correct positions, it does not adapt its overall behavior based on the existing order.



# &#128221; Application
Bubble Sort's utility is limited in modern software development contexts due to its inefficiency. Even for niche applications, there are better alternatives readily available, making Bubble Sort largely obsolete. Its primary relevance lies solely in educational purpose.



# &#x23F3; Historical Notes
In terms of computer science, Bubble Sort was one of the earliest sorting algorithms to be implemented in early computer programs. Its origin cannot be attributed to a single individual, rather it reflects the collective ingenuity of humanity. One notable contribution to this term, was documented in **1956** paper by mathematician and actuary **Edward Harry Friend**, who referred to it as "sorting exchange algorithm" and only later the well-known "Bubble Sort" name was coined by **Kenneth Eugene Iverson** in **1962**.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contact Information
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contact-information).



# &#128591; Credits
&#128218; **Books:**
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 6.4: Bubble Sort
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 5.2.2: Sorting by Exchanging

---
&#127891;**Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 20: Sorting Techniques
  
---
&#127760;**Web-Resources:**  
- [Bubble Sort](https://en.wikipedia.org/wiki/Bubble_sortt) (Wikipedia)
- [Bubble Sort Algorithm](https://www.geeksforgeeks.org/bubble-sort/)
- [Bubble Sort: An Archaeological Algorithmic Analysis](https://users.cs.duke.edu/~ola/papers/bubble.pdf)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)