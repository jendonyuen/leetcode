// 2020-08-11, 时间复杂度O(n)
// 基于快排的选择方法
// 快排可参考912题
// ref: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
class Solution {
    int partition(vector<int>& nums, int l, int r) {
        auto pivot = nums[r];
        int i = l;
        for (int j = l; j < r; ++j) {
            if (nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }

    int randomized_parition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    int randomized_quickselect(vector<int>& nums, int l, int r, int k) {
        int pos = randomized_parition(nums, l, r);
        // pos左边的必定比nums[pos]小, 右边的必定比nums[pos]大
        if (pos == k - 1) return pos;
        else if (pos < k) return randomized_quickselect(nums, pos + 1, r, k);
        else return randomized_quickselect(nums, l, pos - 1, k);
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int pos = randomized_quickselect(nums, 0, nums.size() - 1, k);
        return nums[pos];
    }
};


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