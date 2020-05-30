// 第 27 场双周赛

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> map;
        for (int i = 0; i < target.size(); ++i) {
            map[target[i]]++;
        }
        for (int i = 0; i < arr.size(); ++i) {
            if (map.find(arr[i]) == map.end()) {return false;}
            map[arr[i]]--;
        }
        for (auto &a : map) {
            if (a.second != 0) return false;
        }
        return true;
    }
};