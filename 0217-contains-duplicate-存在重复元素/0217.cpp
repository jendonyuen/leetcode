class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, int> m;
        for (auto &num: nums) {
            m[num] = 0;
        }
        if (nums.size() != m.size()) {
            return true;
        }
        return false;
    }
};