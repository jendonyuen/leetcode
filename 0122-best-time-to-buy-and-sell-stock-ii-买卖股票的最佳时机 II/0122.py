class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        dayNum = len(prices)
        if dayNum < 2:
            return 0

        profit = 0
        for buy in range(dayNum - 1):
            cur = prices[buy+1] - prices[buy]
            if cur > 0:
                profit += cur

        return profit 