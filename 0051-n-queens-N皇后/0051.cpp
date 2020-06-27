class Solution {
    int n;
    vector<vector<string>> res;
    vector<string> board;
    vector<int> vertical;   // 竖直方向
    vector<int> horizantal; // 水平方向
    vector<int> slash;      // 斜方向"\"
    vector<int> slashBack;  // 反斜方向"/"
    
    bool check(int y, int x) {
        if (vertical[x]) return false;
        if (horizantal[y]) return false;
        if (slash[n+y-x-1]) return false;
        if (slashBack[x+y]) return false;
        vertical[x] = 1;
        horizantal[y] = 1;
        slash[n+y-x-1] = 1;
        slashBack[x+y] = 1;
        board[y][x] = 'Q';
        return true;
    }

    void recovery(int y, int x) {
        vertical[x] = 0;
        horizantal[y] = 0;
        slash[n+y-x-1] = 0;
        slashBack[x+y] = 0;
        board[y][x] = '.';
    }
    
    void backTrack(int y, int x) {
        if (not check(y, x)) {
            return;
        }
        ++y;
        if (y >= n) {
            res.push_back(board);
            recovery(y-1, x);
            return;
        }
        for (int x = 0; x < n; ++x) {
            // printf("%d %d\n", y, x);
            backTrack(y, x); 
        }
        recovery(y-1, x);
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return {{}};
        if (n == 1) return {{"Q"}};
        this->n = n;
        string s(n, '.');
        board.resize(n, s);
        vertical.resize(n, 0);
        slash.resize(2*n, 0);
        slashBack.resize(2*n, 0);
        horizantal.resize(n, 0);
        for (int x = 0; x < n; ++x) {
            backTrack(0, x);
        }
        return res;
    }
};