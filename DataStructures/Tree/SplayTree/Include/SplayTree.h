// Title:   Header file for Splay Tree
// Authors: by vezzolter
// Date:    April 15, 2025
// ----------------------------------------------------------------------------


#ifndef SPLAYTREE_H
#define SPLAYTREE_H


class SplayTree {
private:
    int _size;
    struct Node;
    Node* _root;

    // -----------------
    //  Utility Methods
    // -----------------
    // Declaration

public:
    // --------------------
    //  Compiler Generated
    // --------------------
    SplayTree();
    SplayTree(const SplayTree& other);
    SplayTree(SplayTree&& other)          = delete;
    SplayTree& operator=(const SplayTree& rhs);
    SplayTree& operator=(SplayTree&& rhs) = delete;
    ~SplayTree();

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
    int height() const;
    int height(const int& val) const;
    int height(const iterator& it) const;
    int depth() const;
    int depth(const int& val) const;
    int depth(const iterator& it) const;

    // -----------
    //  Modifiers
    // -----------
    void insert(const int& val);
    void remove(const int& val);
    void clear();
    void swap(SplayTree& other);
};


struct SplayTree::Node {
public:
    int data;
    Node* parent;
    Node* left;
    Node* right;

    // --------------------
    //  Compiler Generated
    // --------------------
    Node();
    Node(const int& val, Node* parent = nullptr);
    Node(const Node& other)          = delete; // no copying or moving to ensure 
    Node(Node&& other)               = delete; // uniqueness of the node within    
    Node& operator=(const Node& rhs) = delete; // the tree and prevent accidental 
    Node& operator=(Node&& rhs)      = delete; // duplicates or dangling nodes
    ~Node()                          = default;
};


class SplayTree::Iterator {
private:
    friend class SplayTree; // to handle iterator-based methods in SplayTree
    Node* _curr;

    // -----------------
    //  Utility Methods
    // -----------------

    // Find the leftmost node starting from the given node (the smallest)
    static Node* findLeftmost(Node* node) {
        // Implementation
    }

    // Find the next node of the given node (in-order successor)
    static Node* findNext(Node* node) {
        // Implementation
    }

public:
    // --------------------
    //  Compiler Generated
    // --------------------
    Iterator();
    explicit Iterator(Node* node);
    Iterator(const Iterator& other)          = default;
    Iterator(Iterator&& other)               = default;
    Iterator& operator=(const Iterator& rhs) = default;
    Iterator& operator=(Iterator&& rhs)      = default;
    ~Iterator()                              = default;

    // ----------------------
    //  Overloaded Operators
    // ----------------------

    // Returns a reference to the data of the current node
    int& operator*() {
        // Implementation
    }

    // Advances the iterator to the next element in in-order traversal (pre-increment)
    Iterator& operator++() {
        // Implementation
    }

    // Advances the iterator to the next element, returning the previous state (post-increment)
    Iterator operator++(int) {
        // Implementation
    }

    // Returns true if two iterators point to the same node
    friend bool operator==(const SplayTree::Iterator& lhs, const SplayTree::Iterator& rhs) {
        // Implementation
    }

    // Returns true if two iterators point to different nodes
    friend bool operator!=(const SplayTree::Iterator& lhs, const SplayTree::Iterator& rhs) {
        // Implementation
    }
};


class SplayTree::ConstIterator {
private:
    friend class SplayTree; // to handle iterator-based methods in SplayTree
    const Node* _curr;

    // -----------------
    //  Utility Methods
    // -----------------

    // Find the leftmost node starting from the given node (the smallest)
    static const Node* findLeftmost(Node* node) {
        // Implementation
    }

    // Find the next node of the given node (in-order successor)
    static const Node* findNext(const Node* node) {
        // Implementation
    }

public:
    // --------------------
    //  Compiler Generated
    // --------------------
    ConstIterator();
    ConstIterator(const Node* node);
    ConstIterator(const ConstIterator& other)          = default;
    ConstIterator(ConstIterator&& other)               = default;
    ConstIterator& operator=(const ConstIterator& rhs) = default;
    ConstIterator& operator=(ConstIterator&& rhs)      = default;
    ~ConstIterator()                                   = default;

    // ----------------------
    //  Overloaded Operators
    // ----------------------

    // Returns a const reference to the data of the current node
    const int& operator*() const {
        // Implementation
    }

    // Advances the iterator to the next element in in-order traversal (pre-increment)
    ConstIterator& operator++() {
        // Implementation
    }

    // Advances the iterator to the next element, returning the previous state (post-increment)
    ConstIterator operator++(int) {
        // Implementation
    }

    // Returns true if two iterators point to the same node
    friend bool operator==(const SplayTree::ConstIterator& lhs, const SplayTree::ConstIterator& rhs) {
        // Implementation
    }

    // Returns true if two iterators point to different nodes
    friend bool operator!=(const SplayTree::ConstIterator& lhs, const SplayTree::ConstIterator& rhs) {
        // Implementation
    }
};


#endif // SPLAYTREE_H