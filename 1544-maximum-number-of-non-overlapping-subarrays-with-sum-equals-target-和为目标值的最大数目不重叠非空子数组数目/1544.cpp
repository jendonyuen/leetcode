class Solution {
public
    int maxNonOverlapping(vectorint& nums, int target) {
        unordered_maplong long, int preSum;    ksum , vpos
        preSum[0] = -1;
        int count = 0;
        int lastEnd = -1;
        
        long long sum = 0;
        for (int i = 0; i  nums.size(); ++i) {
            sum += nums[i];
            int t = sum - target;
            if (preSum.count(t) && lastEnd  preSum[t] + 1) {
                 cout  i    preSum[t]  endl;
                count++;
                lastEnd = i;
            }
            preSum[sum] = i;
        }
        
        return count;
    }
};