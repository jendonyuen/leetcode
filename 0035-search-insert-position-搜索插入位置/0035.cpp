// 2020.07
class Solution {
    int search(vector<int>& nums, int target, int beg, int end) {
        while (beg < end) {
            int mid = beg + (end - beg) / 2;
            if (nums[mid] < target) {
                beg = mid + 1;
            } else {
                end = mid;
            }
        }
        return beg;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int beg = 0, end = (int)nums.size();
        return search(nums, target, beg, end);
    }
};

/*
// 2018.10
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = 0;
        for(auto a: nums){
            if(a==target){
                return index;
            }else if(a>target){
                return index;
            }else{
                ++index;
            }
        }
        return index;
    }
};
*/