class Solution {
    vector<vector<int>> res;
    vector<int> v;
    void backTrack(vector<int>& cds, int& target, int i, long long sum) {
        if (i >= cds.size()) return;
        sum += cds[i];
        if (sum > target) return;
        v.push_back(cds[i]);
        if (sum == target) {
            res.push_back(v);
        } else {
            for (int j = 0; j < cds.size() - i; ++j) {
                backTrack(cds, target, i+j, sum);
            }
        }
        v.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        for (int i = 0; i < candidates.size(); ++i) {
            backTrack(candidates, target, i, 0);
        }
        return res;
    }
};