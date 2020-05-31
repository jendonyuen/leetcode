// 第 191 场周赛
// 排序O(nlogn)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size() - 2] - 1) * (nums.back() - 1);
    }
};

/* 枚举法O(n2)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int cur = (nums[i]-1) * (nums[j]-1);
                if (cur > ans) ans = cur;
            }
        }
        return ans;
    }
};
*/