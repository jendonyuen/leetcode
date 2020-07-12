// 197th weekly contest

class Solution {
public:
    int numSub(string s) {
        long long res = 0;
        long long cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                cur++;
                res += cur;
            } else {
                cur = 0;
            }
        }
        return fmod(res, 1000000007);;
    }
};