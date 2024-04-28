// Source file for Binary Tree
// by vezzolter
// April 20, 2024

#ifndef BINARY_TREE_CPP
#define BINARY_TREE_CPP

#include "BinaryTree.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
template<typename T>
BinaryTree<T>::BinaryTree() {
}

//// Parametrized constructor
//template<class T>
//BinaryTree<T>::BinaryTree(const std::initializer_list<T>& initList) { }

// Deep copy constructor
template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& rhs) {
}

// Deep copy assignment operator
template<class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& rhs) {
}

// Destructor
template<typename T>
BinaryTree<T>::~BinaryTree() {
}


// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool BinaryTree<T>::empty() const {
}

// Returns the number of elements in the container
template<typename T>
int BinaryTree<T>::size() const {
}

// Checks if the specified element is present in container
template<typename T>
bool BinaryTree<T>::contains(const T& value) const {
}

// Returns the number of edges from leaf node to a particular node
template<typename T>
int BinaryTree<T>::height() const {
}

// Returns the number of edges from root to a particular node
template<typename T>
int BinaryTree<T>::depth() const {
}


// ---------
// Modifiers
// ---------

// Appends specified element to the container based on criteria
// Criteria: undecieded right now
template<typename T>
void BinaryTree<T>::insert(const T& value) {
}

// Removes the particular element of the container
template<typename T>
void BinaryTree<T>::remove(const T& value) {
}

// Erases all elements from the container
template<typename T>
void BinaryTree<T>::clear() {
}


#endif