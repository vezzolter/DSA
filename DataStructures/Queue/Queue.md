# &#128209; Table of Contents
- [💡 What is the Queue](#-what-is-the-queue)
- [💻 Implementation](#-implementation)
  - [Linear Queue](#linear-queue)
  - [Deque](#deque)
  - [Circular Queue](#circular-queue)
  - [Priority Queue](#priority-queue)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is the Queue
The Queue as a linear ADT (abstract data structure) in computer programming, becomes particularly valuable when you need to manage entities (e.g. data, objects, persons, events, tasks) in a sequential manner, where they are stored and held to be processed later, sort of a buffer. This subsection explores the ADT of Queue not only to enhance comprehension of its concepts, but also to establish a solid foundation for algorithmic design and problem-solving strategies.
<p align="center"><img src="./img/introduction.png"/></p>


---
**Queue** — is a term used to encompass a variety of ADTs with similar sequential behavior. It introduces the following essential terms:
- **Front/Head** — the end of the sequence at which elements are added.
- **Rear/Back/Tail** — the end of the sequence at which elements are removed.
- **Enqueue** — operation of adding an element to the rear.
- **Dequeue** — operation of removing an element from the front.


---
When it comes to implementation, queues can be broadly classified into four types: linear queue, double-ended queue, circular queue, and priority queue. While these specifications share some common ideas, each possesses distinctive characteristics, and some of them can be also combined together (e.g. deque with circular functionality). This variety provides the flexibility in data organization approaches, because the overall choice depends on the specific requirements of the case at hand.

1. **Linear Queue** — all insertions are made at one end of and all deletions at the other, operates on the First-In-First-Out principle.  
**Typical underlying DS:** arrays, linked lists.
<p align="center"><img src="./img/structureLQ.png"/></p>

2. **Deque (Double-Ended Queue)** — allows insertion and deletion of elements from both ends.
    - **Input Restricted Deque** — allows insertion from only one end (either rear or front).
    - **Output Restricted Deque** — allows removal from only one end (either rear or front).
    
   **Typical Underlying DS:** arrays, linked lists.
<p align="center"><img src="./img/structureDQ.png"/></p>

3. **Circular Queue** — variation of deque or linear queue, that connects front with rear ends.  
**Typical underlying DS:** arrays, linked lists.
<p align="center"><img src="./img/structureCQ.png"/></p>

4. **Priority Queue** — elements are dequeued based on their priority level, rather than their order of insertion.
    - **Ascending Priority Queue** — elements with higher priority levels are dequed first.
    - **Descending Priority Queue** — elements with lower priority levels are dequed first. 
    
   **Typical underlying DS:** max-heaps, min-heaps.  
<p align="center"><img src="./img/structurePQ.png"/></p>


---
**Common Operations for Queues:**
- **Accessing Specific Elements** — retrieving or updating the value of an existing element at a specific position.
- **Enqueueing (Insertion)** — adding a new element to the queue.
- **Dequeueing (Deletion)** — removing an element from the queue.



# &#x1F4BB; Implementation 
Currently in Progress...



##  Linear Queue
Currently in Progress...



##  Deque
Currently in Progress...



##  Circular Queue
Currently in Progress...



##  Priority Queue
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
- [Queue Data Structure](https://www.programiz.com/dsa/queue)
- [std::queue](https://en.cppreference.com/w/cpp/container/queue)
- [Applications, Advantages and Disadvantages of Queue](https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-queue/)
- [Double-ended queue](https://en.wikipedia.org/wiki/Double-ended_queue) (Wikipedia)
- [Deque Data Structure](https://www.programiz.com/dsa/deque)
- [std::deque](https://en.cppreference.com/w/cpp/container/deque)
- [Applications, Advantages and Disadvantages of Deque](https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-deque/)
- [Circular buffer](https://en.wikipedia.org/wiki/Circular_buffer) (Wikipedia)
- [Introduction to Circular Queue](https://www.geeksforgeeks.org/introduction-to-circular-queue/)
- [Circular Queue](https://www.programiz.com/dsa/circular-queue)
- [Applications, Advantages and Disadvantages of Circular Queue](https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-circular-queue/)
- [Priority Queue](https://en.wikipedia.org/wiki/Priority_queue) (Wikipedia)
- [Priority Queue](https://www.programiz.com/dsa/priority-queue)
- [std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)
- [Applications of Priority Queue](https://www.geeksforgeeks.org/applications-priority-queue/)
- [Different Types of Queues and its Applications](https://www.geeksforgeeks.org/different-types-of-queues-and-its-applications/)
- [Array-Based Queues vs List-Based Queues](https://www.geeksforgeeks.org/array-based-queues-vs-list-based-queues/)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)