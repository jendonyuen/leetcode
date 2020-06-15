class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        string res = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            if (res.size() == 0) return res;
            for (int j = 0; j < res.size(); ++j) {
                if (j >= strs[i].size()) {
                    res = res.substr(0, j);
                } else {
                    if (res[j] != strs[i][j]) {
                        res = res.substr(0, j);
                    }
                }
            }
        }
        return res;
    }
};