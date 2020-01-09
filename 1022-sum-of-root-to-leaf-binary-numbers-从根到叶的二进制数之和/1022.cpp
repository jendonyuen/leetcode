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
        std::vector<int> v;
        run(root, v);
        return sum;
    }
    void run(TreeNode* root, std::vector<int> v) {
        v.push_back(root->val);
        if (root->left != NULL) {
            run(root->left, v);
        } 
        if (root->right != NULL) {
            run(root->right, v);
        } 
        if (root->left == NULL && root->right == NULL) {
            cal(v);
        }
    
    }
    void cal(std::vector<int> v) {
        int t = 0;
        for (auto &a : v) {
            // std::cout << a;
            t = t * 2 + a;
        }
        // std::cout << endl;
        sum += t;
    }
    
};