class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cur = numBottles;
        int res = cur;
        while(cur / numExchange) {
            int le = cur % numExchange;
            cur /= numExchange;
            res += cur;
            cur += le;
        } 
        return res;
    }
};