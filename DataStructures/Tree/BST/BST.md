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
- `find(val)` — returns a pointer or iterator to the node containing the specified value.
  - returns `nullptr` or equivalent, if the value is not found.
- `min()` — returns an iterator to the node with the smallest value in the tree.
  - returns `nullptr` or equivalent, if the tree is empty.
- `max()` — returns an iterator to the node with the largest value in the tree.
  - returns `nullptr` or equivalent, if the tree is empty.
- `successor(val)` — returns a pointer or iterator to the node with the smallest value greater than the specified value (in-order successor).
   - returns `nullptr` or equivalent, if specified value has no successor (e.g. the largest value, sole value).
- `predecessor(val)` — returns a pointer or iterator to the node with the largest value smaller than the specified value (in-order predecessor).
  - returns `nullptr` or equivalent, if specified value has no predecessor (e.g. the largest value, sole value).

---
**Capacity**:
- `empty()` — returns `true` if the tree contains no nodes; otherwise `false`.
- `size()` — returns the total number of nodes in the tree.
- `maxSize()` — returns the theoretical maximum number of nodes the tree can hold, depending on memory limits.
  - return value depends on platform architecture and the size of the node structure.
- `height(val)` — returns the height of the given's value node, which is the length (number of edges) of the longest path from the node to a leaf.
  - if the value is not found in the tree, it returns `-1`;
  - the height of a leaf node is `0`.
- `depth(val)` — returns the depth of the given's value node, which is the length (number of edges) of the path from the root to the node.
  - if the value is not found in the tree, it returns `-1`;
  - the depth of the root node is `0`.

---
<p align="center"><img src="./Images/OperationsModifiers.png"/></p>

**Modifiers**:
- `insert(val)` — inserts a new node with the specified value into the tree, maintaining the BST ordering property.
- `erase(val)` — removes the node with the specified value from the tree, adjusting the structure as needed to maintain the ordering property.
  - if the node has no children (leaf), simply remove node;
  - if the node has one child, replace the node with its child;
  - if the node has two children, it is replaced with its in-order successor or predecessor, depending on the design decision.
- `clear()` — removes all nodes from the tree,  resetting it to its initial state.
- `swap(other)` — exchanges the contents of the current tree with another tree, avoiding expensive deep copies.
  - assigning a tree to itself has no effect, as the function exits early without performing any operations.



# &#x1F4BB; Implementation 
The implemented console application demonstrates the basic functionality of the BST by performing various operations and interactions with it. The program provides a clear view of changes made during usage, displaying the state of the data at different stages to illustrate its simplified behavior and characteristics.
<p align="center"><img src="./Images/Demonstration.png"/></p>


## Design Decisions
Currently in Progress...


