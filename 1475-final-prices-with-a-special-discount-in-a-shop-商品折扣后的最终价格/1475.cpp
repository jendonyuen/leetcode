class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        if (prices.empty()) return {};
        if (prices.size() == 1) return prices;
        vector<int> res;
        for (int i = 0; i < prices.size() - 1; ++i) {
            bool b = true;
            for (int j = i + 1; j < prices.size(); ++j) {
                if (prices[j] <= prices[i]) {
                    res.push_back(prices[i] - prices[j]);
                    b = false;
                    break;
                }
            }
            if (b) {
                res.push_back(prices[i]);
            }
        }
        res.push_back(prices.back());
        return res;
    }
};