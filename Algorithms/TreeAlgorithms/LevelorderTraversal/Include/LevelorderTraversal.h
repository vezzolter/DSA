// Title:   Header file for Levelorder Traversal (Iterative)
// Authors: by vezzolter
// Date:    April 5, 2025
// ----------------------------------------------------------------------------


#ifndef LEVELORDERTRAVERSAL_H
#define LEVELORDERTRAVERSAL_H


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void levelorderTraversal(TreeNode* root);
void reversedLevelorderTraversal(TreeNode* root);


#endif // LEVELORDERTRAVERSAL_H