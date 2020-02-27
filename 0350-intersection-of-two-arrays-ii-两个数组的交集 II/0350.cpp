#include <map>
class Solution {
    map<int, int> table;
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> v;
        for (const auto &a: nums1) {
            if (table.find(a) == table.end()) {
                table[a] = 1;
            } else {
                table[a]++;
            }
        }
        for (const auto &a: nums2) {
            if (table.find(a) != table.end()) {
                if (table[a] > 0) {
                    v.push_back(a);
                    table[a]--;
                }
            }
        }
        return v;
    }
};