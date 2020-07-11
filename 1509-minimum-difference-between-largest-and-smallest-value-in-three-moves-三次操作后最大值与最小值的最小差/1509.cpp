// 30th biweekly contest
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int n = nums.size() - 1;
        res = min(res, nums[n-3] - nums[0]);
        res = min(res, nums[n-2] - nums[1]);
        res = min(res, nums[n-1] - nums[2]);
        res = min(res, nums[n] - nums[3]);
        return res;
    }
};