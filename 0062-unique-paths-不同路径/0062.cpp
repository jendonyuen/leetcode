#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1) {
            return 1;
        }else if (n == 1) {
            return 1;
        }else if (m == 2) {
            return n;
        }else if (n == 2) {
            return m;
        }
        vector<int> v(100);
        mat = vector<vector<int>>(100, v);
        mat.push_back(v);
        mat[1][1] = 1;
        mat[2][1] = 1;
        mat[1][2] = 1;
        move(m, n);
        return mat[m][n];
    }
private:
    vector<vector<int>> mat;
    void move(int m, int n) {
        for (int x = 1; x <= m; ++x) {
            for (int y = 1; y <= n; ++y) {
                if (x > 2 && y > 2) {
                    mat[x][y] = mat[x-1][y] + mat[x][y-1];
                }else if(x==2) {
                    mat[x][y] = y;
                }else if(y==2) {
                    mat[x][y] = x;
                }
            }
        }
    }
    
};