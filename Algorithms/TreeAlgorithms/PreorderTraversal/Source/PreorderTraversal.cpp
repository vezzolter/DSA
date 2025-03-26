// Title:   Source file for Preorder Traversal (Recursive)
// Authors: by vezzolter
// Date:    March 24, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include "PreorderTraversal.h"


void preorderTraversal(TreeNode* root) {
	if (!root) { return; }
	std::cout << root->val << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void reversedPreorderTraversal(TreeNode* root) {
	if (!root) { return; }
	std::cout << root->val << " ";
	reversedPreorderTraversal(root->right);
	reversedPreorderTraversal(root->left);
}