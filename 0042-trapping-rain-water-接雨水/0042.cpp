/*
双指针: 从左右两头向中间遍历;
记录已遍历到的左最高格子和右最高格子;
当前格子所能接的雨水，取决于左最高和右最高中较矮的那个;
当[左最高<右最高]从左往右遍历
当[左最高>右最高]从右往左遍历
*/


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        while (left < right) {
            if (leftMax < rightMax) {
                if (height[++left] < leftMax) {
                    ans += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
            } else {
                if (height[--right] < rightMax) {
                    ans += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
            }
        }
        return ans;
    }
};