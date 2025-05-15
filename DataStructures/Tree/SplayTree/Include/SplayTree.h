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
    Node* copySubtree(Node* src, Node* parent);
    void destroySubtree(Node* src);
    Node* findLeftmost(Node* node) const;
    Node* findRightmost(Node* node) const;
    int computeHeight(Node* node) const;
    int computeDepth(Node* node) const;
    void rightRotate(Node* node);
    void leftRotate(Node* node);
    void splay(Node* x);


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
    iterator predecessor(const int& val);
    iterator predecessor(iterator& it);
    iterator successor(const int& val);
    iterator successor(iterator& it);
    iterator minimum();
    iterator maximum();

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
    void remove(iterator pos);
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
    Node() : data(0), parent(nullptr), left(nullptr), right(nullptr) {}
    Node(const int& val, Node* parent = nullptr) : data(val), parent(parent), left(nullptr), right(nullptr) {};
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
        for (; node && node->left; ) { node = node->left; }
        return node;
    }

    // Find the next node of the given node (in-order successor)
    static Node* findNext(Node* node) {
        if (!node) { return nullptr; }

        // Case 1: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
        if (node->right) { return findLeftmost(node->right); }

        // Case 2: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
        Node* parent = node->parent;
        for (; parent && node == parent->right; ) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }

public:
    // --------------------
    //  Compiler Generated
    // --------------------
    Iterator() : _curr(nullptr) {}
    explicit Iterator(Node* node) : _curr(node) {} // prevents from 'node' to 'itr'
    Iterator(const Iterator& other)          = default;
    Iterator(Iterator&& other)               = default;
    Iterator& operator=(const Iterator& rhs) = default;
    Iterator& operator=(Iterator&& rhs)      = default;
    ~Iterator()                              = default;

    // ----------------------
    //  Overloaded Operators
    // ----------------------

    // Returns a CONST reference to the data of the current node
    const int& operator*() {
        return _curr->data;
    }

    // Advances the iterator to the next element in in-order traversal (pre-increment)
    Iterator& operator++() {
        _curr = findNext(_curr);
        return *this;
    }

    // Advances the iterator to the next element, returning the previous state (post-increment)
    Iterator operator++(int) {
        Iterator temp(_curr);
        _curr = findNext(_curr);
        return temp;
    }

    // Returns true if two iterators point to the same node
    friend bool operator==(const SplayTree::Iterator& lhs, const SplayTree::Iterator& rhs) {
        return lhs._curr == rhs._curr;
    }

    // Returns true if two iterators point to different nodes
    friend bool operator!=(const SplayTree::Iterator& lhs, const SplayTree::Iterator& rhs) {
        return lhs._curr != rhs._curr;
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
        for (; node && node->left; ) { node = node->left; }
        return node;
    }

    // Find the next node of the given node (in-order successor)
    static const Node* findNext(const Node* node) {
        if (!node) { return nullptr; }

        // Case 1: if the 'given' has a right subtree, 'next' is the leftmost node in that subtree
        if (node->right) { return findLeftmost(node->right); }

        // Case 2: otherwise 'next' is the first parent node, where the 'given' is in the left subtree
        const Node* parent = node->parent;
        for (; parent && node == parent->right; ) {
            node = parent;
            parent = parent->parent;
        }
        return parent;
    }

public:
    // --------------------
    //  Compiler Generated
    // --------------------
    ConstIterator() : _curr(nullptr) {}
    explicit ConstIterator(const Node* node) : _curr(node) {} // prevents from 'node' to 'itr'
    ConstIterator(const Iterator& other) : _curr(other._curr) {} // allows from 'regular_itr' to 'const_itr'
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
        return _curr->data;
    }

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
    friend bool operator==(const SplayTree::ConstIterator& lhs, const SplayTree::ConstIterator& rhs) {
        return lhs._curr == rhs._curr;
    }

    // Returns true if two iterators point to different nodes
    friend bool operator!=(const SplayTree::ConstIterator& lhs, const SplayTree::ConstIterator& rhs) {
        return lhs._curr != rhs._curr;
    }
};


#endif // SPLAYTREE_H