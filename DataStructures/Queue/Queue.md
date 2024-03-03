# &#128209; Table of Contents
- [💡 What is the Queue](#-what-is-the-queue)
- [💻 Implementation](#-implementation)
  - [Linear Queue](#linear-queue)
  - [Circular Queue](#circular-queue)
  - [Priority Queue](#priority-queue)
  - [Deque](#deque)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is the Queue
The Queue as a linear ADT (abstract data structure) in computer programming, becomes particularly valuable when you need to manage entities (e.g. data, objects, persons, events, tasks) in a sequential manner, where they are stored and held to be processed later, sort of a buffer. Regardless of the specific implementation details or optimizations used, queue operates on the FIFO (First-In-First-Out) principle, which ensures that elements are processed in the order they were inserted, overall maintaining the general idea. This subsection explores the ADT of Queue not only to enhance comprehension of its concepts, but also to establish a solid foundation for algorithmic design and problem-solving strategies.
<p align="center"><img src="./img/introduction.png"/></p>

---
**Queue** — is a term used to encompass the abstract concept of a data structure with FIFO behavior, with specific implementation details varying. It introduces the following essential terms:
- **Front/Head** — the end of the sequence at which elements are added.
- **Rear/Back/Tail** — the end of the sequence at which elements are removed.
- **Enqueue** — operation of adding an element to the rear.
- **Dequeue** — operation of removing an element from the front.


---
When it comes to implementation, queues can be broadly classified into four types: linear queue, circular queue, priority queue, and deque. While these specifications share some common ideas, each possesses distinctive characteristics, and some of them can be also combined together (e.g. deque with priority queue functionality). This variety provides the flexibility in data organization approaches, because the overall choice depends on the specific requirements of the case at hand.

**Linear Queue** — is a queue variation, where all insertions are made at one end of and all deletions at the other. Typically based on an array or a linked list data structure.
<p align="center"><img src="./img/structureLQ.png"/></p>

**Deque (Double-Ended Queue)** — is a queue variation, which allows insertion and deletion of elements from both ends. It can be either input or output restricted: input-restricted deques allow elements to be added at one end only, while output-restricted deques permit removal from only one end. Typically based on an array or a linked list data structure.
<p align="center"><img src="./img/structureDQ.png"/></p>

**Priority Queue** — is a queue variation, where elements are dequeued based on their priority level, rather than their order of insertion. It can have either ascending or descending priority order, determining whether elements with lower or higher priority levels are dequeued first. Typically based on a heap data structure.
<p align="center"><img src="./img/structurePQ.png"/></p>

**Circular Queue** — is a queue variation, where the rear of the queue is connected to the front. Typically based on an array data structure.
<p align="center"><img src="./img/structureCQ.png"/></p>







# &#x1F4BB; Implementation 
Currently in Progress...



##  Linear Queue
Currently in Progress...



##  Circular Queue
Currently in Progress...



##  Priority Queue
Currently in Progress...



##  Deque
Currently in Progress...




# &#128202; Analysis
Currently in Progress...



# &#128221; Application
Currently in Progress...



# &#x23F3; Historical Notes
Currently in Progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contact Information
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contact-information).



# &#128591; Credits
&#128218; **Books:**
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 3.7: The Queue ADT
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Chapter 4: Abstract Data Types
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 10.1: Stacks and Queues.
- **"The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd Edition)** — by Donald Ervin Knuth 
  - Section 2.2.1: Stacks, Queues, and Deques
  - Section 2.2.2: Sequential Allocation
  - Section 2.2.2: Linked Allocation

---
&#127891;**Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 14: Queues
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) from Coursera
   - Course 2.1: Linear Structures

---  
&#127760;**Web-Resources:**  
- [Queue (abstract data structure)](https://en.wikipedia.org/wiki/Linked_list) (Wikipedia)
- [What is Queue Data Structure?](https://www.geeksforgeeks.org/what-is-queue-data-structure/)
- [Queue Data Structure](https://www.tutorialspoint.com/data_structures_algorithms/dsa_queue.htm)
- [Array-Based Queues vs List-Based Queues](https://www.geeksforgeeks.org/array-based-queues-vs-list-based-queues/)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)