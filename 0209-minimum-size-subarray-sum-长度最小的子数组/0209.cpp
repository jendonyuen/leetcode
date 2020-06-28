class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, beg = 0, res = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum - nums[beg] >= s) sum -= nums[beg++];
            if (sum >= s && i - beg + 1 < res) res = i - beg + 1; 
        }
        return res == INT_MAX ? 0 : res;
    }
};

/*
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int beg = 0;
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum - nums[beg] >= s) {
                sum -= nums[beg];
                beg++;
            }
            if (sum >= s && i - beg + 1 < res) res = i - beg + 1; 
        }
        if (res == INT_MAX) return 0;
        return res;
    }
};
*/