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
BST<T>::BST() {
}

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
BST<T>::~BST() {
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

// Checks if the specified element is present in container
template<typename T>
bool BST<T>::contains(const T& value) const {
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

// Appends specified element to the container based on criteria
// Criteria: undecieded right now
template<typename T>
void BST<T>::insert(const T& value) {
}

// Removes the particular element of the container
template<typename T>
void BST<T>::remove(const T& value) {
}

// Erases all elements from the container
template<typename T>
void BST<T>::clear() {
}


#endif