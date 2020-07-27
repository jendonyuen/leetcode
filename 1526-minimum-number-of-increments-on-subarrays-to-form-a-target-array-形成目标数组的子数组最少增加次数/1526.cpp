// 考虑左侧元素对该元素的贡献
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = 0;
        vector<int> v(target.size(), 0);
        res += target[0];
        for (int i = 1; i < target.size(); ++i) {
            res += max(target[i] - target[i-1], 0);
        }
        return res;
    }
};