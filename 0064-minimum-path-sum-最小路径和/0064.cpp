class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), INT_MAX));
        dp[0][0] = grid[0][0];
        for (int y = 1; y < grid.size(); ++y) {
            dp[y][0] = grid[y][0] + dp[y-1][0];
        }
        for (int x = 1; x < grid[0].size(); ++x) {
            dp[0][x] = grid[0][x] + dp[0][x-1]; 
        }

        for (int y = 1; y < grid.size(); ++y) {
            for (int x = 1; x < grid[0].size(); ++x) {
                dp[y][x] = grid[y][x] + min(dp[y-1][x], dp[y][x-1]);
            }
        }

        return dp.back().back();
    }
};