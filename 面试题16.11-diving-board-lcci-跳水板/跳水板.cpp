class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if (k == 0) return {};
        vector<int> res;
        res.push_back(shorter * k);
        int d = longer - shorter;
        if (!d) return res;
        for (int i = 0; i < k; ++i) {
            res.push_back(res.back() + d);
        }
        return res;
    }
};