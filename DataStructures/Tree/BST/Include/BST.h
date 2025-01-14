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
    //class Iterator;
    //using iterator = Iterator;
    //iterator begin();
    //iterator end();
    //class ConstIterator;
    //using const_iterator = ConstIterator;
    //const_iterator begin() const;
    //const_iterator end() const;
    //const_iterator cbegin() const;
    //const_iterator cend() const;

    // ----------------
    //  Element Access
    // ----------------
    //iterator find(const int& val);
    //const_iterator find(const int& val) const;
    //int maximum() const;
    //int minimum() const;
    //iterator predecessor(const int& val);
    //const_iterator predecessor(const int& val) const;
    //iterator successor(const int& val);
    //const_iterator successor(const int& val) const;

    // ----------
    //  Capacity
    // ----------
    //bool empty() const;
    //int size() const;
    //int height(const int& val) const;
    //int depth(const int& val) const;

    // -----------
    //  Modifiers
    // -----------
    //void insert(const int& val);
    //void remove(const int& val);
    void clear();
    //void swap(BST& other);

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
    int _count; // duplicate handling
    Node* _parent;
    Node* _left;
    Node* _right;

    // --------------------
    //  Compiler Generated
    // --------------------
    Node() : _data(0), _count(0), _parent(nullptr), _left(nullptr), _right(nullptr) {}
    Node(const int& val, Node* parent = nullptr)
        : _data(val), _count(1), _left(nullptr), _right(nullptr) {}
    Node(const Node& other)          = delete;  // no copying or moving to ensure 
    Node(Node&& other)               = delete;  // uniqueness of the node within    
    Node& operator=(const Node& rhs) = delete;  // the tree and prevent accidental 
    Node& operator=(Node&& rhs)      = delete;  // duplicates or dangling nodes
    ~Node()                          = default; 

    // -----------------
    //  Utility Methods
    // -----------------
    
    // Description
    //bool isLeaf() const;

    // Description
    //bool hasSignleChild() const;
};


//class BST::Iterator {
//private:
//
//public:
//    // --------------------
//    //  Compiler Generated
//    // --------------------
//    Iterator()                               = default;
//    //Iterator(char* ptr) : _ptr(ptr) { }
//    Iterator(const Iterator& other)          = default;
//    Iterator(Iterator&& other)               = default;
//    Iterator& operator=(const Iterator& rhs) = default;
//    Iterator& operator=(Iterator&& rhs)      = default;
//    ~Iterator()                              = default;
//
//    // ----------------------
//    //  Overloaded Operators
//    // ----------------------
//};


//class BST::ConstIterator {
//private:
//    const char* _ptr = nullptr;
//
//public:
//    // --------------------
//    //  Compiler Generated
//    // --------------------
//    ConstIterator()                  = default;
//    //ConstIterator(const char* ptr) : _ptr(ptr) { }
//    ConstIterator(const ConstIterator& other)          = default;
//    ConstIterator(ConstIterator&& other)               = default;
//    ConstIterator& operator=(const ConstIterator& rhs) = default;
//    ConstIterator& operator=(ConstIterator&& rhs)      = default;
//    ~ConstIterator();
//};


#endif // BST_H
