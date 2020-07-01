class Solution {
    int res = 0;
    void maxLen(vector<int>& A, vector<int>& B, int ai, int bi) {
        int curLen = 0;
        while (ai < A.size() and bi < B.size()) {
            if (A[ai] == B[bi]) {
                curLen++;
            } else {
                if (curLen > res) res = curLen;
                curLen = 0;
            }
            ai++;
            bi++;
        }
        if (curLen > res) res = curLen;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        for (int ai = 0; ai < A.size(); ++ai) {
            maxLen(A, B, ai, 0);
        }

        for (int bi = 0; bi < B.size(); ++bi) {
            maxLen(A, B, 0, bi);
        }
        return res;
    }
};

// 滑动窗口
// 原理参考https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/solution/zui-chang-zhong-fu-zi-shu-zu-by-leetcode-solution/