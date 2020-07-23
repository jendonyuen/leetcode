class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, mid = INT_MAX;
        for (auto &a : nums) {
            if (a <= min) {
                min = a;
            } else if (a <= mid) {
                mid = a;
            } else if (a > mid) {
                return true;
            }
        }
        return false;
    }
};