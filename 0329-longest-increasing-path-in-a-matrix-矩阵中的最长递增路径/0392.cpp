class Solution {
    int res = 0;
    vector<vector<int>> v;
    int ysize, xsize;
    int dfs(vector<vector<int>>& matrix, int y, int x) {
        if (v[y][x] > 1) return v[y][x];
        if (ysize > y+1 && matrix[y+1][x] > matrix[y][x]) v[y][x] = 1 + dfs(matrix, y+1, x);
        if (xsize > x+1 && matrix[y][x+1] > matrix[y][x]) v[y][x] = max(1 + dfs(matrix, y, x+1), v[y][x]);
        if (y > 0 && matrix[y-1][x] > matrix[y][x]) v[y][x] = max(1 + dfs(matrix, y-1, x), v[y][x]);
        if (x > 0 && matrix[y][x-1] > matrix[y][x]) v[y][x] = max(1 + dfs(matrix, y, x-1), v[y][x]);
        res = max(res, v[y][x]);
        return v[y][x];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        v.resize(matrix.size(), vector<int> (matrix[0].size(), 1));
        ysize = matrix.size();
        xsize = matrix[0].size();
        for (int y = 0; y < matrix.size(); ++y) {
            for (int x = 0; x < matrix[0].size(); ++x) {
                dfs(matrix, y, x);
            }
        }
        return res;
    }
};