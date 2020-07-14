class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // bottom up dp, O(n) extra space
        // 动态规划, 自下而上, 保存下一行的信息
        vector<int> dp(triangle.size(), INT_MAX);
        for (int x = 0; x < triangle.back().size(); ++x) {
            dp[x] = triangle.back()[x];
        }
        for (int y = triangle.size() - 2; y >= 0; --y) {
            for (int x = 0; x < triangle[y].size(); ++x) {
                dp[x] = triangle[y][x] + min(dp[x], dp[x+1]);
            }
        }

        return dp[0];
    }
};

/*
// 更改输入数组的原地算法
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // bottom up dp, modify source array
        for (int y = triangle.size() - 2; y >= 0; --y) {
            for (int x = 0; x < triangle[y].size(); ++x) {
                triangle[y][x] += min(triangle[y+1][x], triangle[y+1][x+1]);
            }
        }

        return triangle[0][0];
    }
};
*/

/* 超时
class Solution {
    int res = INT_MAX;
    int cur = 0;
    void backTrack(vector<vector<int>>& triangle, int y, int x) {
        if (x >= triangle[y].size()) return;
        if (y == triangle.size() - 1) {
            cur += triangle[y][x];
            res = min(cur, res);
            cur -= triangle[y][x];
            return;
        }
        cur += triangle[y][x];
        backTrack(triangle, y+1, x);
        backTrack(triangle, y+1, x+1);
        cur -= triangle[y][x];
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        backTrack(triangle, 0, 0);
        return res;
    }
};
*/