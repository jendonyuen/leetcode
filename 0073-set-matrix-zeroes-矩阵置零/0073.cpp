// 将需要置0的[行/列]标记在[行首/列首]
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        bool setFirstRowZero = false;
        bool setFirstColZero = false;
        // [1]检查第一行第一列是否含0, 若含0则在第[4]步置0
        for (int y = 0; y < matrix.size(); ++y) {
            if (matrix[y][0] == 0) {
                setFirstColZero = true;
                break;
            }
        }
        for (int x = 0; x < matrix[0].size(); ++x) {
            if (matrix[0][x] == 0) {
                setFirstRowZero = true;
                break;
            }
        }

        // [2]检查需要置零的行列, 将其标记在第一行第一列
        for (int y = 1; y < matrix.size(); ++y) {
            for (int x = 1; x < matrix[0].size(); ++x) {
                if (matrix[y][x] == 0) {
                    matrix[y][0] = 0;
                    matrix[0][x] = 0;
                }
            }
        }

        // [3]根据第一行第一列的标记，对应置零
        // 注意: 需要忽略matrix[0][0]元素, 交由第[4]步检查
        for (int y = 1; y < matrix.size(); ++y) {
            if (matrix[y][0] == 0) {
                for (int x = 1; x < matrix[0].size(); ++x) {
                    matrix[y][x] = 0;
                }
            }
        }
        for (int x = 1; x < matrix[0].size(); ++x) {
            if (matrix[0][x] == 0) {
                for (int y = 1; y < matrix.size(); ++y) {
                    matrix[y][x] = 0;
                }
            }
        }

        // [4]检查第一行第一列是否需要置零
        if (setFirstColZero) {
            for (int y = 0; y < matrix.size(); ++y) matrix[y][0] = 0;
        }
        if (setFirstRowZero) {
            for (int x = 0; x < matrix[0].size(); ++x) matrix[0][x] = 0;
        }
    }
};

/* 矩阵内数字可能与flag冲突
class Solution {
    int flag = INT_MIN + 4321;
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        for (int y = 0; y < matrix.size(); ++y) {
            for (int x = 0; x < matrix[0].size(); ++x) {
                if (matrix[y][x] == 0) {
                    int yi = 0;
                    for (; yi < y; ++yi) matrix[yi][x] = 0;
                    for (yi++; yi < matrix.size(); ++yi) {
                        if (matrix[yi][x]) matrix[yi][x] = flag;
                    }
                    int xi = 0; 
                    for (; xi < x; ++xi) matrix[y][xi] = 0;
                    for (++xi; xi < matrix[0].size(); ++xi) {
                        if (matrix[y][xi]) matrix[y][xi] = flag;
                    }
                } else if (matrix[y][x] == flag) matrix[y][x] = 0;
            }
        }
    }
};
*/