class Solution {
    int target;
    set<vector<int>> res;
    vector<int> v;
    void backTrack(vector<int>& candidates, int i, int cur) {
        v.push_back(candidates[i]);
        cur += candidates[i];
        if (cur == target) {
            res.insert(v);
        } else {
            for (int j = i + 1; j < candidates.size(); ++j) {
                if (cur + candidates[j] > target) break;    // 判断大于直接break
                backTrack(candidates, j, cur);
            }
        }
        v.pop_back();
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        vector<int> cds = candidates;
        sort(cds.begin(), cds.end());   // 先排序
        for (int i = 0; i < cds.size(); ++i) {
            if (cds[i] > target) break; // 判断大于直接break
            backTrack(cds, i, 0);
        }
        vector<vector<int>> vv;
        vv.assign(res.begin(), res.end());
        return vv;
    }
};