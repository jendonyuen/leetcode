class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        int t = 0;
        for (auto &a: nums) {
            t += a;
            res.push_back(t);
        }
        return res;
    }
};