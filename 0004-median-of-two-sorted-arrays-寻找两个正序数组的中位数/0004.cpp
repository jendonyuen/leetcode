/*
划分法 时间复杂度:log(min(m, n))
even:
len(left_part) == len(right_part)
max(left_part) <= min(right_part)
median = (max(left_part) + min(right_part)) / 2
odd:
len(left_part) == len(right_part) + 1
max(left_part) <= min(right_part)
median = max(left_part)
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 确保第一个数组长度小于第二个数组
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int size1 = nums1.size();
        int size2 = nums2.size();

        int beg = 0, end = size1, ansi = -1;
        // median1: 前部分的最大值
        // median2: 后部分的最小值
        int median1 = 0, median2 = 0;

        while(beg <= end) {
            int i1 = (beg+end) / 2;
            int i2 = (size1+size2+1) / 2 - i1;

            // 计算分割线两侧的值, 注意边界判断
            int nums1Left = (i1 == 0 ? INT_MIN: nums1[i1-1]);
            int nums1Right = (i1 == size1 ? INT_MAX: nums1[i1]);
            int nums2Left = (i2 == 0 ? INT_MIN: nums2[i2-1]);
            int nums2Right = (i2 == size2 ? INT_MAX: nums2[i2]);

            if (nums1Left <= nums2Right) {
                ansi = i1;
                median1 = max(nums1Left, nums2Left);
                median2 = min(nums1Right, nums2Right);
                beg = i1 + 1;             
            } else {
                end = i1 - 1;
            }
        }

        return (size1+size2) & 1 ? median1 : (median1+median2) / 2.0;
    }
};


/* 枚举法 O((m+n)/2)
class Solution {
    double res;
    inline bool check(double& curr, int& i, int& n, bool& isOdd) {
        // cout << curr << "," << i << "," << n << "," << isOdd << endl;
        if (isOdd) {
            if (i == n / 2) {
                res = curr;
                return true;
            }
        } else {
            if (i == n / 2 - 1) {
                res = curr;
            } else if (i == n / 2) {
                res = (curr + res) / 2;
                return true;
            }
        }
        return false;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;
        int n = nums1.size() + nums2.size();
        bool isOdd = n % 2; // 个数是否为奇数
        int i = 0;
        double curr;

        if (nums1.size() == 0) {
            curr = nums2[p2];
            p2++;
        } else if (nums2.size() == 0) {
            curr = nums1[p1];
            p1++;
        } else if (nums1[p1] < nums2[p2]) {
            curr = nums1[p1];
            p1++;
        } else {
            curr = nums2[p2];
            p2++;
        }
        if (check(curr, i, n, isOdd)) {
            return res;
        }

        while (true) {
            if (nums1.size() == p1) {
                // v1 遍历完
                curr = nums2[p2];
                p2++;
                i++;
            } else if (nums2.size() == p2) {
                // v2 遍历完
                curr = nums1[p1];
                p1++;
                i++;
            } else if (nums1[p1] < nums2[p2]) {
                curr = nums1[p1];
                p1++;
                i++;
            } else {
                curr = nums2[p2];
                p2++;
                i++;
            }
            if (check(curr, i, n, isOdd)) {
                return res;
            }
        }
        return -1.0;
    }
};
*/