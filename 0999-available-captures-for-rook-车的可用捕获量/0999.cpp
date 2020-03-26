class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int h = board.size();
        if (h == 0) return 0;
        int w = board[0].size();
        int num = 0;
        for (int y = 0; y != h; ++y) {
            for (int x = 0; x != w; ++x) {
                if (board[y][x] == 'R') {
                    for (int y1 = y - 1; y1 >= 0; --y1) {
                        if (board[y1][x] == 'B') break;
                        if (board[y1][x] == 'p') {
                            num++;
                            break;
                        }
                    }
                    for (int x1 = x - 1; x1 >= 0; --x1) {
                        if (board[y][x1] == 'B') break;
                        if (board[y][x1] == 'p') {
                            num++;
                            break;
                        }
                    }
                    for (int y2 = y + 1; y2 < h; ++y2) {
                        if (board[y2][x] == 'B') break;
                        if (board[y2][x] == 'p') {
                            num++;
                            break;
                        }
                    }
                    for (int x2 = x + 1; x2 < w; ++x2) {
                        if (board[y][x2] == 'B') break;
                        if (board[y][x2] == 'p') {
                            num++;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return num;
    }
};