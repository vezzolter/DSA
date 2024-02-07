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
- **Head** — first node in the list.
- **Tail** — last node in the list.

---

When it comes to implementation, lists can be broadly classified into three types: singly linked list, doubly linked list and cirular linked list. While these types share some common ideas, each possesses distinctive characteristics. The choice between them depends on the specific requirements of the case at hand.

**Singly Linked List** — is a list, each node contains only one pointer to the next node in the sequence, enabling unidirectional traversal: forward from the head to the tail. The last node's "next pointer" points to nullptr, indicating the end of the list.


<p align="center"><img src="./img/structureSLL.png"/></p>

**Doubly Linked List** — is a list, where each node contains an additional pointer to the previous node in the sequence enabling bidirectional traversal: forward from the head to the tail and backward from the tail to the head. The first node's "previous pointer" and the last node's "next pointer" point to nullptr, indicating the start and end of the list, respectively.

<p align="center"><img src="./img/structureDLL.png"/></p>

**Circular Linked List** — is a list, where the last node points back to the head node. Allow for circular traversal, which can be unidirectional (if nodes are singly linked) or bidirectional (if nodes are doubly linked).

<p align="center"><img src="./img/structureCLL.png"/></p>


---

**Common Operations for ADT Linked List:**
- **Traversal** — iterating through the elements of the list.
- **Acess** — retrieving or updating the value of an existing element.
- **Insertion** — adding a new element to the list.
- **Deletion** — removing an element from the list.
- **Search** — locating a specific element within the list.
- **Sorting** — arranging the elements of the list in a specific order.
- **Merging** — combining two lists into one.
- **Splitting** — dividing the list into two or more parts.
- **Filtering** — selecting specific elements based on certain criteria.


---

**"Size-Consistent" Operations**

Lists provide **sequential access** meaning that we need to traverse the list's elements one by one in order to access them, which certainly requires time. Furthermore, as as the number of nodes in the list increases, the time required to traverse to a particular location also does. This results in the conclusion, that linked lists are not the preferred option in scenarios where you have to perform lots of operation that dona lot or the data structure size remains constant, although they still can be a natural fit for some cases.

<p align="center"><img src="./img/sizeConsistentOperations.png"/></p>

---

**"Size-Manipulating" Operations**

The true power of linked lists lies in the flexible nature of the size. Dynamic memory allocation of lists allow for flexible resizing, making them suitable for scenarios where the size of the data structure needs to change frequently. All of the "size-manipulating operations" are based on the the principle of "updating" nodes' pointers. Rather than delving into the intricacies of every possible operation, I'll illustrate a fundamental example of deleting an element that encapsulates the essence of the concept.

<p align="center"><img src="./img/sizeManipulatingOperations.png"/></p>


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
- rearraging elements is efficient due to simple change of pointers
- memory can be allocated diversely - in limited scenarios can have impact

---

Disadvantages:
- in order to get to the element you need to traverse whole array
- when there's no space left in memory insertions can fail.
- require additional memory for pointers

---

Common Operations Runtime:
- reading $O(n)$
- insertion $O(1)$
- deletion $O(1)$



# &#128221; Application

- stacks and queues
- adjacency matrix graph.
- dynamic memory location.
- hash table
- functionality known as undo


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
- [Linked List Data Structure](https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm)
- [Linked Lists](https://sbme-tutorials.github.io/2020/data-structure-FALL/notes/week03b.html#:~:text=of%20the%20list.-,Singly%20Linked%20Lists,is%20known%20as%20the%20tail.)
# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)