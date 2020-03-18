class Solution {
public:
    // sort         O(nlogn)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[int(nums.size()) / 2];
    }

    /* 
    // hash_map     O(n)
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> table;
        int n = int(nums.size()) / 2;
        for (const auto &num : nums) {
            if (table.find(num) != table.end()) {
                table[num] += 1;
            } else {
                table[num] = 1;
            }
            if (table[num] > n) {
                return num;
            }
        }
        return nums[0];
    }
    */
};