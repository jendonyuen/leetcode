class Solution {
public:
    // 反转法
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1) return;
        // 注意判断k是否超出数组长度
        if (k > nums.size()) k = k % nums.size();

        // 第一次翻转[0, n]整个数组
        int beg = -1, end = nums.size(), t;
        while (++beg < --end) {
            t = nums[beg];
            nums[beg] = nums[end];
            nums[end] = t;
        }  
        // for (auto & a: nums) cout << a << ","; cout << endl; 
        
        // 第二次翻转[0, k-1]部分数组
        beg = -1;
        end = k;
        while (++beg < --end) {
            t = nums[beg];
            nums[beg] = nums[end];
            nums[end] = t;
        }
        // for (auto & a: nums) cout << a << ","; cout << endl; 
        
        // 第三次翻转[k, n-1]部分数组
        beg = k - 1;
        end = nums.size();
        while (++beg < --end) {
            t = nums[beg];
            nums[beg] = nums[end];
            nums[end] = t;
        }
        // for (auto & a: nums) cout << a << ","; cout << endl; 
    }

    /* 环状替换法(类似换座位)
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
    */
};