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
    int sum;
    bool dfs(TreeNode* node, int val) {
        if (!node) {
            return false;
        }
        val += node->val;
        if (!node->left && !node->right) {
            return val == sum;
        }
        if (dfs(node->left, val)) return true;
        if (dfs(node->right, val)) return true;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        this->sum = sum;
        return dfs(root, 0);
    }
};