# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Essential Terminology](#essential-terminology)
- [💻 Implementation](#-implementation)
  - [How to Implement](#how-to-implement)
  - [Critical Challenges](#critical-challenges)
  - [Potential Optimizations](#potential-optimizations)
- [📊 Analysis](#-analysis)
  - [How to Analyze](#how-to-analyze)
  - [Trade-Offs](#trade-offs)
  - [Alternatives](#alternatives)
- [📝 Application](#-application)
  - [Common Use Cases](#common-use-cases)
  - [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
**Sorting** is a fundamental operation in both the real world and computer science, organizing items into a specific order to improve data management. Mastering this concept is essential — not just for its broad practical applications, but for its ability to unlock more advanced problem-solving capabilities and optimize performance across various domains.
<p align="center"><img src="./Images/Sorting.png"/></p>


## Essential Terminology
- **Sorting Algorithm** — is set of steps used to obtain a particular order of elements within a collection of data.
   - **Hybrid Sorting** — is a sorting method that combines two or more algorithms to leverage their individual strengths, resulting in improved overall efficiency.
- **Criterion** — is a rule used to make the decisions about the order of elements.
- **Order** — is an arrangement of elements within a collection based on a defined set of criteria.
  - **Ascending/Increasing/Non-Decreasing** $(x\geqslant y)$ — from smallest to largest, with duplicates; e.g. $1, 2, 2, 2, 3$.
  - **Descending/Decreasing/Non-Increasing** $(x\leqslant y)$ — from largest to smallest, with duplicates; e.g. $3, 2, 2, 2, 1$.
  - **Strictly Increasing** $(x>y)$ — from smallest to largest, without duplicates; e.g. $1, 2, 3, 4, 5$.
  - **Strictly Decreasing** $(x<y)$ — from largest to smallest, without duplicates; e.g. $5, 4, 3, 2, 1$.
  - **Lexicographical** — elements are ordered based on their dictionary sequence; e.g. $12, 123, 2, 23, 3$.
  - **Custom** — elements are sorted based on a user-defined criterion; e.g. $2, 3, 5, 4, 6$ (ascending with prime number first).
- **Collection** — is a data structure, which is used to group multiple elements together.
  - **Table** — is a small collection of all elements.
  - **File** — is a big collection of all elements.
  - **Database** — is a large collection of all elements.
- **Element/Record/Item** — is an individual entity within a collection.
  - **Index** — is a position of an element within collection.
  - **Value/Data** — is an actual information stored within the element.



# &#x1F4BB; Implementation
When implementing a concept, it's essential to understand the fundamental techniques that drive its behavior and ensure its correct functionality. Additionally, recognizing the critical challenges and potential optimizations allows you to refine the implementation, making it more efficient and robust for various scenarios.


## How to Implement
Currently in Progress...


## Critical Challenges
Currently in Progress...


## Potential Optimizations
Currently in Progress...



# &#128202; Analysis
Understanding how to analyze a concept is crucial for identifying its key characteristics and evaluating its performance across different scenarios. Additionally, examining the trade-offs allows you to understand what you gain and what you give up when applying the concept. Finally, considering alternatives helps you determine when the concept is the best choice and when other approaches might be more appropriate.


## How to Analyze
- **Comparison Approach:**
   - **Comparison-Based** — algorithm sorts elements by comparing them using pairwise comparisons to determine their relative order.
   - **Non-Comparison-Based** — algorithm sorts elements without explicitly comparing them, often using specific properties of data.

- **Time Complexity:**
   - $O(nlogn)$ — efficient performance, divide the input into smaller subproblems and solve them recursively.
   - $O(n)$ — proportional to the size of the input data, each element is compared or moved at most once.
   - $O(n^2)$ — less efficient, typically involve nested loops or multiple comparisons.
   - **Other** — although they are in the minority, it is worth mentioning them.
  
- **Space Complexity:**
   - **In-Place** $\big(O(1)\big)$  — algorithm doesn't require any additional memory.
   - **Out-of-Space** $\big(O(n)/O(nlogn)/...\big)$ — algorithm does require some additional memory.

- **Stability:**
   - **Stable** — algorithm preserves the relative order of equal elements, i.e. if two elements from the input are considered equal, stable algorithm ensures that they will maintain this order in sorted output.
   - **Unstable** — algorithm doesn't guarantee the preservation of the relative order of equal elements; i.e. they can either be swapped or kept, algorithm doesn't consider the original positions.

- **Adaptability:**
   - **Adaptive** — algorithm adjusts its overall behavior (sequence of operations) based on the initial order of elements to improve performance.
   - **Non-Adaptive** — algorithm processes data through the same path of steps, regardless of their values.

- **Directness:**
   - **Direct** — algorithm sorts elements directly manipulating themselves.
   - **Indirect** — algorithm utilizes some sort of a pointer onto elements in order to sort them, typically it is done because moving huge chunks can be more resourceful operation compared to little shortcuts.

- **Storage:**
   - **Internal** — algorithm takes place entirely within the main memory (RAM) of computer.
   - **External** — algorithm takes place within other devices (e.g. hard disk), typically due to their huge size.


## Trade-Offs
**What Sorting Gives:**
- **Organized Data** — sorting transforms unordered data into a structured form, enhancing the efficiency of subsequent operations, such as searching and merging. In many applications, having sorted data simplifies logic and improves performance, making it easier to manage and process large datasets.  
- **Improved Algorithm Performance** — many algorithms are designed to work more efficiently with sorted data. Sorting can therefore be a prerequisite step that unlocks the potential of these algorithms, allowing them to operate optimally.

---
**What Sorting Takes:**
- **Time Investment** — sorting requires computational resources, and for large datasets, this time investment can be significant. Sorting is often a prerequisite rather than the final goal, making this time cost an important consideration in time-sensitive applications.
- **Memory Usage** — some sorting algorithms, particularly those that are not in-place, require additional memory. In memory-constrained environments, this trade-off can be critical. Even in-place algorithms like quicksort can have hidden memory costs, such as stack space for recursive calls.
- **Complexity in Implementation** — efficient sorting algorithms can be complex to implement and optimize, requiring careful consideration of edge cases and algorithmic design. This complexity might introduce bugs or make the code harder to maintain.
- **Energy and Power Consumption** — in resource-constrained environments, such as embedded systems, the energy cost of sorting operations can be a significant trade-off, impacting battery life and system performance.


## Alternatives
Currently in Progress...



# &#128221; Application
Understanding some of the most well-known use cases of a concept is crucial for grasping its practical relevance and potential impact in real-world scenarios. Additionally, familiarizing oneself with practical problems and practicing their solutions ensures that you retain essential details and develop a deep, intuitive understanding of the concept's capabilities and limitations.


## Common Use Cases
- **Search and Retrieval** — sorting facilitates efficient searching and retrieval operations in various data structures like arrays, trees, and hash tables. Sorted data allows for faster lookup times using techniques like binary search.
- **Ordering and Ranking** — sorting used for arranging data in ascending or descending order based on specific criteria, such as numerical values, alphabetical order, or timestamps. This enables easier analysis, visualization, and decision-making processes.
- **Data Presentation and Visualization** — comes from previous, sorted data is often presented visually in charts, graphs, and reports to convey trends, patterns, and insights effectively. Visualization tools rely on sorted data to generate meaningful and informative visual representations.
- **Optimization Problems** — sorting is used in various optimization problems, such as job scheduling, task prioritization, and resource allocation. Sorted data enables the efficient allocation of resources and scheduling of tasks based on predefined criteria or constraints.
- **Data Deduplication** — sorting helps identify and remove duplicate entries or records from datasets efficiently. By sorting the data, duplicate entries can be easily identified and eliminated, improving data quality and reducing storage overhead.


## Some Practical Problems
**Easy Problems:**
1. [Sorting the Sentence](https://leetcode.com/problems/sorting-the-sentence)
2. [Widest Vertical Area Between Two Points Containing No Points](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points)
3. [Sort the People](https://leetcode.com/problems/sort-the-people)
4. [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays)
5. [Relative Sort Array](https://leetcode.com/problems/relative-sort-array)
6. [Matrix Cells in Distance Order](https://leetcode.com/problems/matrix-cells-in-distance-order)
7. [Valid Anagram](https://leetcode.com/problems/valid-anagram)
8. [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array)
9. [Sort Even and Odd Indices Independently](https://leetcode.com/problems/sort-even-and-odd-indices-independently)
10. [Largest Perimeter Triangle](https://leetcode.com/problems/largest-perimeter-triangle)

---
**Medium Problems:** 
1. [Sort an Array](https://leetcode.com/problems/sort-an-array)  
2. [Sort List](https://leetcode.com/problems/sort-list)  
3. [Sort the Matrix Diagonally](https://leetcode.com/problems/sort-the-matrix-diagonally)  
4. [Group Anagrams](https://leetcode.com/problems/group-anagrams)  
5. [Find Polygon With the Largest Perimeter](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter)  
6. [Sort Colors](https://leetcode.com/problems/sort-colors)  
7. [Car Fleet](https://leetcode.com/problems/car-fleet)  
8. [3Sum](https://leetcode.com/problems/3sum)  
9.  [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements)
10. [Maximum Gap](https://leetcode.com/problems/maximum-gap)
11. [Find Original Array From Doubled Array](https://leetcode.com/problems/find-original-array-from-doubled-array)
12. [Merge Intervals](https://leetcode.com/problems/merge-intervals)
13. [Find if Array Can Be Sorted](https://leetcode.com/problems/find-if-array-can-be-sorted)
14. [Shortest Unsorted Continuous Subarray](https://leetcode.com/problems/shortest-unsorted-continuous-subarray)
15. [Maximize Area of Square Hole in Grid](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid)

---
**Hard Problems:** 
1. [Make Array Strictly Increasing](https://leetcode.com/problems/make-array-strictly-increasing)
2. [Orderly Queue](https://leetcode.com/problems/orderly-queue)
3. [Minimum Replacements to Sort the Array](https://leetcode.com/problems/minimum-replacements-to-sort-the-array)
4. [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream)
5. [Recover the Original Array](https://leetcode.com/problems/recover-the-original-array)
6. [GCD Sort of an Array](https://leetcode.com/problems/gcd-sort-of-an-array)
7. [Minimize Manhattan Distances](https://leetcode.com/problems/minimize-manhattan-distances)
8. [Make Array Empty](https://leetcode.com/problems/make-array-empty)
9. [Sum of Subsequence Widths](https://leetcode.com/problems/sum-of-subsequence-widths)
10. [Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance)



# &#x1F559; Origins
While sorting as concept emerged unknown-long time ago and throughout the whole world naturally, the development of sorting algorithms dates back in the early days of computing. One notable early milestone in the computer science's history of sorting methods goes back in the late **1880s**, when American genius **Herman Hollerith** started to work on tabulating machines and came up with efficient solution to automate the manual process by formulating an algorithm, which only later led to the **Radix Sort**.

The breakthrough came with the invention of divide-and-conquer sorting algorithm **Merge Sort** by Hungarian-American computer scientist **John von Neumann** in **1945** and other pioneers, that were born in the **1950s** such as **Bubble Sort** and the **Selection Sort**, which were simple but quite inefficient and thus impractical for large datasets. Later the famous **Quicksort** was developed by British computer scientist **Tony Hoare** in **1959** and published in **1961**, which still remains a commonly used algorithm for sorting. Summarizing, these individuals, among others, played crucial roles in integrating sorting into practical programming paradigms.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 8: Sorting in Linear Time
  - Section 9: Medians and Order Statistics
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 6: Elementary Sorting Methods
  - Section 7: Quicksort
  - Section 8: Merging and Mergesort
  - Section 9: Priority Queues and Heapsort
  - Section 10: Radix Sort
  - Section 11: Special-Purpose Sorts
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 7: Sorting
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 4: Sorting and Searching
  - Section 14: Combinatorial Problems
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 5: Sorting

---
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 20: Sorting Techniques

---  
&#127760; **Web-Resources:**  
- [Sorting Algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) (Wikipedia)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)