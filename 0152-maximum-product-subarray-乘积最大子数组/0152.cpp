class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int lastMin = nums[0];
        int lastMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int t1 = lastMin * nums[i];
            int t2 = lastMax * nums[i];
            int currMax = t1 > t2 ? t1 : t2;
            int currMin = t1 < t2 ? t1 : t2;
            currMax = max(nums[i], currMax);
            currMin = min(nums[i], currMin);
            if (currMax > ans) {ans = currMax;}
            lastMin = currMin;
            lastMax = currMax;
        }
        return ans;
    }
};