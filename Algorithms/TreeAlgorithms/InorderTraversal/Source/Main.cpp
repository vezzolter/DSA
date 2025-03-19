// Title:   Inorder Traversal Algorithm (Recursive)
// Authors: by vezzolter
// Date:    March 17, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include "InorderTraversal.h"


int main() {
	// Greet
	std::cout << "\tWelcome to the 'Inorder Traversal (Recursive)' console application!\n";

	// Manually construct BST
    TreeNode* root = new TreeNode(8);         // level 0
    root->left = new TreeNode(4);             // level 1
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(2);       // level 2
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(17);
    root->left->left->left = new TreeNode(0); // level 3
    root->left->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(7);
    root->right->left->left = new TreeNode(9);
    root->right->left->right = new TreeNode(11);
    root->right->right->left = new TreeNode(14);
    std::cout << "\nInput Tree:\t\t\t\t8 4 13 2 6 10 17 0 3 7 9 11 14" << std::endl;

    // Test standard version
    std::cout << "Inorder Traversal:\t\t\t";
    inorderTraversal(root);
    std::cout << std::endl;

    // Test reversed version
    std::cout << "Reversed Traversal:\t\t\t";
    reversedInorderTraversal(root);
    std::cout << std::endl;

    // Manually lean up memory
    delete root->left->left->left;  // left subtree
    delete root->left->left->right;
    delete root->left->left;
    delete root->left->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right->left->left; // right subtree
    delete root->right->left->right;
    delete root->right->left;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right;
    delete root;                    // root

	// Exit
	std::cout << "\nThanks for using this program! Have a great day!\n";
	std::cout << "Press <Enter> to exit...";
	std::cin.get();
	return 0;
}