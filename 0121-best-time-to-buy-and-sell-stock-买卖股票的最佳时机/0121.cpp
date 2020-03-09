class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)return 0;
        int buy = prices[0];
        int sell = prices[1];
        int price = 0;
        for(int i = 1; i != prices.size(); ++i) {
            if (prices[i] < buy) {
                buy = prices[i];
                sell = prices[i];
            }
            if (prices[i] > sell) {
                sell = prices[i];
            }
            if (sell - buy > price) price = sell - buy;
        }
        return price;
    }
};