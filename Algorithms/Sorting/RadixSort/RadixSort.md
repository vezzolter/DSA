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
The **Radix Sort** stands out as one of the most well-known non-comparative sorting technique. The name of algorithm describes its method of sorting numbers by processing individual digits according to their position within the base (radix) of the number system. This subsection explores idea of radix sort not only to enhance comprehension of its concepts, but also to establish a solid foundation for a more complex algorithmic designs and problem-solving strategies.
<p align="center"><img src="./img/RadixSort.png"/></p>

---
The **Radix Sort** processes each digit of the numbers, starting from the least significant (rightmost) to the most significant (leftmost), and sorts the numbers by distributing them into buckets based on each digit, then collecting them back into a sorted sequence after each digit processing step.

**Important Details:**
1. Can be applied to data that can be sorted lexicographically (e.g. integers, words, punch cards, playing cards).
2. Requires modification to handle floating-point numbers, negative integers, or strings of variable lengths, which can add overall complexity to the algorithm.
3. Works best when the numbers have the same number of digits, otherwise they need to be padded.

**Algorithm Steps:**
1. Determine the maximum number of digits in the largest number.
2. Initialize 10 buckets for each digit (0-9).
3. Sort the numbers by their least significant digit.
4. Collect the numbers from the buckets back into the original list.
5. Sort the numbers by the next significant digit.
6. Collect the numbers from the buckets back into the original list.
7. Repeat the sorting and collecting steps for each digit until the most significant digit has been processed.



# &#x1F4BB; Implementation
The program initializes an array of specified integers, performs ascending order sorting using the radix sort algorithm, and finally displays the result.
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
  - Section 8.3: Radix Sort
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 10: Radix Sorting
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 7.11: Linear-Time Sorts: Bucket Sort and Radix Sort
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 5.2.2: Sorting by Exchanging

---  
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 20: Sorting Techniques

---  
&#127760; **Web-Resources:**  
- [Radix Sort](https://en.wikipedia.org/wiki/Radix_sort) (Wikipedia)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)