class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // 维护一个到i景点之前的最佳得分prev
        int prev = A[0];
        int res = 0;
        for (int i = 1; i < A.size(); ++i) {
            prev--;
            res = prev + A[i] > res ? prev + A[i] : res;
            prev = A[i] > prev ? A[i] : prev;
        }
        return res;
    }
};