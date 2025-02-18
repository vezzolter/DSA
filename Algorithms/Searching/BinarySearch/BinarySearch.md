# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Introduction](#introduction)
  - [Important Details](#important-details)
  - [Algorithm Steps](#algorithm-steps)
- [💻 Implementation](#-implementation)
  - [Design Decisions](#design-decisions)
  - [Complete Implementation](#complete-implementation)
  - [Detailed Walkthrough](#detailed-walkthrough)
- [📊 Analysis](#-analysis)
  - [Algorithm Characteristics](#algorithm-characteristics)
  - [Algorithm Comparison](#algorithm-comparison)
- [📝 Application](#-application)
  - [Common Use Cases](#common-use-cases)
  - [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [📖 Resources](#-resources)
- [🤝 Contributing](#-contributing)
- [🔏 License](#-license)



# &#128161; Overview
The **Binary Search** stands out as one of the most fundamental approaches to search for an element in an ordered collection. The algorithm is named for the way it divides the search interval in half with each step. Knowledge and understanding of it, lays a solid foundation for algorithmic design and tackling more complex problem-solving strategies.
<p align="center"><img src="./Images/BinarySearch.png"/></p>


## Introduction
**Binary Search** efficiently narrows down the search interval within an ordered collection by repeatedly dividing it in half until the target element is found or the interval becomes empty.


## Important Details
- The algorithm is only applicable to sorted collections; otherwise, it may search the wrong half of the data and return no result, even if the element is present.


## Algorithm Steps
1. Make sure the collection is in sorted order.
2. Calculate the middle index.
3. Compare target element with middle one.
   - if target **matches** with middle, the search is successful, **return** the index.
   - if target is **less** then middle, continue the search on the **left** half of a collection.
   - if target is **greater** then middle, continue the search on the **right** half of a collection.
4. Repeat the previous steps until the target element is found or the search interval is empty.



# &#x1F4BB; Implementation
The program initializes an array with specified integers, prompts the user to enter the value of a target element, performs a search using the binary search algorithm. It then displays the result, indicating whether the search was successful (element found) or not (element not found).
<p align="center"><img src="./Images/DemoSuccess.png"/></p>
<p align="center"><img src="./Images/DemoFailure.png"/></p>


## Design Decisions
To prioritize simplicity and emphasize algorithm itself, several design decisions were made:
- Utilizing a small integer array as a collection.
- Omitting certain optimizations to the algorithm.
- Assuming that collections is already sorted.


## Complete Implementation
Searching algorithm implemented within the function `binarySearch()`, which is declared in `BinarySearch.h` header file and defined in `BinarySearch.cpp` source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. Examination of sorting technique is conducted within the `main()` function located in the `Main.cpp` file. Below you can find related code snippets.

```cpp
int binarySearch(int arr[], int left, int right, int target) {
	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) { return mid; }
			

		if (arr[mid] < target) {
			left = mid + 1;
		} else { 
			right = mid - 1; 
		}
	}

	return -1;
}
```


## Detailed Walkthrough
1. We start by passing the sorted array, target element and left side index and right side index of search interval, which basically are start (`0`) and end (`size-1`) of a collection. This way we can iterate over search intervals of a collection anywhere by comparing them:
```cpp
  while (left <= right) {
```
2. In order to determine the middle index of a search interval, we apply this formula because it is more preferable due to the fact that it avoids overflow.
```cpp
  int mid = left + (right - left) / 2;
```
3. Then we can start searching process by comparing target with middle. First we check if we have found the element, if so return the index of it; otherwise we have to divide the search interval.
```cpp
  if (arr[mid] == target) { return mid; }
```
4. The idea behind division is pretty simple and straightforward: we "throw away" half of elements by moving the left index to the right of middle by one if target element appears to be greater then all of the elements in the left half and vice versa for right index.
```cpp
  if (arr[mid] < target) {
    left = mid + 1;
  } else {
    right = mid - 1;
  }
	
```
5. And if target element didn't match with any of present in collection, return an error code, indicating that the search is unsuccessful.
```cpp
  return -1;
```



# &#128202; Analysis
Understanding the characteristics of an algorithm is essential for choosing the right solution to a problem, as it reveals their impact on resource utilization, potential limitations and capabilities. Comparing the algorithm with other approaches provides insights into its strengths and weaknesses, helping to make informed decisions in various scenarios.


## Algorithm Characteristics
- **Search Strategy:** 
  - **Binary Approach** — operate on sorted datasets and repeatedly divide the search space in half until the target element is found.
- **Time Complexity:**
     - **Worst Case** $O(\log n)$ — occurs when target is either not present, therefore algorithm requires traverse through all elements.
     - **Average Case** $O(\log n)$ — occurs when target is spread within uniform probability, therefore algorithm doesn't require to perform all the steps to the end.
     - **Best Case** $O(1)$ — occurs when target is found at the middle, therefore only one comparison.
- **Auxiliary Space Complexity:** 
  - $O(1)$ — as no additional space is required beyond the input collection and a few variables.
- **Element's Mutability:**
   - **Suitable for Static** — as algorithm operates on sorted collections, maintaining sorted order of frequent changes could become costly in terms of resources, especially if it involves reallocation of memory, thus making it not the best option for a dynamic collection.
- **Key Representation:**
   - **Suitable for Actual Keys** — algorithm is primarily concerned with comparing keys directly in their original form, especially because of better alternatives out there.
- **Adaptability:**
   - **Non-Adaptive** — data processed through the same path of steps, regardless of their values, however algorithm requires the collection to be in sorted order.
- **Storage:**
   - **Suitable for Internal** — binary search is not suitable for external searching due to its reliance on random access patterns, which are inefficient for disk-based storage systems, thus for this type of searching there are more optimized alternatives.


## Algorithm Comparison
Will be Updated in the Future...



# &#128221; Application
Understanding some of the most well-known use cases of an algorithm is crucial for grasping its practical relevance and potential impact in real-world scenarios. Additionally, familiarizing oneself with common practical problems and practicing their solutions ensures that you remember the essential details and develop a deep, intuitive understanding of the functionality and limitations.


## Common Use Cases
- **Sorted Collections** — most common application of algorithm due to its efficiency in logarithmic time complexity, which makes it a good choice for dictionaries or large datasets.
- **Finding Upper/Lower Bound** — algorithm can be used when dealing with numerical datasets or when designing algorithms that require matching or approximation, because of how easy it is to find the target element, and calculate closest to it.
- **Building Data Structures** — binary search principle is crucial for data structures, that rely on maintaining sorted order efficient searching capabilities such as BSTs and Heaps, due to its efficiency.


## Some Practical Problems
- [Binary Search](https://leetcode.com/problems/binary-search)
- [First Bad Version](https://leetcode.com/problems/first-bad-version)
- [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array)
- [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array)
- [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix)
- [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array)
- [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays)
- [Minimum Cost to Make Array Equal](https://leetcode.com/problems/minimum-cost-to-make-array-equal)



# &#x1F559; Origins
The idea of binary search has evolved over time and there is no single individual behind them, especially because historical origins are not always well-recorded. In terms of computer science, it was one of the earliest searching algorithms to be implemented in early computer programs. Since then, many others have contributed to its understanding, analysis, and optimization.



# &#128214; Resources
&#128218; **Books:**
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 12.4: Binary Search
  - Section 2.6: Examples of Algorithm Analysis
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 2.4.4: Logarithms in the Running Time
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 2.6.1: Logarithms and Binary Search
  - Section 4.9: Binary Search and Related Algorithms
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 6.2.1: Searching an Ordered Table

---  
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 7: The Array ADT (Binary Search)

---  
&#127760; **Web-Pages:**  
- [Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm) (Wikipedia)
- [Why start + (end – start)/2 is preferable method for calculating middle of an array over (start + end)/2 ?](https://www.geeksforgeeks.org/start-end-start2-preferrable-method-calculating-middle-array-start-end2/) (Article)



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, contact details, and additional information, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)