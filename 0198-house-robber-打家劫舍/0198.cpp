class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> money = {nums[0]};
        money.push_back(nums[0] > nums[1] ? nums[0] : nums[1]);
        for (int i = 2; i < nums.size(); ++ i) {
            int curr = nums[i] + money[i-2];
            if (money[i-1] > curr) curr = money[i-1];
            money.push_back(curr);
        }
        return money.back();
    }
};
/* 
// 与面试题 17.16. 按摩师相同
class Solution {
public:
    int rob(vector<int>& nums) {
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
            times.push_back(t);
        }
        return times.back();
    }
};
*/