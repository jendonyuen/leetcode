class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty())return;
        int temp;
        int n = matrix.size();
        // 主对角线翻转
        for(int i = 0;i!=n;++i){
            for(int j = i+1;j!=n;++j){
                matrix[i][j] = matrix[i][j]+matrix[j][i];
                matrix[j][i] = matrix[i][j]-matrix[j][i];
                matrix[i][j] = matrix[i][j]-matrix[j][i];
            }
        } 
        // 水平翻转
        for(int i = 0;i!=n;++i){
            for(int j = 0;j!=n/2;++j){
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1]= temp;
            }
        }
    }
};