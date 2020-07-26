class Solution {
public:
    int minFlips(string target) {
        int count = 0;
        int cur = 0;
        for (int i = 0; i < target.size(); ++i) {
            if (target[i] - '0' != cur) {
                cur = cur == 1 ? 0 : 1;
                count++;
            }
        }
        return count;
    }
};