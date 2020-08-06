class Solution {
    auto dfs(TreeNode* node) {
        if (!node) return tuple(0, 0);
        auto [robThisL, robOtherL] = dfs(node->left);
        auto [robThisR, robOtherR] = dfs(node->right);
        // 返回抢劫该节点得到的最大收益, 不抢劫该节点得到的最大收益
        return tuple(robOtherL + robOtherR + node->val, max(robThisL, robOtherL) + max(robThisR, robOtherR));
    }
public:
    int rob(TreeNode* root) {
        auto [g1, g2] = dfs(root);
        return max(g1, g2);
    }
};