class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> vs(128, 0);
        vector<int> vt(128, 0);
        for (int i = 0; i < s.size(); ++i) {
            if (!vs[s[i]]) {
                if (!vt[t[i]]) {
                    vs[s[i]] = t[i];
                    vt[t[i]] = s[i];
                } else return false;
            } else {
                if (t[i] != vs[s[i]]) return false;
            }
        }
        return true;
    }
};