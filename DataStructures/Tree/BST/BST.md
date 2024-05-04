# &#128209; Table of Contents
- [💡 Overview](#-overview)
- [💻 Implementation](#-implementation)
- [📊 Analysis](#-analysis)
- [📝 Application](#-application)
- [🕙 Origins](#-origins)
- [🤝 Contributing](#-contributing)
- [📧 Contacts](#-contacts)
- [🙏 Credits](#-credits)
- [🔏 License](#-license)



# &#128161; Overview
The **Binary Search Tree (BST)** stands out as one of the most common implementation of a binary tree. Its name is derived from one of the main operations performed on it, which is searching for a specific element This subsection explores BST to establish a solid knowledge of the ideas behind it, as it helps to create elegant and efficient algorithmic designs for all manner of applications.
<p align="center"><img src="./img/BST.png"/></p>

---
**Binary Search Tree** — is a binary tree, which organizes elements in a sorted manner by following this **property:** for every node, all values in the left subtree are less than the value of the node, and all values in the right subtree are greater than the value of the node.

---
**Important Details:**
- **Duplicates** — while some implementations disallow duplicates elements, some allow. The question is how to handle them is up to developer, one common approach can be either to add counter to each node and simply update it, or entirely skip duplicates.
- **Balance** — insertions and deletions can affect the balance of the BST, meaning that the heights of the left and right subtrees of nodes may differ significantly. If that happens tree may still function correctly, but it may exhibit degraded performance (both space and time), especially for large datasets. To prevent this, balancing mechanisms may be employed (e.g. AVL, Red-Black).

---
**Operations:**  
Currently in Progress...



# &#x1F4BB; Implementation 
Currently in Progress...



# &#128202; Analysis
Assuming that BST is based on a [linked list](https://github.com/vezzolter/DSA/blob/main/DataStructures/LinkedList/List.md) structure, it incorporates its pros (Efficient element rearranging, diverse memory allocation, minimizing unused space) and cons (inefficient sequential access, additional memory consumption), which you have to keep in mind.

---
**Advantages:**
- **Efficient Operations** — due to ordered structure searching space reduces in half at each step, e.g. insertion, deletion, search on average takes $O(logn)$ time and only in some cases when tree is highly disbalanced it can reach $O(n)$.

---
**Disadvantages:**
- **Lack of Balance** — as mentioned earlier, the lack of balance can degrade performance, so to avoid this you should either implement balancing techniques or provide specific input.
- **Handling Duplicates** — also mentioned earlier, handling duplicates can introduce ambiguity and additional complexity, which can affect the design.


# &#128221; Application
**Some of the Most Well-Known Use Cases:**
- **Searching and Retrieval** — BST trees are mainly utilized for effective data retrieval and searchin operations. Their main property is what makes them a well-suited choice for numerous applications.
- **Symbol Tables** — BST trees are used to implement symbol tables to ensure efficient operations. Identifiers such as variables and functions are stored as keys, their associated data or attributes are stored as values, and BSTs allow for quick retrieval based on keys.
- **Database Systems** — BST trees are used in database systems to ensure efficient operations. Just like with symbol tables, BSTs allow to organize records based on keys and perform quick retrieval.
- **Auto-Completing/Checking** — BST trees can be used in various search/checking engines to help make a right decision. Based on the prefix entered, BSTs allow to reduce the space and provide fitting options within entered data.

---
**Common Practical Problems:**
- Find median of BST
- Find the node with minimum value
- Lowest Common Ancestor
- Count of pairs violating BST property
- Balance a BST
- Find the maximum sum leaf to root path
- Find a pair with given sum in a balanced BST
- Merge BSTs to create single BST
- Range sum of BST



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
  - Section 12: Symbol Tables and BSTs
- **"Data Structures and Algorithm Analysis in C++" (4th Edition)** — by Mark Allen Weiss
  - Section 4: Trees
- **"The Algorithm Design Manual" (2nd Edition)** — by Steven S. Skiena
  - Section 3.4: Binary Search Trees
- **"The Art of Computer Programming, Volume 1: Fundamental Algorithms" (3rd Edition)** — by Donald Ervin Knuth
  - Section: 2.3: Trees

---
&#127891; **Courses:**
- [Accelerated Computer Science Fundamentals Specialization](https://www.coursera.org/specializations/cs-fundamentals) on Coursera
  - Section 2.2: Introduction to Tree Strcutures
- [Mastering Data Structures & Algorithms using C and C++](https://www.udemy.com/course/datastructurescncpp/) on Udemy
  - Section 16: Binary Search Trees

---  
&#127760; **Web-Resources:**  
- [Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) (Wikipedia)
- [How to handle duplicates in BST?](https://www.geeksforgeeks.org/how-to-handle-duplicates-in-binary-search-tree/)
- [Balancing a binary search tree](https://appliedgo.net/balancedtree/)
- [Top 50 Binary Search Tree Coding Problems for Interviews](https://www.geeksforgeeks.org/top-50-binary-search-tree-coding-problems-for-interviews/)


# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)