class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int dpSold = 0;             // 当天未持有股票(之前卖出或当天卖出) 的最大收益
        int dpHold = INT_MIN;       // 当天持有股票 的最大收益
        int dpPrev = 0;             // 昨天未持有股票 的最大收益
        for (int i = 0; i < prices.size(); ++i) {
            auto temp = dpSold;
            dpSold = max(dpSold, prices[i] + dpHold);   // 之前卖出或当天卖出 的最大收益
            dpHold = max(dpHold, dpPrev - prices[i]);   // 之前买入或当天买入 的最大收益
            dpPrev = temp;
        }
        return dpSold;  // 最后一天卖掉所有股票才能获得最大收益
    }
};