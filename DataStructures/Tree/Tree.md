# &#128209; Table of Contents
- [💡 Overview](#-overview)
  - [Essential Terminology](#essential-terminology)
- [💻 Implementation](#-implementation)
  - [Core Mechanics](#core-mechanics)
  - [Existing Solutions](#existing-solutions)
  - [Repository Containers](#repository-containers)
- [📊 Analysis](#-analysis)
  - [Evaluating Characteristics](#evaluating-characteristics)
  - [Comparing Containers](#comparing-containers)
- [📝 Application](#-application)
  - [Common Use Cases](#common-use-cases)
  - [Some Practical Problems](#some-practical-problems)
- [🕙 Origins](#-origins)
- [📖 Resources](#-resources)
- [🤝 Contributing](#-contributing)
- [🔏 License](#-license)



# &#128161; Overview
The **Tree** stands out as one of the most fundamental concept in computer science. Trees represents a category of collections that mirror the hierarchical behavior of trees in nature, making them a particularly well-suited choice for depicting relationships that have a parent-child or ancestor-descendant structure. This subsection explores trees to establish a solid foundation of understanding, as it helps to create elegant and efficient algorithmic designs for all manner of applications.
<p align="center"><img src="./Images/Tree.png"/></p>


## Essential Terminology
- **Collection** — is a data structure (or container) used to group multiple elements together.
  - **Tree** — is a collection consisting of nodes and edges that satisfies requirements based on the tree type and maintains ascendant-descendant relationships.
  - **Subtree** — is a tree within a tree formed by selecting a node and all its descendants.
- **Node** — is an each individual element contained within the tree, containing actual information stored within and pointers (or references) to other nodes.
  - **Root** — the topmost node serving as a starting point, thus having no parent.
  - **Parent** — is a node that has one or more child nodes connected to it.
  - **Child** — is a node connected to a parent node.
  - **Siblings** — nodes that share the same parent.
  - **External Node/Leaf** — is a node with no children.
  - **Internal Node** — is a node with children.
  - **Ancestor/Predecessor** — is a node located above another node, along the path leading from the root node to that node.
  - **Descendant/Successor** — is a node located below another node, along the path leading from the root node to that node.
  - **Neighbor of a Node** — any other node that is directly connected to particular node by an edge.
- **Edge** — is a connection between two nodes in a tree, which helps to manage the relationships.
- **Path** — is a sequence of nodes and edges from one node to another one, which must be **only one** for any pair of nodes, otherwise it is a graph.
  - **Length of Path** — is a number of edges (sometimes people consider nodes) that path contains.
  - **Shortest Path** — is a path with minimum length, i.e. the path that requires the fewest number of edges to traverse from one node to another.
  - **Longest Path** — is a path with maximum length, i.e. the path that requires the greatest number of edges to traverse from one node to another.
- **Height of the Node** — is a number of edges from leaf node to a particular node in the longest path.
  - **Height of the Tree** — is a number of edges from leaf node to a root in the longest path.
- **Depth of the Node** — is a number of edges from root node to a particular node.
  - **Depth of the Tree** — is a number of edges from root node to a leaf node in the longest path.
- **Level of the Node** — is a number of edges from root (level 0) down to the particular node (depth - 1).
  - **Width of the Tree** — is the maximum number of nodes among all the levels.
  - **Breadth of the Tree** — is the number of nodes at the last level of the tree, i.e. number of leaves.
- **Degree of a Node** — is a total number of children of a particular node.
  - **Degree of a Tree** — is the highest degree among all the nodes.



# &#x1F4BB; Implementation
Understanding the underlying mechanics of a data structure is essential to grasp how it operates and manages data. Since one data structure can have different implementations, it's crucial to recognize these distinctions, especially by learning from existing solutions, which often offer efficient, well-tested approaches to handling data and optimizing performance.


## Core Mechanics
When delving into the world of trees, it's essential to begin with binary tree, often regarded as the foundational building block. Before exploring more intricate tree structures, let's first establish a solid understanding of two fundamental concepts:
- **Binary Tree** — is a tree structure in which each node can have a maximum of $2$ children, referred to as the left child and the right child.  
- **M-ary Tree** — is a generalization of binary trees, where each node can have a maximum of `m` children.

---
<p align="center"><img src="./Images/BinaryTreeTypes.png"/></p>

**Binary Trees can be described as:**
- **Rooted (Default)** — all nodes have a maximum of $2$ children.
- **Perfect** — all nodes have $2$ children and all leaves have the same level.
- **Full** — all nodes have either $0$ or $2$ children.
- **Complete** — all levels are filled with the maximum amount of nodes ($2$), except last one.
- **Balanced** — height of the left and right subtrees of every node differ by at most $1$.
- **Degenerate (Pathological)** — all nodes have only $1$ child, if all nodes are aligned in a single direction it can be referred to as **skewed**.

---
**Some of the Derived Properties:**
1. Number of null links (absent children) for $x$ nodes is $x+1$.
2. Maximum number of nodes at $l$ level is $2^l$.
3. Maximum number of nodes for tree of $h$ height is $2^h-1$.
4. Maximum possible height for $x$ nodes is $log{_2}{(x+1)}$.
5. Minimum number of levels for $x$ nodes is $log{_2}{(x+1)}$.
6. Minimum number of levels for $x$ external nodes is $|log{_2}{(x)}|+1$.
7. Minimum height of the tree for $x$ external nodes is $log{_2}{(x)}$.
8. In non-empty tree, number of edges for $x$ nodes is $e=n-1$.
9. In perfect tree, number of external nodes $x$ is $\frac{x+1}{2}$.
10. In full tree, number of external nodes is always one more than nodes with two children.
11. In full tree, minimum number of nodes for $h$ height of the tree is $2h+1$.
12. In full tree, maximum number of nodes for $h$ height of the tree is $2^{h+1}-1$.
13. In complete tree, number of internal nodes for $x$ nodes is $⌊x/2⌋$.

> Note: There is no need to remember all the properties, but you should understand how to come up with them if the task requires. Additionally, practice breaking down binary tree structures and analyzing their components to build intuition for deriving relevant knowledge.


## Existing Solutions
When it comes to the implementation of abstract data types (ADTs), there are many different ways to represent trees. While some share common ideas, each possesses distinctive characteristics. To cover them all, it's essential to understand the fundamental concept behind the most well-known representations and make slight adjustments to the chosen tree structure.

Note that it is commonly recommended to rely on proven, well-established, and widely recognized implementations that already exist, rather than reinventing the wheel. In the context of C++, these could include tree-based containers (e.g. `boost::multiway_tree`, `boost::tree`) from the **Boost Graph Library**, or several containers (e.g. `std::set`, `std::map`) from the **STL**, which can be used to implement trees. Although trees can be implemented via [arrrays](https://github.com/vezzolter/DSA/blob/main/DataStructures/Array/Array.md) (binary heaps), typically they are implemented similarly to [linked lists](https://github.com/vezzolter/DSA/blob/main/DataStructures/LinkedList/List.md), where each node is a structure or class containing information, pointers, and optional logic.

Within the scope of this repository, we'll take a closer look at simplified versions of popular trees to gain a deeper understanding of the fundamental concepts that underlie them. After this section, it would be beneficial to examine previously mentioned implementations in practice (e.g. pet-projects, LeetCode-like sites) to solidify the knowledge


## Repository Containers
One of the most important things behind binary trees is how elements are inserted into them. The insertion process similar linked lists, albeit with slight adjustments — elements are inserted based on specific criteria. These criteria can vary, making the binary tree an adaptable container to diverse needs. Perhaps this adaptability is the reason why there's no single container that precisely represents a general binary tree, and it's certainly the reason I've chosen not to implement one. Instead, I suggest starting with this brief overview of binary trees to avoid overwhelming complexity, and head to next types of trees listed in this repository in the following order:
  - [BST (Binary Search Tree)](https://github.com/vezzolter/DSA/tree/main/DataStructures/Tree/BST)✅
  - [AVL Tree](https://github.com/vezzolter/DSA/tree/avl/DataStructures/Tree/AVL)🎯  
  - Splay Tree
  - Red-Black Tree 
  - 2-3-4 Tree
  - B-Tree
  - Trie
  - Fenwick Tree
  - Segment Tree
  - Suffix Tree ❔
  - K-Dimension Tree ❔



# &#128202; Analysis
Understanding how to analyze the particular implementation of a data structure in terms of time and space complexity is crucial for optimizing performance and ensuring efficient resource utilization within the constraints of the given environment. Additionally, knowing the pros and cons of different data structures allows to make informed decisions, helping to choose the most suitable approach for a given problem.


## Evaluating Characteristics
Currently in Progress...


## Comparing Containers
Currently in Progress...



# &#128221; Application
Understanding some of the most well-known use cases of a data structure is crucial for grasping its practical relevance and potential impact in real-world scenarios. Additionally, familiarizing oneself with common practical problems and practicing their solutions ensures that you remember the essential details and develop a deep, intuitive understanding of the functionality and limitations.


## Common Use Cases
- **File Systems** — trees are used in file systems to represent hierarchy. Each node in the tree represents a directory or folder, and the branches represent subdirectories or files contained within each directory.

- **Database Indexing** — trees often used in database indexing to organize and search records based on keys. They enable quick retrieval of data in databases by providing an efficient index structure that allows for fast lookup operations.

- **GUIs** — trees often used in GUIs to represent the hierarchical structure of user interface elements such as menus, widgets, and windows. Each node in the tree represents a UI component, and the branches represent the containment relationships between these components.

- **Networking** — trees often used in networking to represent network topologies and routing tables. They provide a structured way to organize and manage network devices and connections, making it easier to route data packets efficiently between different nodes in the network.

- **Decision Making** — trees often used in decision-making processes to model complex decision scenarios and evaluate different options. Each node in the tree represents a decision or a possible outcome, and the branches represent the different choices or paths that can be taken. By traversing the tree, decision-makers can analyze the potential outcomes of different choices and make informed decisions based on the available information.


## Some Practical Problems
- Currently in Progress...



# &#x1F559; Origins
The concept of tree data structures, due to its natural and simple idea, emerged long ago and independently throughout the world. One notable documented mention comes from the field of mathematics, particularly from the German physicist and mathematician **Gustav Robert Kirchhoff**. In **1847**, Kirchhoff used trees to find a set of fundamental cycles in an electrical network in connection with the law that bears his name. Another German mathematician, **Karl Georg Christian von Staudt**, also used the same concept around this time in his book _«Geometrie der Lage»_. About ten years later (**1857**), the British mathematician **Arthur Cayley** described trees in terms of enumeration in his series of papers _«Collected Mathematical Papers of A. Cayley»_. Since then, numerous people have contributed to the idea of trees, such as Carl Wilhelm Borchardt, Johann Benedict Listing, Marie Ennemond Camille Jordan, Denes Konig, Luitzen Egbertus Jan "Bertus" Brouwer.

In the context of computer programming, the origins of trees came from mathematics, quickly gaining widespread adoption and undergoing continuous development by many people worldwide around **1950**. This led to the appearance of many different versions such as AVL (1962), B-Tree (1970), Red-Black (1978), Fenwick (1989), and many others along the way.



# &#128214; Resources
&#128218; **Books:**
- **"Introduction to Algorithms" (3rd Edition)** — by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein
  - Section 10.4: Representing Rooted Trees
  - Section 12: Binary Search Trees
  - Section 12.8: Insertion at the Root of BSTs
  - Section 13: Red-Black Trees
  - Section 14: Augmenting Data Structures
  - Section 18: B-Trees
- **"Algorithms in C++, Parts 1-4: Fundamentals, Data Structure, Sorting, Searching" (3rd Edition)** — by Robert Sedgewick
  - Section 5: Recursion and Trees
  - Section 12: Symbol Tables and BSTs
  - Section 13: Balanced Trees
  - Section 15.1: Digital Search Trees
  - Section 15.2: Tries
  - Section 15.3: Patricia Tries
  - Section 15.4: Multiway Tries and TSTs
  - Section 16.3: B Trees
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 4.1: Preliminaries
  - Section 4.2: Binary Trees
  - Section 4.8: Sets and Maps in the Standard Library
  - Section 12: Advanced Data Structures
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 3.4: Binary Search Trees
  - Section 12.3: Suffix Trees and Arrays
  - Section 12.6: Kd-Trees
- **"The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd Edition)** — by Donald Ervin Knuth
  - Section: 2.3: Trees
  - Section 2.6: History and Bibliography

---
&#127891; **Courses:**
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) on Coursera
  - Section 2.2: Introduction to Tree Structures
  - Section 2.3: Advanced Tree Structures
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
  - Section 15: Trees
  - Section 16: Binary Search Trees
  - Section 17: AVL Trees
  - Section 18: Search Trees

---  
&#127760; **Web-Pages:**  
- [Tree (data structure)](https://en.wikipedia.org/wiki/Tree_(data_structure)) (Wikipedia)
- [Tree structure](https://en.wikipedia.org/wiki/Tree_structure) (Wikipedia)
- [Tree - Terminology](http://www.btechsmartclass.com/data_structures/tree-terminology.html) (Article)
- [Binary tree](https://en.wikipedia.org/wiki/Binary_tree) (Wikipedia)
- [Binary Tree: Properties, Types, Representation, Application](https://www.enjoyalgorithms.com/blog/introduction-to-binary-tree) (Article)



# &#129309; Contributing
Contributions are highly appreciated! For detailed guidelines, contact details, and additional information, please refer to the [root directory's contributing section](../../#-contributing).



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)