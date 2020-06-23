/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 计算每个节点的最大贡献值

class Solution {
    int res = INT_MIN;
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        int left = max(maxGain(node->left), 0);
        int right = max(maxGain(node->right), 0);
        res = max(res, left+right+node->val);
        return node->val+max(left, right); // 只能贡献值最大的边
    }
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return res;
    }
};