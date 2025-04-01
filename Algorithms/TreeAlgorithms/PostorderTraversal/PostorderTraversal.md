# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Introduction](#introduction)
  - [Important Details](#important-details)
  - [Algorithm Steps (Recursive)](#algorithm-steps-recursive)
- [💻 Implementation](#-implementation)
  - [Design Decisions](#design-decisions)
  - [Complete Implementation](#complete-implementation)
  - [Detailed Walkthrough](#detailed-walkthrough)
- [📊 Analysis](#-analysis)
  - [Characteristics](#characteristics)
  - [Trade-Offs](#trade-offs)
- [📝 Application](#-application)
  - [Common Use Cases](#common-use-cases)
  - [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [📖 Resources](#-resources)
- [🤝 Contributing](#-contributing)
- [🔏 License](#-license)



# &#128161; Overview
**Postorder traversal** is a fundamental algorithm for visiting nodes in a binary tree. When you think of traversal names as root placement plus left-to-right reading order, it is possible to observe that the name «POSTorder» means the root is visited AFTER the left and right subtrees. Knowledge and understanding of it lay a solid foundation for algorithmic design and tackling more complex problem-solving strategies.
<p align="center"><img src="./Images/PostorderTraversal.png"/></p>


## Introduction
The algorithm visits both subtrees before processing the root node — following the order Left-Right-Root in the standard version, and Right-Left-Root in the reversed version.


## Important Details
1. Can be implemented using **recursion** or **iteration**, but unlike inorder and preorder, iterative postorder is more complex due to the need to ensure both children are visited before the node; it often requires two stacks or clever use of a single stack with tracking.


## Algorithm Steps (Recursive)
**Standard Version:**
1. Set up the base case, stopping recursion when traversal reaches the end of a branch.
2. Recursively traverse the left subtree by calling the function on the left child.
3. Recursively traverse the right subtree by calling the function on the right child.
4. Process the current node (this step depends on the specific task at hand).

---
**Reversed Version:**
1. Set up the base case, stopping recursion when traversal reaches the end of a branch.
2. Recursively traverse the right subtree by calling the function on the right child.
3. Recursively traverse the left subtree by calling the function on the left child.
4. Process the current node (this step depends on the specific task at hand).



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
I couldn’t find any definitive records tracing its origins, so I’m assuming it naturally emerged as people began exploring tree structures and needed a way to process children before their parent nodes. As recursion and bottom-up processing became more common, the Left-Right-Root order likely stood out as a clean way to finalize a node only after fully handling everything beneath it.



# &#128214; Resources
&#128218; **Books:**
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 5.6: Tree Traversal
  - Section 5.7: Recursive Binary-Tree Algorithms
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 4.1: Preliminaries
  - Section 4.2: Binary Trees
  - Section 4.6: Tree Traversals (Revisited)
- **"The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd Edition)** — by Donald Ervin Knuth
  - Section: 2.3.1: Traversing Binary Trees

---
&#127891; **Courses:**
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) on Coursera
  - Section 2.2: Introduction to Tree Structures
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
  - Section 15: Trees



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, contact details, and additional information, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)