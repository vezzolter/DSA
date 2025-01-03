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

    // --------------------------------
    //  Helper Functions (lack of itr)
    // --------------------------------
    Node* copyNodes(Node* root);
    int heightHelper(Node* root, const int& val) const;
    int depthHelper(Node* root, const int& val, int depth) const;

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

    // ----------------
    //  Element Access
    // ----------------
    bool search(const int& val) const;
    int maximum() const;
    int minimum() const;
    int predecessor(const int& val) const;
    int successor(const int& val) const;

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
};


struct BST::Node {
    int _data;
    Node* _left;
    Node* _right;

    Node(const int& val) : _data(val), _left(nullptr), _right(nullptr) {}
};


#endif // BST_H
