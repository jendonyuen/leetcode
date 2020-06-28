class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // 对应奇数个数统计到的次数
        vector<int> count(nums.size()+1, 0);
        count[0] = 1;
        int odd = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) odd++;
            if (odd >= k) {
                res += count[odd - k];
            }
            count[odd]++;   
        }
        return res;
    }
};