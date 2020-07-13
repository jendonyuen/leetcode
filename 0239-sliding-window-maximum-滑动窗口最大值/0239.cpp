// 双端队列, 存元素索引
// 维持队列内元素单调递减, 队首元素最大
// [1]先根据索引判断队首元素是否处于窗口内
// [2]再将新元素入队, 入队规则: 若队尾元素小于入队元素, 则弹出队尾元素
class Solution {
    deque<int> dq;
    int k;
    void push(vector<int>& nums, int i) {
        // [1]先根据索引判断队首元素是否处于窗口内
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        // [2]再将新元素入队, 入队规则: 若队尾元素小于入队元素, 则弹出队尾元素
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        } 
        dq.push_back(i);
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        this->k = k;
        for (int i = 0; i < k - 1; ++i) {
            push(nums, i);
        }
        for (int i = k - 1; i < nums.size(); ++i) {
            push(nums, i);
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};


// 动态规划+分块
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // div将滑动窗口分为两块, 则滑动窗口的最大值为max[beg, div] max[div, end]
        // 将数组分为k块, 则总存在一个div将窗口分为两块
        int n = nums.size();
        if (n == 0 || k > n || k == 0) return {};

        // 记录当前位置往左到分割位置[div, left]之间的最大值
        vector<int> left(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i % k) {
                left[i] = max(nums[i], left[i-1]);
                
            } else {
                left[i] = nums[i];
            }
        }
        // 记录当前位置往右到分割位置[right, div]之间的最大值
        vector<int> right(n, 0);
        right[n-1] = nums[n-1];
        for (int i = n - 2; i >= 0; --i) {
            if ((i+1) % k) right[i] = max(nums[i], right[i+1]);
            else right[i] = nums[i];
        }

        // max(max[beg, div] max[div, end])
        vector<int> res(n - k + 1);
        for (int i = 0; i < n - k + 1; ++i) {
            res[i] = max(right[i], left[i + k - 1]);
        }

        return res;
    }
};

/*
// 枚举
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        queue<int> que;
        int maxValue = INT_MIN;
        for (int i = 0; i < k; ++i) {
            que.push(nums[i]);
            if (nums[i] > maxValue) maxValue = nums[i];
        }

        vector<int> res = {maxValue};
        for (int i = k; i < nums.size(); ++i) {
            int t = que.front();
            que.pop();
            que.push(nums[i]);
            if (t == maxValue) {
                maxValue = nums[i];
                for (int j = i - k + 1; j < i; ++j) {
                    if (nums[j] > maxValue) maxValue = nums[j];
                }
            }
            if (nums[i] > maxValue) maxValue = nums[i];
            res.push_back(maxValue);
        }
        return res;
    }
};
*/