// Title:   Header file for BST
// Authors: by vezzolter
// Date:    April 29, 2024
// ----------------------------------------------------------------------------


#ifndef BST_H
#define BST_H


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

    // ------------
    //  Operations
    // ------------
    // void traverse();
    // bool contains(const int& val) const;
    // void validate() const;
    // int count(const int& val) const;
};


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


class BST::Iterator {
private:
    friend class BST; // so that itr-based element access fcn would work
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


class BST::ConstIterator {
private:
    friend class BST; // so that itr-based element access fcn would work
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


#endif // BST_H