## Container Implementation
The container is implemented within the `BST` class, which is declared in [BST.h](https://github.com/vezzolter/DSA/blob/bst/DataStructures/Tree/BST/Include/BST.h) header file and defined in [BST.cpp](https://github.com/vezzolter/DSA/blob/bst/DataStructures/Tree/BST/Source/BST.cpp) source file. This approach is adopted to ensure encapsulation, modularity and compilation efficiency. To see the container's functionality in action, you can examine the `main()` function located in the [Main.cpp](https://github.com/vezzolter/DSA/blob/bst/DataStructures/Tree/BST/Source/Main.cpp) file. The full implementation can be found in the corresponding files, while the class declaration below offers a quick overview:

```cpp
class BST {
private:
    int _size;
    struct Node;
    Node* _root;

    // -----------------
    //  Utility Methods
    // -----------------

    // For self-balancing trees, the copy constructor and copy assignment operator
    // often rely on iterators, because insertions automatically balance the tree,
    // but for BST, balancing isn't a concern, so it would add unnecessary complexity
    Node* copyNodes(Node* src, Node* parent);
    Node* findLeftmost(Node* node) const;

public:
    // --------------------
    //  Compiler Generated
    // --------------------
    BST();
    BST(const BST& other);
    BST(BST&& other)          = delete;
    BST& operator=(const BST& rhs);
    BST& operator=(BST&& rhs) = delete;
    ~BST();

    // -----------
    //  Iterators
    // -----------
    class Iterator;
    using iterator = Iterator;
    iterator begin();
    iterator end();
    class ConstIterator;
    using const_iterator = ConstIterator;
    const_iterator begin() const;
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;

    // ----------------
    //  Element Access
    // ----------------
    iterator find(const int& val);
    const_iterator find(const int& val) const;
    iterator predecessor(const int& val);
    const_iterator predecessor(const int& val) const;
    iterator successor(const int& val);
    const_iterator successor(const int& val) const;
    iterator predecessor(const iterator& it);
    const_iterator predecessor(iterator& it) const;
    iterator successor(const iterator& it);
    const_iterator successor(iterator& it) const;
    int minimum() const;
    int maximum() const;

    // ----------
    //  Capacity
    // ----------
    bool empty() const;
    int size() const;
    int height(const int& val) const;
    int depth(const int& val) const;

    // -----------
    //  Modifiers
    // -----------
    void insert(const int& val);
    void remove(const int& val);
    void clear();
    void swap(BST& other);
};
```


## Node Implementation
The `Node` structure is defined as a private nested structure within the `BST` container. This design keeps `Node` as an internal component, accessible only within the container, and enhances encapsulation. Given the simplicity of the `Node` structure, its functions are defined inline within the container's header file.

```cpp
struct BST::Node {
public:
    int _data;
    Node* _parent;
    Node* _left;
    Node* _right;

    // --------------------
    //  Compiler Generated
    // --------------------
    Node() : _data(0), _parent(nullptr), _left(nullptr), _right(nullptr) {}
    Node(const int& val, Node* parent = nullptr)
        : _data(val), _parent(parent), _left(nullptr), _right(nullptr) {}
    Node(const Node& other)          = delete;  // no copying or moving to ensure 
    Node(Node&& other)               = delete;  // uniqueness of the node within    
    Node& operator=(const Node& rhs) = delete;  // the tree and prevent accidental 
    Node& operator=(Node&& rhs)      = delete;  // duplicates or dangling nodes
    ~Node()                          = default; 
};
```


## Iterator Implementation
Since there are various types of iterators that can be implemented (e.g. forward, const forward, reverse, const reverse), it's common practice to define them in separate classes and files. However, despite being implemented separately, their underlying principles are usually similar, with only slight adjustments for specific purposes. To keep things simpler and avoid cluttering the core concepts, this container implements regular and constant iterator classes. Those iterators cover the basic $[begin, end)$ range and demonstrates how typical iterators operations are handled, as well as how the iterators classes are integrated into the BST container.

---
The `Iterator` class is defined as a public nested class within the `BST` container. This design makes `Iterator` accessible to users, enabling them to traverse and interact with list elements directly. Given the simplicity of the `Iterator` class, its functions are defined inline within the container's header file.

```cpp

class BST::Iterator {
private:
    friend class BST; // So that itr-based element access fcn would work
    Node* _curr;
    const BST* _tree; // Eases some operations (traversing, reversing, sentinel, caching, etc)

    // -----------------
    //  Utility Methods
    // -----------------

    // Find the leftmost node starting from the given node (begin/smallest)
    Node* findLeftmost(Node* node) const { return _tree->findLeftmost(node); }

    // Find the next node of the given node (in-order successor)
    Node* findNext(Node* node) const {
        // Case: empty node
        if (!node) { return nullptr; }

        // Case: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
        if (node->_right) { return findLeftmost(node->_right); }

        // Case: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
        Node* parent = node->_parent;
        for (; parent && node == parent->_right; ) {
            node = parent;
            parent = parent->_parent;
        }
        return parent;
    }

public:
    // --------------------
    //  Compiler Generated
    // --------------------
    Iterator() : _curr(nullptr), _tree(nullptr) {}
    Iterator(Node* node, const BST* tree) : _curr(node), _tree(tree) {}
    Iterator(const Iterator& other)          = default;
    Iterator(Iterator&& other)               = default;
    Iterator& operator=(const Iterator& rhs) = default;
    Iterator& operator=(Iterator&& rhs)      = default;
    ~Iterator()                              = default;

    // ----------------------
    //  Overloaded Operators
    // ----------------------

    // Returns a reference to the data of the current node
    int& operator*() { return _curr->_data; }

    // Advances the iterator to the next element in in-order traversal (pre-increment)
    Iterator& operator++() {
        _curr = findNext(_curr);
        return *this;
    }

    // Advances the iterator to the next element, returning the previous state (post-increment)
    Iterator operator++(int) {
        Iterator temp(_curr, _tree);
        _curr = findNext(_curr);
        return temp;
    }

    // Returns true if two iterators point to the same node
    friend bool operator==(const BST::Iterator& lhs, const BST::Iterator& rhs) {
        return lhs._curr == rhs._curr;
    }

    // Returns true if two iterators point to different nodes
    friend bool operator!=(const BST::Iterator& lhs, const BST::Iterator& rhs) {
        return lhs._curr != rhs._curr;
    }
};
```

---
The `ConstIterator` class is defined as a public nested class within the `BST` container. This design makes `ConstIterator` accessible to users, enabling them to traverse and interact with list elements directly. Given the simplicity of the `ConstIterator` class, its functions are defined inline within the container's header file.

```cpp
class BST::ConstIterator {
private:
    friend class BST; // So that itr-based element access fcn would work
    const Node* _curr;
    const BST* _tree; // Eases some operations (traversing, reversing, sentinel, caching, etc)

    // -----------------
    //  Utility Methods
    // -----------------

    // Find the leftmost node starting from the given node (begin/smallest)
    const Node* findLeftmost(Node* node) const { return _tree->findLeftmost(node); }

    // Find the next node of the given node (in-order successor)
    const Node* findNext(const Node* node) const {
        // Case: empty node
        if (!node) { return nullptr; }

        // Case: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
        if (node->_right) { return findLeftmost(node->_right); }

        // Case: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
        const Node* parent = node->_parent;
        for (; parent && node == parent->_right; ) {
            node = parent;
            parent = parent->_parent;
        }
        return parent;
    }

public:
    // --------------------
    //  Compiler Generated
    // --------------------

    ConstIterator() : _curr(nullptr), _tree(nullptr) {}
    ConstIterator(const Node* node, const BST* tree) : _curr(node), _tree(tree) {}
    ConstIterator(const ConstIterator& other)          = default;
    ConstIterator(ConstIterator&& other)               = default;
    ConstIterator& operator=(const ConstIterator& rhs) = default;
    ConstIterator& operator=(ConstIterator&& rhs)      = default;
    ~ConstIterator()                                   = default;

    // ----------------------
    //  Overloaded Operators
    // ----------------------

    // Returns a const reference to the data of the current node
    const int& operator*() const { return _curr->_data; }

    // Advances the iterator to the next element in in-order traversal (pre-increment)
    ConstIterator& operator++() {
        _curr = findNext(_curr);
        return *this;
    }

    // Advances the iterator to the next element, returning the previous state (post-increment)
    ConstIterator operator++(int) {
        ConstIterator temp = *this;
        _curr = findNext(_curr);
        return temp;
    }

    // Returns true if two iterators point to the same node
    friend bool operator==(const BST::ConstIterator& lhs, const BST::ConstIterator& rhs) {
        return lhs._curr == rhs._curr;
    }

    // Returns true if two iterators point to different nodes
    friend bool operator!=(const BST::ConstIterator& lhs, const BST::ConstIterator& rhs) {
        return lhs._curr != rhs._curr;
    }
};
```


# &#128202; Analysis
Currently in Progress...


## Characteristics 
Currently in Progress...


## Trade-Offs
Currently in Progress...



# &#128221; Application
Currently in Progress...


## Common Use Cases
- **Efficient Searching** — BSTs are used for searching elements efficiently, as they maintain a hierarchical ordering of data. In a well-structured BST, searches can be performed in $O(\log n)$ time on average, leveraging the ordering property to reduce comparisons.

- **Data Sorting** — BSTs are utilized for sorting data dynamically through their in-order traversal. This traversal produces a sorted sequence of elements, leveraging the hierarchical structure of the tree to organize data efficiently.

- **Range Queries** — BSTs are applied to retrieve all elements within a specific range of values. By traversing only the relevant portions of the tree, range queries efficiently access the data while maintaining the overall structure.

- **Educational Purposes** — BSTs are frequently used in education to demonstrate core concepts in data structures. Their simplicity helps in understanding recursion, tree traversals, and hierarchical ordering of data, also they serve as a starting point for understanding how balancing affects performance.


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