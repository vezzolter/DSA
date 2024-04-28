// Header file for Binary Tree
// by vezzolter
// April 20, 2024

#ifndef BINARY_TREE_H
#define BINARY_TREE_H


template <typename T>
class BinaryTree {
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
    BinaryTree();
    BinaryTree(const BinaryTree& rhs);
    BinaryTree& operator=(const BinaryTree& rhs);
    ~BinaryTree();

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


#include "BinaryTree.cpp"

#endif