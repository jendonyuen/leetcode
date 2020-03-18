class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = 0
        sell = 0
        profit = 0
        while(sell < len(prices) - 1):
            sell += 1
            curProfit = prices[sell] - prices[buy]
            if curProfit < 0:
                buy = sell
                continue
            if curProfit > profit:
                profit = curProfit
        return profit