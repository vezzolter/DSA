// Header file for Binary Search Tree
// by vezzolter
// April 29, 2024

#ifndef BST_H
#define BST_H


template <typename T>
class BST {
private:
    struct Node {
        T _data;
        Node* _left;
        Node* _right;

        Node(const T& val) : _data(val), _left(nullptr), _right(nullptr) {}
    };

    Node* root;

public:
    // Special Member Functions
    BST();
    BST(const BST& rhs);
    BST& operator=(const BST& rhs);
    ~BST();

    // Capacity
    bool empty() const;
    int size() const;
    bool contains(const T& value) const;
    int height() const;
    int depth() const;


    // Modifiers
    void insert(const T& value);
    void remove(const T& value);
    void clear();
};


#include "BST.cpp"

#endif
