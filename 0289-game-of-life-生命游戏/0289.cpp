class Solution {

    // 0-dead
    // 1-live
    // 2-dead-dead
    // 3-dead-live
    // 4-live-dead
    // 5-live-live
    inline void liveOrDie(vector<vector<int>>& board, int &y, int &x, int &h, int &w) {
        int liveAround = 0;
        // 第一排
        if (y > 0 && x > 0) {
            if (board[y-1][x-1] > 3) liveAround++;
        }
        if (y > 0) {
            if (board[y-1][x] > 3) liveAround++;
        }
        if (y > 0 && x < w - 1) {
            if (board[y-1][x+1] > 3) liveAround++;
        }

        // 第二排
        if (x > 0) {
            if (board[y][x-1] > 3) liveAround++;
        }
        if (x < w - 1) {
            liveAround += board[y][x+1];
        }

        // 第三排
        if (y < h - 1 && x > 0) {
            liveAround += board[y+1][x-1];
        }
        if (y < h - 1) {
            liveAround += board[y+1][x];
        }
        if (y < h - 1 && x < w - 1) {
            liveAround += board[y+1][x+1];
        }

        if (liveAround < 2 || liveAround > 3) {
            board[y][x] = board[y][x] ? 4 : 2;
        } else if (liveAround == 3) {
            board[y][x] = board[y][x] ? 5 : 3;
        } else {
            board[y][x] = board[y][x] ? 5 : 2;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int h = board.size();
        if (h == 0) return;
        int w = board[0].size();
        if (w == 0) return;
        
        for (int y = 0; y != h; y++) {
            for (int x = 0; x != w; x++) {
                liveOrDie(board, y, x, h, w);
            }
        }
        for (int y = 0; y != h; y++) {
            for (int x = 0; x != w; x++) {
                board[y][x] = board[y][x] % 2 ? 1 : 0;
            }
        }
    }
};