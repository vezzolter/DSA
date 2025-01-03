// Title:   Source file for BST
// Authors: by vezzolter
// Date:    April 29, 2024
// ----------------------------------------------------------------------------


#include "BST.h"


// --------------------------------
//  Helper Functions (lack of itr)
// --------------------------------

// Helper function to recursively copy nodes
typename BST::Node* BST::copyNodes(Node* src) {
    if (src == nullptr) { return nullptr; }
    Node* newNode = new Node(src->_data);
    newNode->_left = copyNodes(src->_left);
    newNode->_right = copyNodes(src->_right);
    return newNode;
}

// Helper function to calculate the height
int BST::heightHelper(Node* root, const int& val) const {
    if (root == nullptr) { return -1; } // Height of an empty subtree is -1

    if (val < root->_data) {
        return 1 + heightHelper(root->_left, val);

    } else if (val > root->_data) {
        return 1 + heightHelper(root->_right, val);

    } else {
        auto maxHeight = [](int leftHeight, int rightHeight) {
            return leftHeight > rightHeight ? leftHeight : rightHeight;
        };
        return maxHeight(heightHelper(root->_left, val), heightHelper(root->_right, val)) + 1;
    }
}

// Helper function to calculate the depth
int BST::depthHelper(Node* root, const int& val, int depth) const {
    if (root == nullptr) { return -1; } // Node not found, return -1

    if (root->_data == val) {
        return depth;

    } else if (val < root->_data) {
        return depthHelper(root->_left, val, depth + 1);

    } else {
        return depthHelper(root->_right, val, depth + 1);
    }
}


// --------------------
//  Compiler Generated
// --------------------

// Default constructor
BST::BST() : _root(nullptr), _size(0) { }

//// Parametrized constructor
//BST::BST(const std::initializer_list<int>& initList) { }

// Deep copy constructor
BST::BST(const BST& rhs) : _root(nullptr), _size(rhs._size) {
    _root = copyNodes(rhs._root);
}

// Deep copy assignment operator
BST& BST::operator=(const BST& rhs) {
    if (this != &rhs) {
        clear(); // prevent existing values
        _root = copyNodes(rhs._root);
        _size = rhs._size;
    }
    return *this;
}

// Destructor
BST::~BST() { clear(); }


// ----------------
//  Element Access 
// ----------------

// Checks if a specific element is present within the container
bool BST::search(const int& val) const {
    Node* current = _root;

    for (; current != nullptr; ) {
        if (current->_data == val) {
            return true;

        } else if (current->_data > val) {
            current = current->_left;

        } else {
            current = current->_right;
        }
    }

    return false;
}

// Finds the value of maximum element within the container
int BST::maximum() const {
    if (_root == nullptr) { return 0; }

    Node* current = _root;
    for (; current->_right != nullptr; ) { current = current->_right; }

    return current->_data; 
}

// Finds the value of minimum element within the container
int BST::minimum() const {
    if (_root == nullptr) { return 0; }

    Node* current = _root;
    for (; current->_left != nullptr; ) { current = current->_left; }

    return current->_data;
}

// Finds the value of predecessor for a given value
int BST::predecessor(const int& val) const {
    Node* current = _root;
    Node* pred = nullptr;

    for (; current != nullptr; ) {
        if (current->_data < val) {
            pred = current;
            current = current->_right;

        } else {
            current = current->_left;
        }
    }

    if (pred != nullptr) {
        return pred->_data;

    } else {
        return 0;
    }
}

// Finds the value of successor for a given value
int BST::successor(const int& val) const {
    Node* current = _root;
    Node* succ = nullptr;

    for (; current != nullptr; ) {
        if (current->_data > val) {
            succ = current;
            current = current->_left;

        } else {
            current = current->_right;
        }
    }

    if (succ != nullptr) {
        return succ->_data;

    } else {
        return 0;
    }
}


// ----------
//  Capacity
// ----------

// Checks if the container has no elements
bool BST::empty() const { return _root == nullptr; }

