class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            int size = res.size();
            // 将之前res中所有的集合都插入当前元素
            for (int j = 0; j < size; ++j) {
                auto v = res[j];
                v.push_back(nums[i]);
                res.push_back(v);
            }
            res.push_back({nums[i]});
        }
        res.push_back({});
        return res;
    }
};