// 30th biweekly contest
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp {1, 0, 1, 1};
        for (int i = 5; i <=n; ++i) {
            if (sqrt(i) == int(sqrt(i))) {
                dp.push_back(1);
                continue;
            }
            bool win = false;
            for (int j = 1; j*j < i; j++) {
                if (!dp[i - j*j - 1]) {
                    win = true;
                    break;
                }
            }
            if (win) dp.push_back(1);
            else dp.push_back(0);
        }
        return dp[n-1];
    }
};