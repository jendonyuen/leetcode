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
    vector<vector<int>> v;
    void search(TreeNode* node, int level) {
        if (!node) return;
        if (v.size() == level) {v.push_back({});}
        v[level].push_back(node->val);
        search(node->left, level+1);
        search(node->right, level+1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        search(root, 0);
        return v;
    }
};