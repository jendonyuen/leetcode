class Solution {
public:
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
};