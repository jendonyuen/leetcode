class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)return 0;
        int buy = prices[0];
        int price = 0;
        for(int i = 1; i != prices.size(); ++i) {
            buy = prices[i] < buy ? prices[i] : buy;
            price = prices[i] - buy > price ? prices[i] - buy : price;
        }
        return price;
    }
};


/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int buy = prices[0];
        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            buy = min(buy, prices[i]);
            res = max(res, prices[i] - buy);
        }
        return res;
    }
};
*/