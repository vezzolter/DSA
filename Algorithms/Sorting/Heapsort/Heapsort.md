# &#128209; Table of Contents
- [📑 Table of Contents](#-table-of-contents)
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
The **Heapsort** stands out as one of the most well-known and efficient sorting techniques. The algorithm is named for its use of the heap data structure property, which implies that the keys of parent nodes are either greater than or equal to those of their children (in a max heap) or less than or equal to those of their children (in a min heap). Therefore, it is recommended to first learn about heaps. This subsection explores the idea of heapsort not only to enhance comprehension of its concepts, but also to establish a solid foundation for more complex algorithmic designs and problem-solving strategies.
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


# &#128202; Analysis
Currently in Progress...



# &#128221; Application
Currently in Progress...



# &#x1F559; Origins
Currently in Progress...



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