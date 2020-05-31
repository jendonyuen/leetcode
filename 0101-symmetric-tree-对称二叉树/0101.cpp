/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool DFS(TreeNode* left, TreeNode* right) {
        if (!left || !right) {
            return left == right;
        }
        return left->val == right->val && DFS(left->left, right->right) && DFS(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return DFS(root->left, root->right);
    }
};