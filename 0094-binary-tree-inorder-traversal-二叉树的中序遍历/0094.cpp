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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL) return v; 
        walk(root, v);
        return v;
    }

    void walk(TreeNode* root, vector<int>& v) {
        if (root->left != NULL) {
            walk(root->left, v);
            v.push_back(root->val);
        } else {
            v.push_back(root->val);
        } 
        if (root->right != NULL) {
            walk(root->right, v);
        } 
    }
};