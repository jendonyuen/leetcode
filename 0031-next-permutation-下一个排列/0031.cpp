class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for (; i > 0 && nums[i-1] >= nums[i]; --i);    // 从后向前查找不递增的元素
        reverse(nums.begin() + i, nums.end());  // 查找到的位置之后都是递增的, 进行反转
        if (i > 0) {            // 二分查找尽可能小的大于nums[i-1]的元素, 交换位置
            auto it = upper_bound(nums.begin() + i, nums.end(), nums[i-1]);
            swap(*it, nums[i-1]);
        }
    }
};