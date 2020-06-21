class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        list<int> drain;
        vector<int> res(rains.size(), -1);
        unordered_map<int, int> lake;   // key:lakeIndex, value:rainDay
        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                drain.push_back(i);
                res[i] = 999;
            } else {
                if (lake.find(rains[i]) != lake.end()) {
                    if (drain.size() > 0) {
                        if (drain.back() < lake[rains[i]]) return {};
                        auto p = drain.begin();
                        for (; p != drain.end(); ++p) {
                            if (*p >= lake[rains[i]]) {
                                break;
                            }
                        }
                        res[*p] = rains[i];
                        const auto t = p;
                        drain.erase(p);
                        lake[rains[i]] = i;
                    } else {
                        return {};
                    }
                } else {
                    lake[rains[i]] = i;
                }
            }
        }
        return res;
    }
};