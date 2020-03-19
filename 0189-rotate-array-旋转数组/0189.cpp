class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1) return;
        int len = nums.size();
        k = k % len;    // 求最小k
        if (k == 0) return;
        int p = 0, q, t, last = nums[p];
        int beg = p;    // 记录起始位置
        for(int i = 0; i != len; ++i) {
            q = p + k >= len ? p+k-len : p+k;
            t = nums[q];
            nums[q] = last;
            last = t;
            if (q == beg) {
                // 若循环回到起始位置则+1;
                q++;
                // 记录+1位置后的值
                last = nums[q];
                // 起始位置移动到新位置
                beg = q;
            }
            p = q;
        }
    }
};