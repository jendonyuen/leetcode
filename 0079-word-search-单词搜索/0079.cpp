class Solution {
    // 回溯
    auto search(vector<vector<char>>& board, vector<vector<bool>>& searched, string& word, int i, int y, int x) {
        if (y < 0 || x < 0 || y == board.size() || x == board[0].size()) return false;
        if (searched[y][x] || word[i] != board[y][x]) return false;
        if (i == word.size() - 1) return true;
        i++;
        searched[y][x] = true;
        if (search(board, searched, word, i, y+1, x)) return true;
        if (search(board, searched, word, i, y, x+1)) return true;
        if (search(board, searched, word, i, y-1, x)) return true;
        if (search(board, searched, word, i, y, x-1)) return true;
        searched[y][x] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> searched(board.size(), vector<bool>(board[0].size(), false));
        for (int y = 0; y < board.size(); ++y) {
            for (int x = 0; x < board[0].size(); ++x) {
                if (search(board, searched, word, 0, y, x)) return true;
            }
        }
        return false;
    }
};
