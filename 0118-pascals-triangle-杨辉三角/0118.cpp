class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(numRows);
        
        for (int i = 0; i < numRows; ++i) {
            v[i] = vector<int>(i+1, 1);
            for(int p = 1; p <= i - 1; ++p) {
                v[i][p] = v[i-1][p-1] + v[i-1][p];
            }
        }

        return v;
    }
};