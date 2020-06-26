class Solution {
    void range(vector<int>& nums, int target, int &leftBeg, int &mid, int& rightEnd) {
        int leftEnd = mid;
        int rightBeg = mid;
        bool leftOk = false;
        bool rightOk = false;
        while (!leftOk or !rightOk) {
            if (!leftOk) {
                int leftMid = (leftBeg + leftEnd) / 2;
                if (nums[leftMid] < target) {
                    leftBeg = leftMid + 1;
                } else {
                    if (leftMid - 1 >= 0 and nums[leftMid - 1] == target) {
                        leftEnd = leftMid;
                    } else {
                        leftBeg = leftMid;
                        leftOk = true;
                    }
                }
            }
            if (!rightOk) {
                int rightMid = (rightBeg + rightEnd) / 2;
                if (nums[rightMid] > target) {
                    rightEnd = rightMid;
                } else {
                    if (rightMid + 1 < nums.size() and nums[rightMid + 1] == target) {
                        rightBeg = rightMid + 1;
                    } else {
                        rightEnd = rightMid;
                        rightOk = true;
                    }
                }
            }
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int beg = 0;
        int end = nums.size() - 1;
        while(beg < end) {
            int mid = (beg+end) / 2;
            if (nums[mid] == target) {
                // printf("r: %d, %d, %d\n", beg, mid, end);
                range(nums, target, beg, mid, end);
                return {beg, end};
            } else if (nums[mid] < target) {
                beg = mid + 1;
            } else if (nums[mid] > target) {
                end = mid;
            }
        }
        if (nums[end] == target) return {beg, end};
        return {-1, -1};
    }
};

/*
test cases
[1,1,2,2,3,3,4,5,7,7,8,8,8,8,8,8,8,9,10]
8
[1]
1
[5,7,7,8,8,10]
6
[2,2]
2
*/