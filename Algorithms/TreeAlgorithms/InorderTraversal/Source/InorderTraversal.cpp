// Title:   Source file for Inorder Traversal (Recursive)
// Authors: by vezzolter
// Date:    March 17, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include "InorderTraversal.h"


void inorderTraversal(TreeNode* root) {
	if (!root) { return; }
	inorderTraversal(root->left);
	std::cout << root->val << " ";
	inorderTraversal(root->right);
}

void reversedInorderTraversal(TreeNode* root) {
	if (!root) { return; }
	reversedInorderTraversal(root->right);
	std::cout << root->val << " ";
	reversedInorderTraversal(root->left);
}