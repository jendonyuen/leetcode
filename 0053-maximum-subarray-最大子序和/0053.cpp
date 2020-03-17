class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int sum = nums[0];
        int maxSum = sum;
        for (int i = 1; i != nums.size(); ++i) {
            if (sum > 0) {
                // 若sum > 0， 对之后的子序列有益
                sum += nums[i];
            } else {
                //  若sum <= 0，那么之后的子序列肯定不包含目前的子序列，所以令sum = nums[i]
                sum = nums[i];
            }
            maxSum = maxSum >= sum ? maxSum : sum;
        }
        
        return maxSum;
    }
};