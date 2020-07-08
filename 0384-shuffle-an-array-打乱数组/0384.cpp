/*
Fisher-Yates 洗牌算法
依次将数组中的每个元素，与其到末尾[i, n-1]范围内的随机个元素交换，这样已交换过的元素不会再被交换
*/


class Solution {
    int n;
    vector<int> nums;
    vector<int> cur;
public:
    Solution(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        this->cur = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (n == 0) return cur;
        for (int i = 0; i < n; ++i) {
            swap(cur[i], cur[i + rand() % (n - i)]);
        }
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */



/*
class Solution {
    int n;
    vector<int> nums;
    vector<int> cur;
public:
    Solution(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        this->cur = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        if (n == 0) return cur;
        swap(cur[rand() % n], cur[rand() % n]);
        return cur;
    }
};

*/