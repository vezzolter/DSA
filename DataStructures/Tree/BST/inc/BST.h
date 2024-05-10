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


#include "BST.cpp"

#endif
