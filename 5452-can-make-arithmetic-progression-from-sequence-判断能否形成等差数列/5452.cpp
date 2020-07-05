class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> us;
        int min = INT_MAX, max = INT_MIN;
        for (auto &a: arr) {
            us.insert(a);
            if (min > a) min = a;
            if (max < a) max = a;
        }
        if ((max - min) % (n-1) != 0) return false;
        int d = (max - min) / (n - 1);
        for (int i = 0; i < n; ++i) {
            int a = min + i * d;
            if (!us.count(a)) return false;
        }
        return true;
    }
};