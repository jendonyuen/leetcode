int gcd(int a, int b) {
    if (a < b) std::swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int j = 2; j <= n; ++j) {
            for (int i = 1; i < j; ++i) {
                if (gcd(i, j) != 1) continue;
                res.push_back(to_string(i) + "/" + to_string(j));
            }
        }
        return res;
    }
};