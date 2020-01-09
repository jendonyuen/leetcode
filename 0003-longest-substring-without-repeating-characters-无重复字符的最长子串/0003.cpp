class Solution {
    string t;
    int checkRepeat(char &c) {
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == c) {
                return i;
            }
        }
        return -1;
    }
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        int maxLen = 1;
        t.push_back(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            int j = checkRepeat(s[i]);
            if (j != -1) {
                t = t.substr(j + 1, t.size());
            } 
            t.push_back(s[i]);
            if (maxLen < t.size()) {
                maxLen = t.size();
            }
        }
        return maxLen;
    }
};