# &#128209; Table of Contents
- [💡 Overview](#-overview)
	- [Essential Terminology](#essential-terminology)
	- [Core Mechanics](#core-mechanics)
	- [Container Methods](#container-methods)
- [💻 Implementation](#-implementation)
	- [Design Decisions](#design-decisions)
	- [Container Implementation](#container-implementation)
	- [Iterator Implementation](#iterator-implementation)
- [📊 Analysis](#-analysis)
	- [Characteristics](#characteristics)
	- [Trade-Offs](#trade-offs)
- [📝 Application](#-application)
	- [Common Use Cases](#common-use-cases)
	- [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
**Stack** refers to both an abstract data structure and a concrete container, that operates on a Last-In-First-Out (LIFO) principle. The term _«stack»_ comes from this real-world analogy of stacking objects on top of each other, much like stack of dishes where the topmost item is the first to be accessed. Knowledge and understanding of it lay a solid foundation in designing data structures and optimizing their application.
<p align="center"><img src="./Images/Stack.png"/></p>


## Essential Terminology
- **Abstract Data Structure** — is a theoretical model that defines a set of operations and guarantees for organizing and manipulating data, independent of memory organization or specific implementation details.
  - **Data Structure** — is a theoretical model of data organization in memory, used to design containers in an efficient or specific ways.
  - **Container** — is a concrete implementation, used to manage actual data through specific operations. Containers are primarily defined by the operations and guarantees they provide, which can originate from the data structure itself or from an abstract data structure. As long as those guarantees are fulfilled, the underlying model can be modified or replaced.
- **Stack** — refers to both an abstract data structure and a concrete container, that operates on a LIFO principle. This dual nature arises from its ability to represent a conceptual guarantee of functionality while being implemented in diverse ways.
  - **Top** — is the end of the collection at which elements are added and removed.
  - **Bottom** — is the end of the collection opposite to the top.


## Core Mechanics
Work of many computer programs is organized in a way that naturally aligns with how a stack operates. Programs frequently postpone certain tasks to handle others, and often need to return to the most recently postponed task. This behavior reflects the **LIFO** principle, making the stack a fundamental data structure for managing tasks in a wide range of algorithms.

To better understand the stack, specific terms are introduced to describe its structure and operations. The end of the collection where elements are added and removed is called the **top**, while the **bottom** refers to the opposite end, which remains fixed unless the stack is emptied. The design of a stack enforces the LIFO principle by restricting operations to the **top**. Elements can be added (an operation known as **push**) or removed (**pop**) only from this end. Many implementations also include a **peek** operation, allowing the value of the top element to be viewed without modifying the stack. These constraints have their own advantages and disadvantages, which are discussed in the [Trade-Offs](#trade-offs) section.

---
At its core, a stack is simply a collection that enforces the **LIFO** principle, and it imposes no strict requirements on how it must be implemented. While the most common implementations allow users to choose the underlying data structure, by default they rely on **arrays** and then on **linked lists**, although stack can also be built using other data structures in specialized contexts.
<p align="center"><img src="./Images/DifferentMemoryLayouts.png"/></p>

Most stack implementations rely on arrays due to their simplicity, efficiency, and excellent memory locality, which improves performance for sequential processing. In array-based stacks, elements are stored in contiguous memory, with a pointer or index used to track the top of the stack. This design ensures $O(1)$ performance for push and pop operations under normal conditions. Additionally, arrays eliminate the need for dynamic memory allocation during individual operations, reducing overhead. In contrast to linked lists, arrays benefit from superior cache locality and lower memory overhead. However, this approach comes with limitations: fixed-size arrays require a predefined capacity, leading to potential **overflow**. To address this, modern implementations often use dynamically resizable arrays, which double their size when full, balancing efficiency and memory management. 


## Container Methods
Currently in Progress...



# &#x1F4BB; Implementation
Currently in Progress...


## Design Decisions
Currently in Progress...


## Container Implementation
Currently in Progress...


## Iterator Implementation
Currently in Progress...



# &#128202; Analysis
Currently in Progress...


## Characteristics
Currently in Progress...


## Trade-Offs
Currently in Progress...



# &#128221; Application
Currently in Progress...


## Common Use Cases
Currently in Progress...


## Some Practical Problems
Currently in Progress...



# &#x1F559; Origins
Due to the simple and natural concept of this data structure it was quite common in computer programming from the earliest days and its origins cannot be attributed to a single individual, rather it reflects the collective ingenuity of humanity. However, it is still possible to retrace a few notable contributions to understanding of stack to the following people **Jan Lukasiewicz**, **Konrad Zuse**, **Alan Mathison Turing**, **Charles Leonard Hamblin** and most notably **Klaus Samelson** with **Friedirch Ludwig Bauer**, who in March 1988 received the IEEE Computer Pioneer Award for the invention of the stack principle.



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 10.1: Stacks and Queues
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 4.2: Pushdown Stack ADT
  - Section 4.3: Examples of Stack ADT Clients
  - Section 4.4: Stack ADT Implementations
  - Section 4.5: Creation of a New ADT
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 3.1: Abstract Data Types (ADTs)
  - Section 3.6: The Stack ADT
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 3.2: Stacks and Queues
- **"The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd Edition)** — by Donald Ervin Knuth 
  - Section 2.2.1: Stacks, Queues, and Deques
  - Section 2.6: History and Bibliography

---
&#127891; **Courses:**
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
   - Section 13: Stack
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) from Coursera
   - Course 2.1: Linear Structures

---  
&#127760; **Web-Resources:**  
- [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (Wikipedia)
- [std::stack](https://en.cppreference.com/w/cpp/container/stack) (Documentation)
- [Second-Generation Stack Computer Architecture](http://fpgacpu.ca/publications/Second-Generation_Stack_Computer_Architecture.pdf) (Research Paper)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)