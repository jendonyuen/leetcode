class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int maxPos = nums[0];
        int i = 0;
        while(i < maxPos) {
            i++;
            // cout << i << ":" << i + nums[i] << "max" << maxPos << endl;
            if (i + nums[i] > maxPos) maxPos = i + nums[i];
            if (maxPos >= nums.size() - 1) return true;
        }
        return false;
    }
};