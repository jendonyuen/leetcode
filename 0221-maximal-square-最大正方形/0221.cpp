class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int side = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int path[rows][cols];
        for (int y = 0; y != rows; ++y) {
            for (int x = 0; x != cols; ++x) {
                if (matrix[y][x] == '1') {
                    // 动态规划, 记录当前位置(x, y)可以存在的最大正方形的边长
                    // 若当前位置为0, 则必定为0;
                    // 若当前位置为1, 则该位置为(左上, 上, 左)三个位置中最小的数值+1
                    int minNum = INT_MAX;
                    if (y == 0 || x == 0) path[y][x] = 1;
                    else path[y][x] = min(min(path[y-1][x], path[y-1][x-1]), path[y][x-1]) + 1;
                    if (path[y][x] > side) side = path[y][x];
                } else path[y][x] = 0;
                // cout << path[y][x] << ",";
            }
            // cout << endl;
        }
        return side * side;
    }
};