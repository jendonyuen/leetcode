class Solution {
public:
    // 位运算: 异或, 同第136题
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto &num: nums) {
            ans ^= num;
        }
        return ans;
    }
    /* 穷举法
    int singleNumber(vector<int>& nums) {
        for (int i = 0; i != nums.size(); ++i) {
            int j = 0;
            for (; j!= nums.size(); ++j) {
                if (i!=j && nums[i] == nums[j]) {
                    break;
                }
            }
            if (j == nums.size()) {
                return nums[i];
            }
        }
        return 0;
    }
    */
};