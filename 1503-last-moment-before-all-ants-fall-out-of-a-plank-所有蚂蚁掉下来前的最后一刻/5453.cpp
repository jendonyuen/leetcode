class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = INT_MIN;
        for (auto &a: left) {
            if (a > res) res = a;
        }
        for (auto &a: right) {
            if (n - a > res) res = n - a;
        }
        return res;
    }
};