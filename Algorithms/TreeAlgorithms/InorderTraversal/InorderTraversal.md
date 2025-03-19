# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Introduction](#introduction)
  - [Important Details](#important-details)
  - [Algorithm Steps](#algorithm-steps)
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
**Inorder traversal** is a fundamental algorithm for visiting nodes in a binary tree. When you think of traversal names as root placement plus left-to-right reading order, it is possible to observe that the name «inorder» means the root is visited IN between the left and right subtrees. Knowledge and understanding of it lay a solid foundation for algorithmic design and tackling more complex problem-solving strategies.
<p align="center"><img src="./Images/InorderTraversal.png"/></p>


## Introduction
The algorithm visits the root node in between its left and right children — following the order Left-Root-Right in the standard version, and Right-Root-Left in the reversed version.


## Important Details
1. When inorder traversal is applied to a BST, it visits nodes in **ascending sorted order** due to the tree’s inherent ordering property; when reversed inorder traversal is used, it processes nodes in **descending sorted order** instead.
2. Can be implemented using **recursion**, **iteration**, or **Morris traversal**, where the recursive approach relies on an implicit function call stack, the iterative approach uses an explicit stack, and Morris traversal achieves the same result with $O(1)$ extra space by temporarily modifying tree links.


## Algorithm Steps (Recursive)
**Standard Version:**
1. Set up the base case, stopping recursion when traversal reaches the end of a branch.
2. Recursively traverse the left subtree by calling the function on the left child.
3. Process the current node (this step depends on the specific task at hand).
4. Recursively traverse the right subtree by calling the function on the right child.

---
**Reversed Version:**
1. Set up the base case, stopping recursion when traversal reaches the end of a branch.
2. Recursively traverse the right subtree by calling the function on the right child.
3. Process the current node (this step depends on the specific task at hand).
4. Recursively traverse the left subtree by calling the function on the left child.



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
Currently in Progress...


# &#128214; Resources
Currently in Progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, contact details, and additional information, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)