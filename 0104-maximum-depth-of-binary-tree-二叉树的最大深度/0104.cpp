class Solution {
    int res = 0;
    void dfs(TreeNode* root, int d) {
        if (!root) return;
        res = max(res, d);
        dfs(root->left, d+1);
        dfs(root->right, d+1);
    }
public:
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return res;
    }
};