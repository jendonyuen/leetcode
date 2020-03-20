class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        int zerosNum = 0;
        int size = nums.size();
        for (int i = 0; i != size; ++i) {
            if (nums[i] != 0) {
                nums[p] = nums[i];
                ++p;
            } else {
                zerosNum++;
            }
        }
        for (int j = 0; j != zerosNum; ++j) {
            nums[size - j - 1] = 0;
        }
    }
};