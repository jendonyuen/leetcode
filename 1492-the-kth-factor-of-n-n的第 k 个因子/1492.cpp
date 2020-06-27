// 第 29 场双周赛

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors = {1};
        for (int i = 2; i <= n; ++i) {
            if (n % i == 0)
            factors.push_back(i);
        }
        if (factors.size() < k) return -1;
        return factors[k-1];
    }
};