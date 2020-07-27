// 贪心策略, 记录每种长度的上升子序列, 末尾所允许的最小值,
// dp[i] 表示长度为i的上升子序列, 末尾所允许的最小值
// 二分查找, 插入元素n后, 查找dp[i]中大于或等于n的元素位置

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (auto& n: nums) {
            int beg = 0, end = dp.size();
            while(beg < end) {
                int mid = beg + (end - beg) / 2;
                if (dp[mid] < n) {
                    beg = mid + 1;
                } else {
                    end = mid;
                }
            }
            if (dp.size() <= beg) {
                dp.emplace_back(n);
            } else {
                dp[beg] = n;
            }
        }
        // for (auto a : dp) cout << a << ", "; cout << endl;
        return dp.size();
    }
};