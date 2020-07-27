/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int res = 0;
    int d;
    vector<int> search(TreeNode* node) {
        if (!node) return {};
        if (!node->left && !node->right) return {1};
        auto l = search(node->left);
        auto r = search(node->right); 
        count(l, r);
        for (auto &a: l) {
            a++;
        }
        for (auto &a: r) {
            l.push_back(a+1);
        }
        return l;
    }
    void count(vector<int>& l, vector<int>& r) {
        for (int i = 0; i < l.size(); ++i) {
            for (int j = 0; j < r.size(); ++j) {
                if (l[i] + r[j] <= d) res++;
            }
        }
    }
public:
    int countPairs(TreeNode* root, int distance) {
        this->d = distance;
        search(root);
        return res;
    }
};