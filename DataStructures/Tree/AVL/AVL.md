# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Important Details](#important-details)
  - [Container Methods](#container-methods)
- [💻 Implementation](#-implementation)
  - [Design Decisions](#design-decisions)
  - [Container Implementation](#container-implementation)
  - [Node Implementation](#node-implementation)
  - [Iterator Implementation](#iterator-implementation)
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
The **AVL Tree** is a self-balancing implementation of the binary search tree (BST) that strictly maintains height balance by enforcing a maximum difference of 1 between subtree heights at every node. The tree is named after its two Soviet inventors, Georgy Adelson-Velsky and Evgenii Landis, who introduced it in 1962 as the first self-balancing BST. Knowledge and understanding of it lay a solid foundation in designing data structures and optimizing their application.
<p align="center"><img src="./Images/AVL.png"/></p>


## Important Details
1. **Self-Balancing BST** — self-balancing BST is a type of tree that will adjust itself (automatically update pointers to reorganize the nodes) in specific moments (whenever an operation causes an imbalance) in order to prevent performance degradation seen in unbalanced BSTs, where certain operations degrade from $O(\log{n})$ to $O(n)$ due to excessive skewing.

2. **BST Ordering Property** — for any given node (`x`), all values in the left subtree are less than the node's value (`left` $<$ `x`), and all values in the right subtree are greater than the node's value (`right` $>$ `x`). This property is the core of BSTs, ensuring a hierarchical structure that supports efficient operations; any violation compromises the tree's integrity and reliability.

3. **AVL Height-Balancing Property** — for any given node, the height difference between its left and right subtrees is at most $1$, which can be expressed as $|$`leftHeight` $-$ `rightHeight`$| \leqslant 1$. This constraint prevents the tree from becoming excessively skewed, ensuring that its height remains logarithmic in relation to the number of nodes. 

4. **Balance Factor (BF)** — is a numerical value that represents the height difference between a node's left and right subtrees, calculated as `BF` $=$ `leftHeight` - `rightHeight` (although some people reverse the formula, the idea remains the same). Basically it is a metric that enforces the AVL height-balancing property, because it allows determining whether node is balanced or not, and if at any time `BF` exceeds the balanced range (i.e. node becomes unbalanced), rebalancing is performed to restore that property. The node is considered:
   - **balanced** if its `BF` equals $-1$, $0$, or $1$;
   - **right-heavy** if its `BF` $< -1$ (because right subtree is taller);
   - **left-heavy** if its `BF` $> 1$ (because left subtree is taller).
   
   Pretty often, to simplify height calculations, some implementations define the height of a leaf's child pointers as $-1$, this way the formula for height $max($`leftHeight`, `rightHeight`$) + 1$ results in $max(-1,-1) + 1 = -1 + 1 = 0$, which correctly represents the height of a leaf node (it takes $0$ steps to get from a leaf to a itself).
   
5. **Only Two Bits** — is currently in progress...

6. **Rebalancing via Rotations** — will be covered later, since the topic of rotations is common for multiple trees and [Tree.md](https://github.com/vezzolter/DSA/blob/avl/DataStructures/Tree/Tree.md) is still in progress...

7. **Fibonacci Relation** — is currently in progress...

8.  **Duplicates** — while some implementations of AVLs disallow duplicates altogether, others allow them but require consistent handling. A common approach is to add a counter to each node to track the frequency of duplicate values, or to consistently place duplicates in either the left or right subtree. The decision is left to the developer and depends on the specific use case, but consistent handling is crucial to maintaining the AVL’s structure.



## Container Methods
Currently in Progress...



# &#x1F4BB; Implementation 
Currently in Progress...


## Design Decisions
Currently in Progress...


## Container Implementation
Currently in Progress...


## Node Implementation
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
Currently in Progress...



# &#128214; Resources
&#128218; **Books:**
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 4.4: AVL Trees
- **"The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd Edition)** — by Donald Ervin Knuth
  - Section 6.2.3: Balanced Trees

---
&#127891; **Courses:**
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) on Coursera
  - Section 2.3: Advanced Tree Structures
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
  - Section 17: AVL Trees

---
&#127916; **Recordings:**
- [Lecture 6: AVL Trees, AVL Sort](https://www.youtube.com/watch?v=FNeL18KsWPc) (Lecture)
- [Balanced binary search tree rotations](https://www.youtube.com/watch?v=q4fnJZr8ztY) (Video)

---  
&#127760; **Web-Pages:**  
- [AVL tree](https://en.wikipedia.org/wiki/AVL_tree) (Wikipedia)
- [Self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree) (Wikipedia)
- [Tree rotation](https://en.wikipedia.org/wiki/Tree_rotation) (Wikipedia)
- [An anlgorithm for the organization of information](https://zhjwpku.com/assets/pdf/AED2-10-avl-paper.pdf) (Research Paper)



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, contact details, and additional information, please refer to the [root directory's contributing section](../../../#-contributing).



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)