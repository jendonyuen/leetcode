// 30th biweekly contest
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> sums;
        for (int i = 0; i < nums.size(); ++i) {
            long long sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());
        long long res = 0;
        for (int i = left - 1; i < right; ++i) {
            res += sums[i];
        }
        
        return fmod(res, 1000000007);
    }
};