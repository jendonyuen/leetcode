
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