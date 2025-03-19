// Title:   Header file for Inorder Traversal (Recursive)
// Authors: by vezzolter
// Date:    March 17, 2025
// ----------------------------------------------------------------------------


#ifndef INORDERTRAVERSAL_H
#define INORDERTRAVERSAL_H


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root);
void reversedInorderTraversal(TreeNode* root);


#endif // INORDERTRAVERSAL_H