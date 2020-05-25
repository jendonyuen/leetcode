// 前序遍历[(root), left, right]
// 中序遍历[left, (root), right]
// 根据前序遍历, 定位中序遍历的根节点, 即可知道左子树和右子树
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
    // (node_value, inorder_pos)
    unordered_map<int, int> orderMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, 
        int preLeft, int preRight, int inLeft, int inRight) {
            if (preLeft > preRight) {return NULL;}
            TreeNode* node = new TreeNode(preorder[preLeft]);
            int inRoot = orderMap[preorder[preLeft]];
            // 遍历左子树
            int leftSize = inRoot - inLeft;
            if (leftSize > 0) {
                int leftChildPreRight = preLeft + leftSize;
                node->left = buildTree(preorder, inorder, preLeft + 1, leftChildPreRight, inLeft, inRoot - 1);
            }
            // 遍历右子树
            int rightSize = inRight - inRoot;
            if (rightSize > 0) {
                int rightChildPreLeft = preLeft + leftSize + 1;
                node->right = buildTree(preorder, inorder, rightChildPreLeft, preRight, inRoot + 1, inRight);
            }
            return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {return NULL;}
        int p1 = 0;
        int p2 = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            orderMap[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }
};