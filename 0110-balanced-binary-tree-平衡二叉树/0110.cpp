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
    bool res = true;
    int dfs(TreeNode* root, int depth) {
        if (!root) return depth;
        int left = dfs(root->left, depth+1);
        if (!res) return depth;
        int right = dfs(root->right, depth+1);
        if (abs(left - right)> 1) res = false;
        return max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
};