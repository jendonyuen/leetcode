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
    vector<pair<TreeNode*, int>> paths;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int i = -1;
        TreeNode* nodeFound = NULL;
        paths.push_back(make_pair(root, 0));

        while (true) {
            auto &nodePair = paths.back();
            if (!nodePair.first) {
                paths.pop_back();
                continue;
            };
            // cout << nodePair.first->val << "," << i << endl;

            if (nodePair.second != 2) {
                if (nodePair.first == p || nodePair.first == q) {
                    if (i == -1) {
                        i = paths.size() - 1;
                        nodeFound = nodePair.first;
                    } else if (nodePair.first != nodeFound) return paths[i].first;
                }
                if (nodePair.second == 0) {
                    nodePair.second = 1;
                    paths.push_back(make_pair(nodePair.first->left, 0));
                } else if (nodePair.second == 1) {
                    nodePair.second = 2;
                    paths.push_back(make_pair(nodePair.first->right, 0));
                }
                
            } else {
                paths.pop_back();
                int size = paths.size();
                if (i >= size) {
                    i--;
                }
            }
        }
        return NULL;
    }
};