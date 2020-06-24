// 单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len == 0) return 0;
        if (len == 1) return heights[0];

        // 加入哨兵, 左右两端补0
        vector<int> v(heights.size() + 2, 0);
        for (int i = 0; i < heights.size(); ++i) {
            v[i+1] = heights[i];
        }
        heights = v;

        int area = 0;
        stack<int> stack;
        stack.push(0);
        for (int i = 1; i < heights.size(); ++i) {
            while (heights[stack.top()] > heights[i]) {
                int height = heights[stack.top()];
                stack.pop();

                int width = i - stack.top() - 1;
                area = max(area, width * height);
            }
            stack.push(i);
        }

        return area;
    }
};

/* 枚举法
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int minHeight = INT_MAX;
            for (int j = i; j < heights.size(); ++j) {
                minHeight = min(heights[j], minHeight);
                maxArea = max(minHeight * (j - i + 1), maxArea);
            }
        }
        return maxArea;
    }
};

*/