class Solution {
private:
    inline void insert(vector<int>& A, int index, int value) {
        for(int i = A.size() - 1; i > index; --i) {
            A[i] = A[i-1];
        }
        A[index] = value;
    }
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int j = 0;
        for(int i = 0; i < B.size(); ++i) {
            while(true) {
                if(A[j] > B[i] || j >= m + i) {
                    insert(A, j, B[i]);
                    break;
                }
                ++j;
            }
        }
    }
};