class Solution {
public:
    // 前缀和 + hash_map
    // sum[A,B]=sum[0,B]-sum[0,A]
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        int ans = 0;
        int sum = 0;
        for (const auto &num: nums) {
            sum += num;
            ans += sumMap[sum - k];
            sumMap[sum]++;
        }
        return ans;
    }
    /* 
    // 枚举法
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) {return 0;}
        if (nums.size() == 1) {return nums[0] == k ? 1 : 0;}
        int p1 = 0;
        int stride = 1;
        int sum = 0;
        int ans = 0;
        while (stride <= nums.size()) {
            for (int i = p1; i < stride; ++i) {
                sum += nums[i];
                // cout << "sum" << sum << endl;
            }
            while (true) {
                // cout << "!" << sum << endl;
                if (sum == k) {ans++;}
                if (p1 + stride == nums.size()) {break;}
                sum = sum - nums[p1] + nums[p1 + stride];
                p1++;
            }
            sum = 0;
            p1 = 0;
            stride++;
        }
        return ans;
    }
    */
};