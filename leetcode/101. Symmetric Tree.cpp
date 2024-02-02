/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    bool checkSymmetric(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if ((!left && right) || (left && !right) || left->val != right->val) return false;
        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return checkSymmetric(root->left, root->right) && checkSymmetric(root->right, root->left);
    }
};
