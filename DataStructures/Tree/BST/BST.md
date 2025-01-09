# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Essential Terminology](#essential-terminology)
  - [Important Details](#important-details)
  - [Operation Details](#operation-details)
- [💻 Implementation](#-implementation)
  - [Design Decisions](#design-decisions)
  - [Detailed Overview](#detailed-overview)
- [📊 Analysis](#-analysis)
  - [How to Analyze](#how-to-analyze)
  - [Advantages](#advantages)
  - [Disadvantages](#disadvantages)
- [📝 Application](#-application)
  - [Some of the Most Well-Known Use Cases](#some-of-the-most-well-known-use-cases)
  - [Common Practical Problems](#common-practical-problems)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
**Binary Search Tree (BST)** is an implementation of binary tree, designed to organize data for efficient search, insertion, and deletion operations. The name reflects its key feature: enabling fast searches by maintaining a sorted hierarchical structure. Knowledge and understanding of it lay a solid foundation in designing data structures and optimizing their application.
<p align="center"><img src="./Images/BST.png"/></p>



## Important Details
- **Ordering Property** — for any given node, all values in the left subtree are less than the nodes's value, and all the values in the right subtree are greater than the node's value. This property is the core of BST, ensuring a hierarchical structure that supports efficient operations; any violation compromises the tree's integrity and reliability.
- **Duplicates** — while some implementations of BSTs disallow duplicates altogether, others allow them but require consistent handling. A common approach is to add a counter to each node to track the frequency of duplicate values, or to consistently place duplicates in either the left or right subtree. The decision is left to the developer and depends on the specific use case, but consistent handling is crucial to maintaining the BST’s structure.
- **Balancing** — insertions and deletions can affect the balance of a BST, causing the heights of the left and right subtrees to differ significantly. While the tree may still function correctly in such cases, its performance (both in terms of time and space) can degrade, particularly for large datasets. Without rebalancing, a BST can degenerate into a structure resembling a linked list, with a height of $O(n)$, where $n$ is the number of nodes, resulting in lookup performance equivalent to linear search. To maintain efficiency, balancing mechanisms are employed to keep the tree height bounded by $O(\log n)$, ensuring optimal performance even during updates (e.g. AVL, Red-Black).


## Container Methods
When working with BSTs, it's important to note that there is no universal standard defining a strict list of operations or guidelines for how they should be implemented. Moreover, raw BSTs are rarely implemented directly in modern programming libraries. Instead, **self-balancing trees** (e.g. Red-Black Trees, AVL Trees) are used to maintain efficient $O(\log n)$ operations and are employed **internally** to implement higher-level containers such as `std::map` (C++), `TreeMap` (Java), or `SortedSet` (C#). Since the design and functionality of containers vary significantly depending on several factors, it is difficult to pinpoint a definitive list of operations. Therefore, in this repository, the container methods aim to replicate some of the fundamental operations present in most implementations.

---
**Compiler Generated**:
- `Default Constructor` — creates an empty BST, initializing its internal structure to represent a tree with no nodes.
- `Copy Constructor` — creates a new BST by copying the structure and values of another tree.
- `Move Constructor` — creates a new BST by transferring the structure and values from another tree, leaving the original tree in a valid but unspecified state. This avoids the overhead of copying by efficiently reusing the original memory.
- `Copy Assignment Operator` — replaces the contents of the current BST with the structure and values of another tree by copying them.
- `Move Assignment Operator` — replaces the contents of the current BST by transferring the structure and values from another tree, leaving the original tree in a valid but unspecified state.
- `Destructor` — performs cleanup on the BST: deallocates memory for stored nodes and properly handles any associated resources, ensuring no memory leaks.

---
<p align="center"><img src="./Images/OperationsIterators.png"/></p>

**Iterators:**
- `begin`, `cbegin` — returns an iterator (or constant iterator) pointing to the smallest node in the tree (in-order traversal).
- `end`, `cend` — returns an iterator (or constant iterator) pointing past the largest node in the tree.
- `rbegin`, `crbegin` — returns an iterator (or constant iterator) pointing to the largest node in the tree (reverse in-order traversal).
- `rend`, `crend` — returns an iterator (or constant iterator) pointing past the smallest node in reverse traversal.

---
<p align="center"><img src="./Images/OperationsAccess.png"/></p>

**Elements Access**:
- `find(key)` — returns a pointer or iterator to the node containing the specified key.
  - returns `nullptr` or equivalent if the key is not found.
- `min()` — returns a pointer or iterator to the node with the smallest key in the tree.
- `max()` — returns a pointer or iterator to the node with the largest key in the tree.
- `successor(key)` — returns a pointer or iterator to the node with the smallest key greater than the specified key (in-order successor).
- `predecessor(key)` — returns a pointer or iterator to the node with the largest key smaller than the specified key (in-order predecessor).

---
**Capacity**:
- `empty()` — returns `true` if the tree contains no nodes, otherwise `false`.
- `size()` — returns the number of nodes in the tree.
- `maxSize()` — returns the theoretical maximum number of nodes the tree can hold, depending on memory limits.
- `height()` — returns the height of the tree (the length of the longest path from the root to a leaf).

---
<p align="center"><img src="./Images/OperationsModifiers.png"/></p>

**Modifiers**:
- `insert(key)` — inserts a new node with the specified key into the tree, maintaining the BST ordering property.
- `erase(key)` — removes the node with the specified key from the tree, adjusting the structure as needed to maintain the ordering property.
  - if the node has two children, it is replaced with its in-order successor or predecessor.
- `clear()` — removes all nodes from the tree, leaving it empty.
- `swap(other)` — exchanges the contents of the current tree with another tree, avoiding expensive deep copies.

---
**Operations**:
- `traverse()` — traverses the tree in the specified order (`in-order`, `pre-order`, `post-order`, or `level-order`) and applies a function to each node.
- `contains(key)` — checks whether the tree contains a node with the specified key.
- `validate()` — checks whether the tree satisfies the BST ordering property, useful for debugging or verifying correctness.
- `count(key)` — returns the number of nodes in the tree containing the specified key.
  - for trees that disallow duplicates, this returns either `0` or `1`.



# &#x1F4BB; Implementation 
The implemented console application demonstrates the basic functionality of the BST by performing various operations and interactions with it. The program provides a clear view of changes made during usage, displaying the state of the data at different stages to illustrate its simplified behavior and characteristics.
<p align="center"><img src="./Images/Demonstration.png"/></p>


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
**Easy Problems:**
1. [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree)
2. [Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree)
3. [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst)
4. [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst)
5. [Find Mode in Binary Search Tree](https://leetcode.com/problems/find-mode-in-binary-search-tree)
6. [Increasing Order Search Tree](https://leetcode.com/problems/increasing-order-search-tree)

---
**Medium Problems:** 
1. [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees)
2. [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree)
3. [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree)
4. [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree)
5. [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst)
6. [Serialize and Deserialize BST](https://leetcode.com/problems/serialize-and-deserialize-bst)
7. [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst)
8. [Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree)
9. [Balance a Binary Search Tree](https://leetcode.com/problems/balance-a-binary-search-tree)
10. [All Elements in Two Binary Search Trees](https://leetcode.com/problems/all-elements-in-two-binary-search-trees)

---
**Hard Problems:** 
1. [Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree)
2. [Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst)
3. [Merge BSTs to Create Single BST](https://leetcode.com/problems/merge-bsts-to-create-single-bst)



# &#x1F559; Origins
Currently in Progress...



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128231; Contacts
For contact details and additional information, please refer to the [root directory's contact information section](../../../#-contacts).



# &#128591; Credits
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 12: Binary Search Trees
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 12.5: Binary Search Trees (BSTs)
  - Section 12.6: Performance Characteristics of BSTs
  - Section 12.8: Insertion at the Root of BSTs
  - Section 12.9: BST Implementations of Other ADT Functions
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 4.3: The Search Tree ADT — Binary Search Trees
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 3.4: Binary Search Trees
- **"The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd Edition)** — by Donald Ervin Knuth
  - Section: 2.3.2: Binary Tree Representation of Trees

---
&#127891; **Courses:**
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) on Coursera
  - Section 2.2: Introduction to Tree Structures
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
  - Section 16: Binary Search Trees

---  
&#127760; **Web-Resources:**  
- [Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) (Wikipedia)
- [How to handle duplicates in BST?](https://www.geeksforgeeks.org/how-to-handle-duplicates-in-binary-search-tree/) (Article)
- [Balancing a binary search tree](https://appliedgo.net/balancedtree/) (Article)
- [On the efficiency of a new method of dictionary construction](https://www.sciencedirect.com/science/article/pii/S0019995860909013) (Research Paper)
- [More combinatorial properties of certain trees](http://comjnl.oxfordjournals.org/content/7/4/299.full.pdf) (Research Paper)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)