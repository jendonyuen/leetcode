class Solution {
public:
    int findMin(vector<int>& nums) {
        int beg = 0, end = nums.size() - 1;
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] < nums[end]) end = mid;
            else if (nums[mid] > nums[end]) beg = mid + 1;
            else end --;
        }
        return nums[beg];
    }
};