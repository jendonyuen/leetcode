class Solution {
public:
    // 位运算: 一个数异或两次后得到本身
    // 异或: 相同为1, 不同为0
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }

    /* 数学: 求和后相减
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n+1) / 2;
        int tSum = 0;
        for (auto &num :nums) {
            tSum += num;
        }
        return sum - tSum;
    }
    */
};