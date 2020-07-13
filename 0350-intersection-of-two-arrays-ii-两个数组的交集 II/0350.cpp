class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> res;
        for (auto &a : nums1) {
            um[a]++;
        }
        for (auto &a : nums2) {
            if (um.count(a)) {
                if (um[a] > 0) {
                    um[a]--;
                    res.push_back(a);
                }
            }
        }
        return res;
    }
};