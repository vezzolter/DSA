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
The **Binary Search Tree (BST)** stands out as one of the most common implementation of a binary tree. Its name is derived from one of the main operations performed on it, which is searching for a specific element. This subsection explores BST to establish a solid knowledge of the ideas behind it, as it helps to create elegant and efficient algorithmic designs for all manner of applications.
<p align="center"><img src="./img/BST.png"/></p>

## Essential Terminology
**Binary Search Tree** — is a binary tree, which organizes elements in a sorted manner by following this **property:** for every node, all values in the left subtree are less than the value of the node, and all values in the right subtree are greater than the value of the node.

## Important Details
- **Duplicates** — while some implementations disallow duplicates elements, some allow. The question is how to handle them is up to developer, one common approach can be either to add counter to each node and simply update it, or entirely skip duplicates.
- **Balance** — insertions and deletions can affect the balance of the BST, meaning that the heights of the left and right subtrees of nodes may differ significantly. If that happens tree may still function correctly, but it may exhibit degraded performance (both space and time), especially for large datasets. To prevent this, balancing mechanisms may be employed (e.g. AVL, Red-Black).

## Operation Details
Most operations in BST heavily rely on recursion, although it's possible to implement them using iteration, people generally prefer the first option due to its natural and intuitive approach. To understand them all thoroughly, it's much easier to comprehend the general concepts behind them. This way, understanding how _minimum_ operates will make replicating _maximum_ straightforward. Here are some explanations to functions (probably will be updated in the future to include more):

- **Searching** — this function takes a pointer to the root and the value of the node to search for. If such a node exists, it returns a pointer to it; otherwise, it returns `nullptr`. The typical recursive implementation involves starting the traversal of the tree at the root node and comparing the current node's value to the value being searched for. If the current node's value is equal to the search value, the function returns a pointer to this node. If the current node's value is greater than the search value, the function moves to the left child and repeats the process. Similarly, if the current node's value is less than the search value, the function moves to the right child and repeats the process. If the entire tree has been traversed without finding the search value, the function returns `nullptr`.

- **Removing** — this function takes a pointer to the root and the value of the node to delete. It iterates through the tree, just like previous function and considers 4 basic cases:
  - **Node is Absent** — usually people simply return the function, laying responsibility on the user, but it depends on the implementation.
  - **No Children** — update parent's node respective pointer (left/right child) to `nullptr`, free the memory and optionally handle any metadata logic.
  - **One Child** — redirect parent's node pointer to respective child node (left/right), free the memory and optionally handle any metadata logic.
  - **Two Children** — find successor for node to be deleted, which is smallest node in the right subtree, copy successor's data into deleting node, free the memory of successor, update it's parent's relative pointer and optionally handle any metadata logic.

- **Traversal** — here are several ways to traverse the tree. For this topic, there is a dedicated subsection on Graph & Tree Traversals (the link will be updated in the future).



# &#x1F4BB; Implementation 
Since it's commonly recommended to rely on proven implementations rather than reinventing the wheel, you might think that there must be some well-established and widely recognized containers. The truth is that in the context of C++, people usually refer to [std::map](https://en.cppreference.com/w/cpp/container/map) or [std::set](https://en.cppreference.com/w/cpp/container/set) to fulfill the access characteristics. This happens because people choose containers based on guarantees and not based on how the containers are implemented (even though map and set are usually implemented as Red-Black trees). An alternative to this approach is to use some of the containers from [Boost Graph Library](https://www.boost.org/doc/libs/?view=category_containers). Long story short, there is no container exactly replicating a BST, and there are reasons for this. Therefore, this section explores only a simplified version to gain a deeper understanding of the fundamental concepts underlying this data structure.

## Design Decisions
One significant design decision is the implementation of a container without the iterator class. Generally speaking, most BST functions are supposed to return a pointer to a node. Since the node is a private part of the class, there is no way to store or access this type of node outside the class. In order to allow this behavior, classes have iterator classes, but it slightly adds to the overall complexity and shifts the focus from how operations are done to an additional layer of processing. Therefore, to remove this additional layer, the class primarily operates on the data and some additional functions. Basically, all the ideas behind are the same; once you grasp them (which is much easier directly), you will see that updating the class for iterators is not going to change approaches drastically, but rather the return types and comparing values. (This decision is still under review).



## Detailed Overview
<p align="center"><img src="./img/BSTDemonstration.png"/></p>