// Returns the number of elements in the container
int BST::size() const { return _size; }

// Returns the number of edges from leaf node to a particular node
int BST::height(const int& val) const { return heightHelper(_root, val); }

// Returns the number of edges from root to a particular node
int BST::depth(const int& val) const { return depthHelper(_root, val, 0); }


// -----------
//  Modifiers
// -----------

// Appends specified element to the container based on criteria for every node:
// all values in the left subtree are less than the value of the node,
// and all values in the right subtree are greater than the value of the node
void BST::insert(const int& val) {
    Node* newNode = new Node(val);

    if (_root == nullptr) {
        _root = newNode;

    } else {
        Node* current = _root;
        for (; ;) {
            if (current->_data > val) {
                if (current->_left == nullptr) {
                    current->_left = newNode;
                    break;

                } else {
                    current = current->_left;
                }

            } else {
                if (current->_right == nullptr) {
                    current->_right = newNode;
                    break;

                } else {
                    current = current->_right;
                }
            }
        }
    }

    _size++;
}

// Removes the particular element of the container
void BST::remove(const int& val) {
    Node* parent = nullptr;
    Node* current = _root;

    // Search for the node with the given value (instead of iterator)
    for (; current != nullptr && current->_data != val; ) {
        parent = current;
        if (val < current->_data) {
            current = current->_left;

        } else {
            current = current->_right;
        }
    }

    // If the value is not found, return
    if (current == nullptr) { return; }

    // Case 1: Node to be deleted has no children (leaf node)
    if (current->_left == nullptr && current->_right == nullptr) {
        if (parent == nullptr) {
            _root = nullptr;

        } else if (parent->_left == current) {
            parent->_left = nullptr;

        } else {
            parent->_right = nullptr;
        }

        delete current;
        _size--;

    // Case 2: Node to be deleted has one child
    } else if (current->_left == nullptr) {
        if (parent == nullptr) {
            _root = current->_right;

        } else if (parent->_left == current) {
            parent->_left = current->_right;

        } else {
            parent->_right = current->_right;
        }

        delete current;
        _size--;
    
    } else if (current->_right == nullptr) {
        if (parent == nullptr) {
            _root = current->_left;

        } else if (parent->_left == current) {
            parent->_left = current->_left;

        } else {
            parent->_right = current->_left;
        }

        delete current;
        _size--;

    // Case 3: Node to be deleted has two children
    } else {
        Node* successorParent = current;
        Node* successor = current->_right;
        for (; successor->_left != nullptr; ) {
            successorParent = successor;
            successor = successor->_left;
        }
        current->_data = successor->_data;
        if (successorParent->_left == successor) {
            successorParent->_left = successor->_right;

        } else {
            successorParent->_right = successor->_right;
        }

        delete successor;
        _size--;
    }
}

// Erases all elements from the container
void BST::clear() {
    // Post-order traversal
    for (; _root != nullptr; ) {
        Node* current = _root;

        // Traverse to the leftmost leaf node
        for (; current->_left != nullptr || current->_right != nullptr; ) {
            if (current->_left != nullptr) {
                current = current->_left;

            } else {
                current = current->_right;
            }
        }

        // Leaf delete directly, internal based on position
        if (current == _root) {
            delete _root;
            _root = nullptr;

        } else {
            // Find the parent of the current node
            int currentData = current->_data;
            Node* parent = nullptr;
            Node* node = _root;
            for (; node != nullptr && node->_data != currentData; ) {
                parent = node;
                if (currentData < node->_data) {
                    node = node->_left;

                } else {
                    node = node->_right;
                }
            }

            // Delete the current node based on its position relative to the parent
            if (parent != nullptr) {
                if (parent->_left != nullptr && parent->_left->_data == currentData) {
                    delete parent->_left;
                    parent->_left = nullptr;

                } else if (parent->_right != nullptr && parent->_right->_data == currentData) {
                    delete parent->_right;
                    parent->_right = nullptr;
                }
            }
        }
    }

    _size = 0;
}