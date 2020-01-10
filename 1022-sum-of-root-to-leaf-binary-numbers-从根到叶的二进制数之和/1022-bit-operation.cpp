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
    int sum = 0;
public:
    int sumRootToLeaf(TreeNode* root) {
        DFS(root, 0);
        return sum;
    }
    void DFS(TreeNode* node, int branchValue) {
        // sum
        branchValue = branchValue << 1 | node->val;
        if (node->left) DFS(node->left, branchValue);
        if (node->right) DFS(node->right, branchValue);
        if (node->left == NULL && node->right == NULL) {
            sum += branchValue;
        }
    }
};