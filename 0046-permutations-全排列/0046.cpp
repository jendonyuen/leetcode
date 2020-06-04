// 回溯法
class Solution {
    vector<vector<int>> res;
    vector<int> v;

    void backTrack(vector<int>& nums) {
        if (v.size() == nums.size()) {
            res.push_back(v);
            return;
        }
        // 回溯法, 循环里边套递归
        // 递归完成后撤销
        for (int i = 0; i < nums.size(); ++i) {
            if (find(v.begin(), v.end(), nums[i]) == v.end()) {
                v.push_back(nums[i]);
            } else continue;
            backTrack(nums);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(nums);
        return res;
    }
};

/*
// 见缝插针法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<list<int>> vl = {{nums[0]}};
        for (int i = 1; i != nums.size(); ++i) {
            vector<list<int>> vlt;
            for (auto& l : vl) {
                for (int j = 0; j <= l.size(); ++j) {
                    list<int> t = l;
                    auto it = t.begin();
                    advance(it, j);
                    t.insert(it, nums[i]);
                    vlt.push_back(t);
                }
            }
            vl = vlt;
        }
        vector<int> t;
        vector<vector<int>> ans(vl.size(), t);
        for (int i = 0; i != vl.size(); ++i) {
            ans[i].assign(vl[i].begin(), vl[i].end());
        }
        return ans;
    }
};
*/