class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n+1) / 2;
        int tSum = 0;
        for (auto &num :nums) {
            tSum += num;
        }
        return sum - tSum;
    }
};