class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> vBlock(9, vector<bool>(9, false));
        vector<vector<bool>> vRow(9, vector<bool>(9, false));
        vector<vector<bool>> vCol(9, vector<bool>(9, false));

        vector<tuple<int, int>> startPoints = {
            tuple(0, 0), tuple(0, 3), tuple(0, 6),
            tuple(3, 0), tuple(3, 3), tuple(3, 6),
            tuple(6, 0), tuple(6, 3), tuple(6, 6)
        };

        int bi = 0;
        for (auto [sx, sy]: startPoints) {
            for (int dy = 0; dy < 3; ++dy) {
                for (int dx = 0; dx < 3; ++dx) {
                    int x = sx+dx;
                    int y = sy+dy;
                    // cout << x << "," << y << " :" << board[y][x] << endl;
                    auto &c = board[y][x];
                    if (c != '.') {
                        int n = c - '0' - 1;
                        if (!vBlock[bi][n]) vBlock[bi][n] = true;
                        else return false;
                        if (!vRow[y][n]) vRow[y][n] = true;
                        else return false;
                        if (!vCol[x][n]) vCol[x][n] = true;
                        else return false;
                    }
                }
            }
            bi++;
        }

        return true;
    }
};