class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() or s[0] == '0') return 0;
        int res = 1, last = 1, before = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '0' or s[i-1] > '2') return 0;
                else res = before;
            } else if (s[i-1] == '1') {
                res = last + before;
            } else if (s[i-1] == '2' and (s[i] >= '1' and s[i] <= '6')) {
                res = last + before;
            } else {
                res = last;
            }
            before = last;
            last = res;
        }
        return res;
    }
};