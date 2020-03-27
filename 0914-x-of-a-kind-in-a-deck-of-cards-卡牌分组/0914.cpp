class Solution {
    // define minimum common divisor( >= 2)
    int gcd(int a, int b) {
        if (a < b) swap(a, b);
        return b == 0 ? a : gcd(b, a % b);
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        int table[10000] = {0};
        for (auto &n : deck) {
            table[n]++;
        }
        int X = table[0];
        for (auto &n : table) {
            if (n) X = gcd(n, X);
        }

        return X >= 2;
    }
};