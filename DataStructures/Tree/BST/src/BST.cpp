// Source file for Binary Search Tree
// by vezzolter
// April 29, 2024

#ifndef BST_CPP
#define BST_CPP

#include "BST.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
template<typename T>
BST<T>::BST() : _root(nullptr), _size(0) { }

//// Parametrized constructor
//template<class T>
//BST<T>::BST(const std::initializer_list<T>& initList) { }

// Deep copy constructor
template<typename T>
BST<T>::BST(const BST& rhs) {
}

// Deep copy assignment operator
template<class T>
BST<T>& BST<T>::operator=(const BST& rhs) {
}

// Destructor
template<typename T>
BST<T>::~BST() { clear(); }


// --------------
// Element Access
// --------------

// Finds a specific element within the container
template<typename T>
typename BST<T>::Node* BST<T>::search(const T& value) const {
    Node* current = _root;

    while (current != nullptr) {
        if (current->_data == value) {
            return current;
        }
        else if (current->_data > value) {
            current = current->_left;
        }
        else {
            current = current->_right;
        }
    }

    return nullptr;
}

// Finds the maximum element within the container
template<typename T>
typename BST<T>::Node* BST<T>::maximum() const {
}

// Finds the minimum element within the container
template<typename T>
typename BST<T>::Node* BST<T>::minimum() const {
}

//// Finds the predecessor of a given value in the BST
//template<typename T>
//typename BST<T>::Node* BST<T>::predecessor(const T& value) const {
//    Node* current = _root;
//    Node* pred = nullptr;
//
//    while (current != nullptr) {
//        if (current->_data < value) {
//            pred = current;
//            current = current->_right;
//        }
//        else {
//            current = current->_left;
//        }
//    }
//
//    return pred;
//}

// Finds the value of the predecessor of a given value in the BST
template<typename T>
T BST<T>::predecessor(const T& value) const {
    Node* current = _root;
    Node* pred = nullptr;

    while (current != nullptr) {
        if (current->_data < value) {
            pred = current;
            current = current->_right;
        }
        else {
            current = current->_left;
        }
    }

    if (pred != nullptr) {
        return pred->_data;
    }
    else {
        return T(); // 0
    }
}

// Finds the successor of a given value in the BST
template<typename T>
typename BST<T>::Node* BST<T>::successor(const T& value) const {
}


// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool BST<T>::empty() const {
}

// Returns the number of elements in the container
template<typename T>
int BST<T>::size() const {
}

// Returns the number of edges from leaf node to a particular node
template<typename T>
int BST<T>::height() const {
}

// Returns the number of edges from root to a particular node
template<typename T>
int BST<T>::depth() const {
}


// ---------
// Modifiers
// ---------

// Appends specified element to the container based on criteria for every node:
// all values in the left subtree are less than the value of the node,
// and all values in the right subtree are greater than the value of the node
template<typename T>
void BST<T>::insert(const T& value) {
    Node* newNode = new Node(value);

    if (_root == nullptr) {
        _root = newNode;
    }
    else {
        Node* current = _root;
        while (true) {
            if (current->_data > value) {
                if (current->_left == nullptr) {
                    current->_left = newNode;
                    break;
                }
                else {
                    current = current->_left;
                }
            }
            else {
                if (current->_right == nullptr) {
                    current->_right = newNode;
                    break;
                }
                else {
                    current = current->_right;
                }
            }
        }
    }

    _size++;
}

// Removes the particular element of the container
template<typename T>
void BST<T>::remove(const T& value) {
}

//// Erases all elements from the container
//template<typename T>
//void BST<T>::clear() {
//    // Post-order traversal
//    while (_root != nullptr) {
//        Node* current = _root;
//        
//        // Traverse to the leftmost leaf node
//        while (current->_left != nullptr || current->_right != nullptr) {
//            if (current->_left != nullptr) {
//                current = current->_left;
//            }
//            else {
//                current = current->_right;
//            }
//        }
//
//        // Leaf delete directly, internal based on position
//        if (current == _root) {
//            delete _root;
//            _root = nullptr;
//        }
//        else {
//            Node* parent = predecessor(current->_data);
//            
//            // Left or right child
//            if (parent->_left == current) {
//                delete parent->_left;
//                parent->_left = nullptr;
//            }
//            else {
//                delete parent->_right;
//                parent->_right = nullptr;
//            }
//        }
//    }
//
//    _size = 0;
//}

// Erases all elements from the container
template<typename T>
void BST<T>::clear() {
    // Post-order traversal
    while (_root != nullptr) {
        Node* current = _root;

        // Traverse to the leftmost leaf node
        while (current->_left != nullptr || current->_right != nullptr) {
            if (current->_left != nullptr) {
                current = current->_left;
            }
            else {
                current = current->_right;
            }
        }

        // Leaf delete directly, internal based on position
        if (current == _root) {
            delete _root;
            _root = nullptr;
        }
        else {
            // Find the parent of the current node
            T currentData = current->_data;
            Node* parent = nullptr;
            Node* node = _root;
            while (node != nullptr && node->_data != currentData) {
                parent = node;
                if (currentData < node->_data) {
                    node = node->_left;
                }
                else {
                    node = node->_right;
                }
            }

            // Delete the current node based on its position relative to the parent
            if (parent != nullptr) {
                if (parent->_left != nullptr && parent->_left->_data == currentData) {
                    delete parent->_left;
                    parent->_left = nullptr;
                }
                else if (parent->_right != nullptr && parent->_right->_data == currentData) {
                    delete parent->_right;
                    parent->_right = nullptr;
                }
            }
        }
    }

    _size = 0;
}


#endif