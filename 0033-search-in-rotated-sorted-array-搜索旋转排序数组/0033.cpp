/*
三种向前半部分查找的情况:
[beg] <= target <= [mid]   1(2)34567
[mid] < [beg] <= target    6(7)12345
target <= [mid] < [beg]    67(1)2345
其它情况向后查找
*/


class Solution {
    // 第二种写法
    // 使用异或进行判断
    int bSearch(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;
        while (beg < end) {
            int mid = (beg + end) / 2;
            if ((nums[beg] <= target) ^ (target <= nums[mid]) ^ (nums[mid] < nums[beg])) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        return beg == end && nums[beg] == target ? beg : -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        // return bSearch(nums, target);
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (
                (nums[left] <= target && target <= nums[mid]) ||
                (nums[mid] < nums[left] && nums[left] <= target) ||
                (target <= nums[mid] && nums[mid] < nums[left])
            ) {
                right = mid;
            } else {
                left = mid + 1;
            }
            
        }
        return left == right && nums[left] == target ? left : -1;
    }
};