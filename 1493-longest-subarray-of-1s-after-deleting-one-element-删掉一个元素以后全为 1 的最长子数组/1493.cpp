// 第 29 场双周赛

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int t1 = 0; // 当前连续的1
        int t2 = 0; // 跳过上次1个0时, 连续的1个数
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) {
                t1++;
                t2++;
            } else {
                t2 = t1;
                t1 = 0;
            }
            if (t2 > res) res = t2;
        }
        if (res == nums.size()) return res - 1;
        return res;
    }
};