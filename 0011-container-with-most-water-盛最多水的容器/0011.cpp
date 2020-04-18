// 第42题为本题的进阶版, 解法类似

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() < 2) return 0;
        int maxWater = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int currWater = min(height[left], height[right]) * (right - left);
            maxWater = currWater > maxWater ? currWater : maxWater;
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};