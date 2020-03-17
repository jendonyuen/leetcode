class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        if (numRows == 0) return v;

        vector<int> t = {1};
        v.push_back(t);
        if (numRows == 1) return v;

        t.push_back(1);
        v.push_back(t);
        if (numRows == 2) return v;
        
        for (int i = 3; i <= numRows; ++i) {
            t = {1};
            for(int p = 1; p != i - 1; ++p) {
                t.push_back(v[i-2][p-1] + v[i-2][p]);
            }
            t.push_back(1);
            v.push_back(t);
        }

        return v;
    }
};