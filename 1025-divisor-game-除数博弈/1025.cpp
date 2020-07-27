// dp
class Solution {
public:
    bool divisorGame(int N) {
        vector<int> dp(N + 1, 0);
        for (int i = 2; i <= N; ++i) {
            for (int j = i - 1; j > 0; --j) {
                if (!(i % j) && !dp[i - j]) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp.back();
    }
};


/* math
class Solution {
public:
    bool divisorGame(int N) {
        return !(N % 2);
    }
};
*/