// 动态规划
/*
coins = [1, 2, 5], amount = 11
F(0)=0
F(1)=min(F(1−1),F(1−2),F(1−5))+1=1
F(2)=min(F(2−1),F(2−2),F(2−5))+1=1
F(3)=min(F(3−1),F(3−2),F(3−5))+1=2
F(4)=min(F(4−1),F(4−2),F(4−5))+1=2
...
F(amount)=min(F(amount−1),F(amount−2),F(amount−5))+1=?
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i < amount+1; i++) {
            for (auto &coin: coins) {
                if (i >= coin) dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        return dp.back() == amount+1 ? -1 : dp.back();
    }
};

/* 回溯法 超时
class Solution {
    int sum = 0;
    vector<int> v;
    int res = INT_MAX;
    void backTrack(vector<int>& coins, int& amount) {
        if (sum > amount) return;
        if (sum == amount) {
            res = res < v.size() ? res : v.size();
            return;
        } 
        for (int &coin: coins) {
            v.emplace_back(coin);
            sum += coin;
            backTrack(coins, amount);
            sum -= coin;
            v.pop_back();
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        backTrack(coins, amount);
        return res == INT_MAX ? -1 : res;
    }
};
*/