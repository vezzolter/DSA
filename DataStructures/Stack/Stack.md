# &#128209; Table of Contents
- [💡 What is the Stack](#-what-is-the-stack)
- [💻 Implementation](#-implementation)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [⏳ Historical Notes](#-historical-notes)
- [🤝 Contributing](#-contributing)
- [📧 Contact Information](#-contact-information)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; What is the Stack
The **Stack** stands out as one of the most fundamental abstract data type (ADT) in computer science that serves as a linear collection of elements, which becomes particularly valuable when you need to manage entities (e.g. data, objects, persons, events, tasks) in a last-in-first-out (LIFO) manner. It is named this way, because of how it resembles the behavior of adding or removing items from the top of a physical stack. This subsection explores the stack ADT not only to enhance comprehension of its concepts, but also to establish a solid foundation for a more complex algorithmic designs and problem-solving strategies.
<p align="center"><img src="./img/Stack2.png"/></p>

---
**Essential Terminology:**
- **Stack** — is a ADT that serves as a linear collection that operates on the LIFO principle.
- **Top** — is the end of the of a collection at which elements are added and removed.
- **Bottom** — is the end of the of a collection opposite to the top.
- **Push** — is an operation of adding an element to the top.
- **Pop** — is an operation of removing an element from the top.
- **Peek** — is an operation of returning a value of element at the top.
- **Overflow** — is a condition that occurs when trying to push an element onto a full stack.
- **Underflow** — is a condition that occurs when trying to pop an element from an empty stack.

---
What identifies the data structure as stack is not the implementation but the interface: the user is only allowed to pop or push elements with few other helper operations. The interface includes next common operations:
- **push** — inserts element at the top.
- **pop** — removes the top element.
- **peek** — accesses the top element.
- **empty** — checks whether the container adaptor is empty.
- **size** — returns the number of elements.

---
When it comes to the underlaying data structure, a stack generally can be broadly classified into two types: 
- **Array-Based Stack** — utilizes a fixed-size or dynamic array to store elements.  
- **List-Based Stack** — utilizes a singly, doubly or circular linked list to store elements.

While these types share some common ideas, each possesses distinctive characteristics related to the "base" of ADT. For example, while frequent insertion/removal on array can lead to a quite resourceful reallocation, those same operations in linked list require dereferencing. Overall the choice between them depends on the specific requirements of the case at hand.  



# &#x1F4BB; Implementation
Currently in progress...



# &#128202; Analysis
Currently in progress...



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
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 3.1: Abstract Data Types
  - Section 3.6: The Stack ADT
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 4: Abstract Data Types
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 10.1: Stacks and Queues
- **"The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd Edition)** — by Donald Ervin Knuth 
  - Section 2.2.1: Stacks, Queues, and Deques
  - Section 2.2.2: Sequential Allocation
  - Section 2.2.3: Linked Allocation

---
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 13: Stack
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) from Coursera
   - Course 2.1: Linear Structures

---  
&#127760; **Web-Resources:**  
- [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (Wikipedia)
- [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)
- [std::stack](https://en.cppreference.com/w/cpp/container/stack)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)