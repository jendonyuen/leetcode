class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet;
        for (auto &n: nums) {
            numsSet.insert(n);
        }

        int res = 0;
        for (auto &n: numsSet) {
            // 如果有数比它小，跳过
            if (numsSet.find(n-1) != numsSet.end()) continue;
            int cur = n;
            int curLen = 1;
            // 从最小的数开始
            while (cur != INT_MAX && numsSet.find(++cur) != numsSet.end()) {
                curLen++;
            }
            res = curLen > res ? curLen : res;
        }
        return res;
    }
};