// Source file for simplified ADT: Stack
// by vezzolter
// March 2, 2024

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"


// ------------------------
// Special Member Functions
// ------------------------

// Default constructor
template<typename T>
Stack<T>::Stack();

// Deep copy constructor
template<class T>
Stack<T>::Stack(const Stack& rhs);

// Deep copy assignment operator
template<class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs);

// Destructor
template<typename T>
Stack<T>::~Stack();



// --------------
// Element Access
// --------------

// Accesses the last element in the container, no range validation, allows modification
template<class T>
T& Stack<T>::top();

// Accesses the last element in the container, no range validation, denies modification
template<class T>
const T& Stack<T>::top() const;



// --------
// Capacity
// --------

// Checks if the container has no elements
template<class T>
bool Stack<T>::empty() const { return _size == 0; }

// Returns the number of elements in the container
template<typename T>
int Stack<T>::size() const { return _size; }



// ---------
// Modifiers
// ---------

// Appends the given element to the end of the container
template<class T>
void Stack<T>::push(const T& newData);

// Removes the last element of the container
// Note: with no bounds check, assumes that stack contains at least 1 element
template<class T>
void Stack<T>::pop();


#endif