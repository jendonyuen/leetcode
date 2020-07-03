class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur = 0, p0 = 0, p2 = nums.size() - 1;
        while(cur <= p2) {
            if (nums[cur] == 0) {
                nums[cur] = nums[p0];
                nums[p0] = 0;
                p0++;
                cur++;
            } else if (nums[cur] == 2) {
                nums[cur] = nums[p2];
                nums[p2] = 2;
                p2--;
            } else cur++;
        }
    }
};