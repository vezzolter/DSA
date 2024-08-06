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
The **Bucket Sort** (or **Bin Sort**) stands out as an efficient and simple sorting technique for uniformly distributed data. The algorithm is named for its key feature — buckets (bins), which are containers used to temporarily store elements within a specific range of values. This subsection explores idea of bucket sort not only to enhance comprehension of its concepts, but also to establish a solid foundation for a more complex algorithmic designs and problem-solving strategies.
<p align="center"><img src="./Images/BucketSort.png"/></p>


## Introduction
The **Bucket Sort** algorithm sorts a collection by distributing the elements into a number of buckets, then individually sorting each bucket (via placement or sorting) and finally concatenating all the sorted buckets back into a single sorted array. 


## Important Details
1. The underlying data structures for buckets are usually implemented as linked lists or arrays.
2. To determine the number of buckets to create, common methods include using the square root of the data size, a fixed number of buckets regardless of the size, the range of input values, or even data-driven approaches.
3. For sorting elements within buckets, standard library implementations are commonly used. However, insertion sort is suitable for small datasets, quicksort works well for medium-sized buckets, and merge sort is ideal for medium to large-sized buckets.


## Algorithm Steps
1. Calculate the number of buckets to use based on the size of the input array.
2. Identify the minimum and maximum values in the array to determine the range of values.
3. Compute the range of values that each bucket will hold.
4. Create and initialize the required number of buckets.
5. Place elements into corresponding bucket based on its value.
6. Sort the elements within each bucket.
7. Concatenate sorted elements from each bucket into the original array in order.



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
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 8.4: Bucket Sort
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 7.11: Linear-Time Sorts: Bucket Sort and Radix Sort
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 4.7: Distribution Sort: Sorting via Bucketing
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 5.2.5: Sorting by Distribution

---  
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 20: Sorting Techniques

---  
&#127760; **Web-Resources:**  
- [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort) (Wikipedia)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)