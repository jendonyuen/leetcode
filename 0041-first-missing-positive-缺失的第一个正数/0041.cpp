// 原地hash, 时间复杂度O(n), 空间复杂度O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // [1] 将非正数变为n+1
        int size = nums.size();
        for (auto &n : nums) {
            if (n <= 0) n = size + 1;
        }
        // [2] 若指向索引在[1, n]范围内, 将索引(i-1)对应位置标记为负数 
        for (auto &n : nums) {
            if (abs(n) <= size) {
                nums[abs(n)-1] = -abs(nums[abs(n)-1]);
            }
        }
        // [3] 返回第一个大于0的值的索引
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return i+1;
        }
        return size + 1;
    }
};


/* O(n2)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 1;
        int temp =0;
        while(temp!=i){
            temp = i;
            for(auto a1:nums){
                if(a1==i){
                    ++i;
                }
            }
        }
        return i;
    }
};
*/