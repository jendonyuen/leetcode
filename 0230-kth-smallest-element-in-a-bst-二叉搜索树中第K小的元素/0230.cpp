// 迭代
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        stk.push(node);
        node = node->left;
        while(true) {
            if (node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                if (--k == 0) return node->val;
                node = node->right;
            }
        }
        return INT_MIN;
    }
};

/*
// 递归
class Solution {
    int k, res;
    void search(TreeNode* root) {
        if (k < 0 || !root) return;
        search(root->left);
        if (--k == 0) {
            res = root->val;
            return;
        }
        search(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        search(root);
        return res;
    }
};
*/