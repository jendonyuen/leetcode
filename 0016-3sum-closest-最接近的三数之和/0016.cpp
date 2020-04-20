class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            int closestSum = -1;
            int minD = INT_MAX;
            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int d = target - sum;
                if (d == 0) {
                    return target;
                }
                if (abs(d) < minD) {
                    minD = abs(d);
                    closestSum = sum;
                }
                if (d > 0) {
                    left++;
                } else {
                    right--;
                }
            }
            if (abs(minD) < abs(target - ans)) {
                ans = closestSum;
            }
        }
        return ans;
    }
};