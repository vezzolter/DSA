# &#128209; Table of Contents
- [💡 What is the Linked List](#-what-is-the-linked-list)
- [💻 Implementation](#-implementation)
  - [Singly Linked List](#singly-linked-list)
  - [Doubly Linked List](#doubly-linked-list)
  - [Circular Linked List](#circular-linked-list)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is the Linked List

A linked list, a fundamental data structure in computer programming, becomes particularly valuable when the primary objective involves traversing a collection of items sequentially, one by one. In contrast to arrays, linked lists allow for non-contiguous memory allocation, offering a dynamic and flexible approach to data organization.

This subsection explores the Abstract Data Type (ADT) of Linked List not only to enhance understanding, but also to establish a solid foundation for approaching more intricate data structures.



<p align="center"><img src="./img/memoryCells.png"/></p>

---

**Linked List** — is a linear data structure, consists of elements named as nodes that are linked together using pointers, because they are not necessarily adjacent in memory. It introduces the following essential terms:
- **Node** — each individual element contained within the list. Consists of two main components: data and pointer.
- **Data** — holds the actual value associated with the node.
- **Pointer** — stores the memory address of the next node in the sequence.
- **Head** — pointer to the first node in the list.
- **Tail** — pointer to the last node in the list.



# &#x1F4BB; Implementation 
Currently in progress...

##  Singly Linked List
Currently in progress...

##  Doubly Linked List
Currently in progress...

##  Circular Linked List
Currently in progress...


# &#128202; Analysis
Advantages:
- rearrange efficiently (you never have to move items): adding/removing elements requires only replacing the address
- memory can be allocated diversely - no need to allocated in one single block in arrays

---

Disadvantages:
- in order to get to the element you need to traverse whole array
- when there's no space left in memory insertions can fail.

---

Common Operations Runtime:
- reading $O(n)$
- insertion $O(1)$
- deletion $O(1)$



# &#128221; Application
Currently in progress...



# &#x23F3; Historical Notes
Currently in progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contact Information
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contact-information).



# &#128591; Credits
&#128218; **Books:**
- **"Grokking Algorithms"** — by Aditya Bhargava
  - Section 2.1: How memory works
  - Section 2.2: Arrays and linked lists
- **"Data Structures and Algorithm Analysis in C++""** — by Mark A. Weiss
  - Section 3.1: Abstract Data Types
  - Section 3.2: The List ADT
  - Section 3.3: `vector` and `list` in the STL
  - Section 3.5: Implementation of `list`
- **"Algorithms in C++, Parts 1-4"** — by Robert Sedgewick
  - Section 3.3: Linked Lists
  - Section 3.4: Elementary List Processing
  - Section 3.5: Memory Allocation for Lists
- **"Introduction to Algorithms"** — by CLRS
  - Section 10.2: Linked Lists

&#127891;**Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/?LSNPUBID=JVFxdTr9V80&ranEAID%3B=JVFxdTr9V80&ranMID%3B=39197&ranSiteID%3B=JVFxdTr9V80-_3GVcwGZFWT4XsSuZYrgGA&utm_source=adwords&utm_medium=udemyads&utm_campaign=DSA_Catchall_la.EN_cc.ROW&utm_content=deal4584&utm_term=_._ag_88010211481_._ad_535397282064_._kw__._de_c_._dm__._pl__._ti_dsa-406594358574_._li_9061020_._pd__._&matchtype=&gad_source=1&gclid=CjwKCAiA3aeqBhBzEiwAxFiOBgRFL7RkV-WJI9tPKml75et478Ai5oJigSKAivJ2txZ9Jhi0mhsTdxoC_foQAvD_BwE) on Udemy
   - Section 11: Linked List
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) from Coursera
   - Course 2.1: Linear Structures
  
&#127760;**Web-Resources:**  
- [Linked List](https://en.wikipedia.org/wiki/Linked_list) (Wikipedia)
- [Understanding the basics of Linked List](https://www.geeksforgeeks.org/what-is-linked-list/)
- [How Linked Lists Work](https://www.freecodecamp.org/news/how-linked-lists-work/)
- [Linked List Data Structure](https://www.geeksforgeeks.org/data-structures/linked-list/)

# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)