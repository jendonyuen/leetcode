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
    int t;
    int res = INT_MIN;
    // 倒序中序遍历, 不需要遍历完整的树
    void search(TreeNode* root) {
        if (!root) return;
        // right
        search(root->right);
        // root
        if (t == 0) return;
        if (--t == 0) this->res = root->val;
        // left
        search(root->left);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        this->t = k;
        search(root);
        return res;
    }
};

/*
// 使用队列+中序遍历
class Solution {
    queue<int> q;
    // 中序遍历
    void search(TreeNode* root, int k) {
        if (!root) return;
        // left
        search(root->left, k);
        // root
        q.push(root->val);
        if (q.size() > k) {
            q.pop();
        }
        // right
        search(root->right, k);
        return;
    }
public:
    int kthLargest(TreeNode* root, int k) {
        search(root, k);
        return q.front();
    }
};
*/

// 使用优先队列, 当前值小于队列头时即找到
/*
class Solution {
    priority_queue<int, vector<int>, greater<>> pq;

    bool search(TreeNode* root, int k) {
        if (!root) return false;
        if (pq.size() == k && !root->right && root->val < pq.top()) return true;
        pq.push(root->val);
        if (pq.size() > k) {
            pq.pop();
        }
        if (search(root->right, k)) return true;
        if (search(root->left, k)) return true;
        return false;
    }
public:
    int kthLargest(TreeNode* root, int k) {
        search(root, k);
        return pq.top();
    }
};
*/