Application's control flow and testing of the class is conducted within the [Main.cpp](https://github.com/vezzolter/DSA/blob/main/DataStructures/Tree/BST/src/Main.cpp) file. The `BST` class is declared in [BST.h](https://github.com/vezzolter/DSA/tree/main/DataStructures/Tree/BST/inc) header file and defined in [BST.cpp](https://github.com/vezzolter/DSA/blob/main/DataStructures/Tree/BST/src/BST.cpp) source file. This approach is adopted to ensure encapsulation, modularity, and compilation efficiency, but for your convenience here is the declaration of the class:
```cpp
template <typename T>
class BST {
private:
   struct Node {
       T _data;
        Node* _left;
        Node* _right;
        Node(const T& val) : _data(val), _left(nullptr), _right(nullptr) {}
    };
    Node* _root;
    int _size;
    // Helper functions (due to lack of iterator class)
    Node* copyNodes(Node* root);
    int heightHelper(Node* root, const T& value) const;
    int depthHelper(Node* root, const T& value, int depth) const;

public:
    // Special Member Functions
    BST();
    BST(const BST& rhs);
    BST& operator=(const BST& rhs);
    ~BST();

    // Element Access
    bool search(const T& value) const;
    T maximum() const;
    T minimum() const;
    T predecessor(const T& value) const;
    T successor(const T& value) const;

    // Capacity
    bool empty() const;
    int size() const;
    int height(const T& value) const;
    int depth(const T& value) const;

    // Modifiers
    void insert(const T& value);
    void remove(const T& value);
    void clear();
};
```



# &#128202; Analysis
Understanding how to analyze the particular implementation of a data structure in terms of time and space complexity is crucial for optimizing performance and ensuring efficient resource utilization within the constraints of the given environment. Additionally, knowing the pros and cons of different data structures allows to make informed decisions, helping to choose the most suitable approach for a given problem.

## How to Analyze  
Will be updated in future...


## Advantages
- **Efficient Operations** — due to ordered structure searching space reduces in half at each step, e.g. insertion, deletion, search on average takes $O(logn)$ time and only in some cases when tree is highly disbalanced it can reach $O(n)$.

## Disadvantages
- **Lack of Balance** — as mentioned earlier, the lack of balance can degrade performance, so to avoid this you should either implement balancing techniques or provide specific input.
- **Handling Duplicates** — also mentioned earlier, handling duplicates can introduce ambiguity and additional complexity, which can affect the design.



# &#128221; Application
Understanding some of the most well-known use cases of a data structure is crucial for grasping its practical relevance and potential impact in real-world scenarios. Additionally, familiarizing oneself with common practical problems and practicing their solutions ensures that you remember the essential details and develop a deep, intuitive understanding of the functionality and limitations.

## Some of the Most Well-Known Use Cases
- **Tree Data Structures** — BST trees are used as base for other trees, specifically balanced and string trees. They all use this data structure for its property of maintaining sorted order but modify it for its needs.
- **Subset of Tree Cases** — BST trees also can be modified to fit in numerous other types of [trees'](https://github.com/vezzolter/DSA/blob/bin-tree/DataStructures/Tree/Tree.md) applications, such as file systems, database indexing, networking.

## Common Practical Problems
- [Range Sum of BST](https://leetcode.com/problems/range-sum-of-bst/)
- [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
- [Convert BST to Greater Tree](https://leetcode.com/problems/convert-bst-to-greater-tree/)
- [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
- [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/)
- [Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)
- [Maximum Sum BST in Binary Tree](https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/)


# &#x1F559; Origins
The concept of Binary Search Trees as a data structure is attributed to the work of several computer scientists and mathematicians over the years. This list includes **A.S. Douglas(?)**, **P.F. Windley(?)**, **Andrew Donald Booth**, **Andrew John Theodore Colin** and **Thomas Nathaniel Hibbard**. All of them contributed in some way to the idea of BST around **1959-1962**. Establishing the starting point for the development of new types of trees, such as balanced and string versions.



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
- [On the efficiency of a new method of dictionary construction](https://www.sciencedirect.com/science/article/pii/S0019995860909013)
- [More combinatorial properties of certain trees](http://comjnl.oxfordjournals.org/content/7/4/299.full.pdf)



# &#128271; License
This project is licensed under the MIT License — see the [LICENSE](https://github.com/vezzolter/DSA/blob/main/LICENSE) file for details.

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)