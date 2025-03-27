// Title:   Header file for Preorder Traversal (Recursive)
// Authors: by vezzolter
// Date:    March 24, 2025
// ----------------------------------------------------------------------------


#ifndef PREORDERTRAVERSAL_H
#define PREORDERTRAVERSAL_H


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* root);
void reversedPreorderTraversal(TreeNode* root);


#endif // PREORDERTRAVERSAL_H