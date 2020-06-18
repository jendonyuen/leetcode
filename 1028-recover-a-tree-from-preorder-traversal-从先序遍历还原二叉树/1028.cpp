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
    TreeNode* recoverFromPreorder(string S) {
        if (S.size() == 0) return NULL;

        vector<vector<TreeNode*>> v;
        int deep = 0;
        int val = 0;
        bool gotNum = false;

        // 根节点
        int i = 0;
        while(i < S.size() && S[i] != '-') {
            val = val * 10 + S[i] - '0';
            i++;
        }
        TreeNode* root = new TreeNode(val);
        v.push_back({root});
        val = 0;

        // 后续节点
        for (; i < S.size(); ++i) {
            if (S[i] == '-') {
                if (gotNum) {
                    TreeNode* node = new TreeNode(val);
                    if (v.size() <= deep) {
                        v.push_back({node});
                    } else {
                        v[deep].push_back(node);
                    }
                    if (v[deep - 1].back()->left) {
                        v[deep - 1].back()->right = node;
                    } else {
                        v[deep - 1].back()->left = node;
                    }
                    deep = 1;
                    val = 0;
                    gotNum = false;
                } else {
                    ++deep;
                }
            } else {
                gotNum = true;
                val = val * 10 + S[i] - '0';
            } 
        }

        // 最后一个节点
        if (gotNum) {
            TreeNode* node = new TreeNode(val);
            if (v[deep - 1].back()->left) {
                v[deep - 1].back()->right = node;
            } else {
                v[deep - 1].back()->left = node;
            }
        }
        return root;
    }
};