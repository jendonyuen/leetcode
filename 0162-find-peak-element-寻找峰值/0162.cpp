class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int beg = 0, end = nums.size() - 1;
        while(beg < end) {
            int mid = (beg + end) / 2;
            if (nums[mid + 1] < nums[mid]) end = mid;
            else beg = mid + 1;
        }
        return beg;
    }
};

/*
class Solution {
    int search(vector<int>& nums) {
        int beg = 0, end = nums.size()-1;
        while(beg < end) {
            int mid = (beg + end) / 2;
            if (mid > 0 and nums[mid] > nums[mid-1]) {
                if (mid < nums.size() - 1 and  nums[mid] > nums[mid+1]) {
                    return mid;
                } else {
                    beg = mid + 1;
                }
            } else {
                end = mid;
            }
        }
        return end;
    }
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
        return search(nums);
    }
};
*/