class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> gardens(N);
        for(auto &path: paths) {
           gardens[path[0]-1].push_back(path[1]-1);
           gardens[path[1]-1].push_back(path[0]-1); 
        }

        vector<int> flower(N, 0);
        int index = 0;
        for(auto &garden: gardens) {
            int kind = 1;
            while(true){
                int find = kind;
                for (auto &adj: garden) {
                    if (flower[adj] == kind) kind++;
                }
                if (find == kind) break;
            }
            flower[index] = kind;
            index++;
        }
        
        return flower;
    }
};