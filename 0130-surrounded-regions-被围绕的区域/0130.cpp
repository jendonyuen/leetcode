// 2020-08-11 每日一题
class Solution {
    vector<vector<int>> searched;
    int ySize, xSize;
    void dfs(vector<vector<char>>& board, int y, int x) {
        if (y < 0 || x < 0 || y >= ySize || x >= xSize) return;
        if (searched[y][x]) return;
        searched[y][x] = 1;
        if (board[y][x] != 'O') return;
        dfs(board, y+1, x);
        dfs(board, y, x+1);
        dfs(board, y-1, x);
        dfs(board, y, x-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        ySize = board.size();
        xSize = board[0].size();
        searched.resize(ySize, vector<int>(xSize, 0));
        // search edge
        for (int y = 0; y < ySize; ++y) dfs(board, y, 0);
        for (int x = 1; x < xSize; ++x) dfs(board, 0, x);
        for (int y = 1; y < ySize; ++y) dfs(board, y, xSize - 1);
        for (int x = 1; x < xSize; ++x) dfs(board, ySize - 1, x);

        // traverse inside
        for (int y = 1; y < ySize - 1; ++y) {
            for (int x = 1; x <xSize - 1; ++x) {
                if (!searched[y][x]) board[y][x] = 'X';
            }
        }
    }
};


// old
class Solution {
    int ySize, xSize;
    vector<vector<int>> searched;
    void edgeTraverse(vector<vector<char>>& board, int y, int x) {
        if (board[y][x] == 'X' || searched[y][x]) return;
        searched[y][x] = 1;
        if (y < ySize - 1) edgeTraverse(board, y+1, x);
        if (x < xSize - 1) edgeTraverse(board, y, x+1);
        if (y > 0) edgeTraverse(board, y-1, x);
        if (x > 0) edgeTraverse(board, y, x-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        this->ySize = board.size();
        if (ySize == 0) return;
        this->xSize = board[0].size();
        if (xSize == 0) return;
        searched.resize(ySize, vector<int>(xSize, 0));
        // 先搜索边界
        for (int x = 0; x < xSize; ++x) {
            edgeTraverse(board, 0, x);
        }
        for (int y = 1; y < ySize; ++y) {
            edgeTraverse(board, y, 0);
        }

        if (ySize > 1 && xSize > 1) {
            int edge = ySize - 1;
            for (int x = 1; x < xSize; ++x) {
                edgeTraverse(board, edge, x);
            }
            edge = xSize - 1;
            for (int y = 1; y < ySize; ++y) {
                edgeTraverse(board, y, edge);
            }
        }

        for (int y = 0; y < ySize; ++y) {
            for (int x = 0; x < xSize; ++x) {
                if (!searched[y][x]) board[y][x] = 'X';
            }
        }
    }
};