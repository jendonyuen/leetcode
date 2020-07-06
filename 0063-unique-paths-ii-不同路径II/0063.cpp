// 动态规划, 矩阵中每个点的值表示该点能贡献的路径数量
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0][0]) return 0;
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        // init
        dp[0][0] = 1;
        for (int x = 1; x < cols; ++x) {
            if (obstacleGrid[0][x] == 0) dp[0][x] = dp[0][x-1];
        }
        for (int y = 1; y < rows; ++y) {
            if (obstacleGrid[y][0] == 0) dp[y][0] = dp[y-1][0];
        }

        for (int y = 1; y < rows; ++y) {
            for (int x = 1; x < cols; ++x) {
                if (obstacleGrid[y][x]) continue;
                dp[y][x] = dp[y-1][x] + dp[y][x-1];
            }
        }

        return dp.back().back();
    }
};


/* 回溯法, 超时
class Solution {
    int rows, cols, res = 0;
    void backTrack(vector<vector<int>>& grid, int y, int x) {
        if (grid[y][x]) return;
        if (y == rows-1 && x == cols-1) {
            res++;
            return;
        } 
        if (x < cols - 1) {
            x++;
            backTrack(grid, y, x);
            x--;
        } 
        if (y < rows - 1) {
            y++;
            backTrack(grid, y, x);
            y--;
        }
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        this->rows = obstacleGrid.size();
        if (rows == 0) return -1;
        this->cols = obstacleGrid[0].size();
        backTrack(obstacleGrid, 0, 0);
        return res;
    }
};
*/