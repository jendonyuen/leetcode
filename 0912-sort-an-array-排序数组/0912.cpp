class Solution {
    // 快速排序法
    void quickSort(vector<int>& nums, int beg, int end) {
        if (end <= beg) return;
        int i = beg, j = end + 1;
        int key = nums[beg];

        while (true) {
            // 从左往右找比key大的元素索引
            while (nums[++i] < key && i != end);
            // 从右往左找比key小的元素索引
            while (nums[--j] > key && j != beg);
            // 当两个指针相遇时终止
            if (i >= j) break;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        // 交换key与j对应值
        int temp = nums[beg];
        nums[beg] = nums[j];
        nums[j] = temp;
        // 递归前半部分和后半部分
        quickSort(nums, beg, j - 1);
        quickSort(nums, j + 1, end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};