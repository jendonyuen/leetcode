class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int n = 0;
        for (int i = int(s.size()) - 1; i > -1; --i) {
            ans += (s[i] - 'A' + 1) * pow(26, n);
            n++;
        }
        return ans;
    }
};