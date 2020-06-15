class SubrectangleQueries {
    vector<vector<int>> rect;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int y = row1; y <= row2; ++y) {
            for (int x = col1; x <= col2; ++x) {
                rect[y][x] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rect[row][col];
    }
};
