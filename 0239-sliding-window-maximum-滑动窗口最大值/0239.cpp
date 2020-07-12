class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int> que;
        int maxValue = INT_MIN;
        for (int i = 0; i < k; ++i) {
            que.push(nums[i]);
            if (nums[i] > maxValue) maxValue = nums[i];
        }

        vector<int> res = {maxValue};
        for (int i = k; i < nums.size(); ++i) {
            int t = que.front();
            que.pop();
            que.push(nums[i]);
            if (t == maxValue) {
                maxValue = nums[i];
                for (int j = i - k + 1; j < i; ++j) {
                    if (nums[j] > maxValue) maxValue = nums[j];
                }
            }
            if (nums[i] > maxValue) maxValue = nums[i];
            res.push_back(maxValue);
        }
        return res;
    }
};