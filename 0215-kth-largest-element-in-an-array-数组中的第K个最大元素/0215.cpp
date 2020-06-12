// 小顶堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 小顶堆, pq.pop()删除队列中最小元素, pq.top()输出队列中最小元素
        priority_queue<int, vector<int>, greater<int>> pq;  
        for (auto &a: nums) {
            pq.push(a);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

/*
// 堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), less<int>());
        for (; k > 1; --k) {
            pop_heap(nums.begin(), nums.end(), less<int>());
            nums.pop_back();
        }
        return nums[0];
    }
};
*/

/*
// 排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
*/