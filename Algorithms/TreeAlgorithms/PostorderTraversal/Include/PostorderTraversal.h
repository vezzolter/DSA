// Title:   Header file for Postorder Traversal (Recursive)
// Authors: by vezzolter
// Date:    March 29, 2025
// ----------------------------------------------------------------------------


#ifndef POSTORDERTRAVERSAL_H
#define POSTORDERTRAVERSAL_H


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postorderTraversal(TreeNode* root);
void reversedPostorderTraversal(TreeNode* root);


#endif // POSTORDERTRAVERSAL_H