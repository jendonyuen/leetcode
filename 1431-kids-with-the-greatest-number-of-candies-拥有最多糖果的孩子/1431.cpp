class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum = 0;
        for (auto &candy: candies) {
            maxNum = maxNum > candy ? maxNum : candy;
        }
        vector<bool> ans;
        for (auto &candy: candies) {
            ans.push_back(candy + extraCandies >= maxNum);
        }
        return ans;
    }
};