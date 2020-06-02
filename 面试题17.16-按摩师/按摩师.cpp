class Solution {
public:
    int massage(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        std::vector<int> times = {nums[0], max(nums[0], nums[1])};
        for(int i = 2; i != nums.size(); ++i) {
            auto t = nums[i] + times[i-2] > times[i-1] ? nums[i] + times[i-2] : times[i-1];
            // cout << nums[i] << ": " << t << endl;
            times.push_back(t);
        }
        return times.back();
    }
};