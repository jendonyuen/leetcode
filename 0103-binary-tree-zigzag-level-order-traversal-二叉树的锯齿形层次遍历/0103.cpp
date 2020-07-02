/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 层序遍历后反转
class Solution {
    vector<vector<int>> levelVec;
    void reverse() {
        for (int i = 1; i < levelVec.size(); i += 2) {
            int left = 0;
            int right = levelVec[i].size() - 1;
            while(left < right) {
                int temp = levelVec[i][left];
                levelVec[i][left] = levelVec[i][right];
                levelVec[i][right] = temp;
                left++;
                right--;
            }
        }
    }
    void levelOrderTraversal(TreeNode* node, int level) {
        if (!node) return;
        if (levelVec.size() == level) {
            levelVec.push_back({node->val});
        } else {
            levelVec[level].push_back(node->val);
        }
        levelOrderTraversal(node->left, level+1);
        levelOrderTraversal(node->right, level+1);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelOrderTraversal(root, 0);
        reverse();
        return levelVec;
    }
};