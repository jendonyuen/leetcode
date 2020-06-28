// 第195场周赛

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> us;
        int x = 10000;
        int y = 10000;
        us.insert(make_pair(x, y));
        for (auto &c:path) {
            if (c == 'N') {
                y++;
            } else if (c == 'S') {
                y--;
            } else if (c == 'E') {
                x++;
            } else {
                x--;
            }
            auto coord = make_pair(x, y);
            if (us.find(coord) != us.end()) return true;
            else us.insert(coord);
        }
        return false;
    }
};