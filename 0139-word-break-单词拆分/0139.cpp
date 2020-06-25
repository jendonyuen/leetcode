/*
dp[i]记录字符串的前i个是否可拆分.
如果dp[i]== true, 且s[i:j]在字典中找到 ==> 即s[:j]可拆分, dp[j] = true;
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us;
        for (auto &word: wordDict) {
            us.insert(word);
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 1; j <= i; j++) {
                if (dp[i - j]) {
                    string t = s.substr(i-j, j);
                    if (us.find(t) != us.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp.back();
    }
};