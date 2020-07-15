class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        for (int i = 1; i * i <= n; i++) {
            dp[i * i] = 1;
        }
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (dp[i] == 1) continue;
            for (int j = 1; j*j < i; ++j) { // 检查所有平方数
                dp[i] = min(dp[i], dp[i-j*j] + dp[j*j]);
                if (dp[i] == 2) break;
            }
        }
        return dp.back();
    }
};