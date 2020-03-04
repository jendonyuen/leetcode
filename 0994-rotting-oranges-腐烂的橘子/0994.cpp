using std::map;
using std::pair;
using std::make_pair;

class Solution {
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        map<pair<int, int>, bool*> goodOrgs;
        map<pair<int, int>, bool*> badOrgs;
        
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        if (w == 0) return 0;

        for(int y = 0; y != h; ++y) {
            for(int x = 0; x != w; ++x) {
                if (grid[y][x] == 1) {
                    goodOrgs[make_pair(y, x)] = NULL;
                }
                else if (grid[y][x] == 2) {
                    badOrgs[make_pair(y, x)] = NULL;
                }
            }
        }

        int time = 0;
        int lastGoodOrgsNumber = -1;
        while(goodOrgs.size() > 0) {
            if (lastGoodOrgsNumber == goodOrgs.size()) return -1;

            lastGoodOrgsNumber = goodOrgs.size();
            map<pair<int, int>, bool*> newBadOrgs;

            for (auto it = badOrgs.begin(); it != badOrgs.end(); ++it) {
                auto y = (*it).first.first;
                auto x = (*it).first.second;
                std::vector<pair<int, int>> delGoodOrgs;
                if (y > 0) {
                    if (goodOrgs.find(make_pair(y-1, x)) != goodOrgs.end()) {
                        delGoodOrgs.push_back(make_pair(y-1, x));
                        newBadOrgs[make_pair(y-1, x)] = NULL;
                    }
                }
                if (y < h-1) {
                    if (goodOrgs.find(make_pair(y+1, x)) != goodOrgs.end()) {
                        delGoodOrgs.push_back(make_pair(y+1, x));
                        newBadOrgs[make_pair(y+1, x)] = NULL;
                    }
                }
                if (x > 0) {
                    if (goodOrgs.find(make_pair(y, x-1)) != goodOrgs.end()) {
                        delGoodOrgs.push_back(make_pair(y, x-1));
                        newBadOrgs[make_pair(y, x-1)] = NULL;
                    }
                }
                if (x < w-1) {
                    if (goodOrgs.find(make_pair(y, x+1)) != goodOrgs.end()) {
                        delGoodOrgs.push_back(make_pair(y, x+1));
                        newBadOrgs[make_pair(y, x+1)] = NULL;
                    }
                }
                for (const auto &a: delGoodOrgs) {
                    goodOrgs.erase(a);
                }
            }
            badOrgs = newBadOrgs;
            time++;
        }

        return time;
         
    }
};