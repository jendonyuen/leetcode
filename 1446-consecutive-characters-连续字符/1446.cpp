class Solution {
public:
    int maxPower(string s) {
        if (s.size() == 0) return 0;
        char c = s[0];
        int ans = 1;
        int curr = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == c) {
                curr++;
                if (curr > ans) ans = curr;
            } else {
                curr = 1;
                c = s[i];
            }
        }
        return ans;
    }
};