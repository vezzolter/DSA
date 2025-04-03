// Title:   Source file for Postorder Traversal (Recursive)
// Authors: by vezzolter
// Date:    March 29, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include "PostorderTraversal.h"


void postorderTraversal(TreeNode* root) {
	if (!root) { return; }
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	std::cout << root->val << " ";
}

void reversedPostorderTraversal(TreeNode* root) {
	if (!root) { return; }
	reversedPostorderTraversal(root->right);
	reversedPostorderTraversal(root->left);
	std::cout << root->val << " ";
}