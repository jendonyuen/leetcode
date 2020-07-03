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
    TreeNode* build(vector<int>& nums, int beg, int end) {
        if (beg > end) return NULL;
        int mid = (beg + end) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, beg, mid - 1);
        root->right = build(nums, mid + 1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
};


/*
class Solution {
private:
    TreeNode* helper(vector<int>& nums, int beg, int end) {
        if (end <= beg) return NULL;
        TreeNode* root = new TreeNode(0);
        int mid = (end + beg) / 2;
        root->val = nums[mid];
        root->left = helper(nums, beg, mid);
        root->right = helper(nums, mid+1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};
*/