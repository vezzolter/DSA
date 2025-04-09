// Title:   Source file for Levelorder Traversal (Iterative)
// Authors: by vezzolter
// Date:    April 5, 2025
// ----------------------------------------------------------------------------


#include <iostream>
#include <queue>
#include <stack>
#include "LevelorderTraversal.h"


void levelorderTraversal(TreeNode* root) {
	if (!root) { return; }

	std::queue<TreeNode*> q;
	q.push(root);

	for (; !q.empty(); ) {
		TreeNode* curr = q.front();
		q.pop();

		std::cout << curr->val << " ";

		if (curr->left) { q.push(curr->left); }
		if (curr->right) { q.push(curr->right); }
	}
}

void reversedLevelorderTraversal(TreeNode* root) {
	if (!root) { return; }

	std::queue<TreeNode*> q;
	q.push(root);
	std::stack<TreeNode*> s;

	for (; !q.empty(); ) {
		TreeNode* curr = q.front();
		q.pop();

		s.push(curr);

		if (curr->right) { q.push(curr->right); } // right should be first
		if (curr->left) { q.push(curr->left); }
	}

	for (; !s.empty(); ) {
		std::cout << s.top()->val << " ";
		s.pop();
	}
}