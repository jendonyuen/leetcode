class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> res{0, n - 1};
        if (n < 2) return res;
        int sum = numbers[res[0]] + numbers[res[1]];
        
        while(sum != target) {
            if (sum > target) {
                res[1]--;
            } else {
                res[0]++;
            }
            sum = numbers[res[0]] + numbers[res[1]];
        }
        res[0]++;
        res[1]++;
        return res;
    }
};