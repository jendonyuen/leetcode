class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        col = len(dungeon)
        if not col:
            return
        row = len(dungeon[0])
        dp = [max(1, 1-dungeon[col - 1][row - 1])]
        for y in range (col-2, -1, -1):
            dp.insert(0, max(1, dp[0] - dungeon[y][row - 1]))
        for x in range (row-2, -1, -1):
            dp[col-1] = max(1, dp[col-1] - dungeon[col-1][x])
            for y in range (col-2, -1, -1):
                dp[y] = max(1, min(dp[y] - dungeon[y][x], dp[y+1] - dungeon[y][x]))
                
        return dp[0]
        