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

// 把左子节点都接到右边, 依次操作每个节点：
// 1，当前节点右边的节点全接到左边节点的最右叶子节点；
// 2，把当前节点左边的节点改接到右边
// 3，继续搜索下一个节点, 重复1和2

class Solution {
    TreeNode* findRight(TreeNode* node) {
        while (node->right) {
            node = node->right;
        }
        return node;
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* node = root;
        while (node) {
            if (node->left) {
                auto theRight = findRight(node->left);
                theRight->right = node->right;
                node->right = node->left;
                node->left = nullptr;
                node = node->right;
            } else if (node->right) {
                node = node->right;
            } else break;
        }
    }
};