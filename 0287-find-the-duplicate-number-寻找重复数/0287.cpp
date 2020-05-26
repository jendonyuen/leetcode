class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 必定存在环, 例如1->(2)->3->4->(2)->3->4->...,
        int fast = 0;
        int slow = 0;
        fast = nums[nums[fast]];
        slow = nums[slow];
        // 第一次快指针追上慢指针, 相遇点不是入环点
        while (fast != slow) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        // 将快指针或慢指针置于起始位置
        fast = 0;
        // 第二次必在入环点相遇
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};