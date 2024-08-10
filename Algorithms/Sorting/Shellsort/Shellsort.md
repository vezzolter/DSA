# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Introduction](#introduction)
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
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
The **Shellsort** stands out as an early and efficient optimization of insertion sort, known for sorting elements more quickly by comparing and moving items that are far apart before focusing on those that are close together. Shellsort is named after its inventor, Donald  Lewis Shell. Knowledge and understanding of it, lays the foundation for tackling more complex sorting algorithms and problem-solving strategies.
<p align="center"><img src="./Images/Shellsort.png"/></p>


## Introduction
**Shellsort** begins by organizing elements that are far apart, gradually reducing the gap between compared elements until the entire collection is sorted. This approach allows larger jumps in the early stages, efficiently moving elements closer to their correct positions before finalizing the sort with smaller, more precise steps.


## Important Details
There are several way to pick a gap sequence for algorithm, here are some of them:
 - **Shell's Sequence (1959)**  — is original one, simple to implement, but not the most efficient for large datasets.  
 **General Term:** $\lfloor\frac{n}{2^k}\rfloor-\text{where }k\text{ is iteration},n\text{ is number of elements}$  
 **Concrete Gap:** $\frac{n}{2}, \frac{n}{4}, \frac{n}{8}, ..., 1$  
 **Time Complexity:** $O(n^2)$
   
 - **Hibbard's Sequence (1963)**  — is designed to avoid large gaps in the data during sorting, helping to position elements closer to their final sorted positions early on, which reduces the number of subsequent operations needed.  
 **General Term:** $2^k-1$  
 **Concrete Gap:** $1, 3, 7, 15, 31, 63 ...$  
 **Time Complexity:** $O(n^{\frac{3}{2}})$
   
 - **Pratt's Sequence (1971)** — is theoretically efficient, utilizing a dense set of gap values that systematically cover a wide range of element distances; however, the complexity of its generation makes it less common in practical applications.  
 **General Term:**  $2^i×3^j-\text{where }i\text{ and }j\text{ are just non-negative integers}$  
 **Concrete Gap:** $1, 2, 3, 4, 6, 8, 9, 12,  ...$  
 **Time Complexity:** $O(n\log^2n)$
   
 - **Knuth's Sequence (1973)** — is particularly appreciated for its practical balance between simplicity and efficiency, making it a go-to choice for many Shellsort implementations due to its effective gap progression.   
 **General Term:** $\frac{(3^k-1)}{2}$  
 **Concrete Gap:** $1, 4, 13, 40, 121, ...$  
 **Time Complexity:** $O(n^{\frac{3}{2}})$
   
 - **Sedgewick's Sequence (1986)**  — is crafted to carefully minimize the total number of comparisons and swaps, by varying the gaps more dynamically, resulting in a more efficient sort, especially for larger datasets.   
 **General Term:** $\begin{cases}9(2^k-2^{\frac{k}{2}})+1&\text{if }k\text{ is even} \\8×2^k-6×2^{\frac{k+1}{2}}&\text{if }k\text{ is odd}\end{cases}$  
 **Concrete Gap:** $1, 5, 19, 41, 109, ...$  
 **Time Complexity:** $O(n^{\frac{4}{3}})$


## Algorithm Steps
Currently in Progress...



# &#x1F4BB; Implementation
Currently in Progress...


## Design Decisions
Currently in Progress...


## Complete Implementation
Currently in Progress...


## Detailed Walkthrough
Currently in Progress...



# &#128202; Analysis
Currently in Progress...


## Algorithm Characteristics
Currently in Progress...


## Algorithm Comparison
Will be Updated in the Future...



# &#128221; Application
Currently in Progress...


## Common Use Cases
Currently in Progress...


## Some Practical Problems
Currently in Progress...



# &#x1F559; Origins
Currently in Progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 6.6: Shellsort
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 7.4: Shellsort
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 5.2.1: Sorting by Insertion

---  
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 20: Sorting Techniques

---  
&#127760; **Web-Resources:**  
- [Shellsort](https://en.wikipedia.org/wiki/Shellsort) (Wikipedia)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)