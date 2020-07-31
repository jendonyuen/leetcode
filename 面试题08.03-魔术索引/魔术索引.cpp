// 二分剪枝
class Solution {
    int res = INT_MAX;
    void search(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        if (nums[mid] == mid) res = min(res, mid);
        search(nums, left, mid);
        if (res > mid) {    // 剪枝：如果前边有元素符合条件，就不搜索后边
            search(nums, mid+1, right);
        }
    }
public:
    int findMagicIndex(vector<int>& nums) {
        search(nums, 0, nums.size());
        return res == INT_MAX ? -1 : res;
    }
};



/* 
// 枚举
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == i) return i;
        }
        return -1;
    }
};

*/