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
    int dimiter = 1;
    int getDeep(TreeNode* root) {
        if (!root) return 0;
        int lD = getDeep(root->left);
        int rD = getDeep(root->right);
        dimiter = max(lD+rD+1, dimiter);
        return max(lD+1, rD+1);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        getDeep(root);
        return dimiter - 1;
    }
};