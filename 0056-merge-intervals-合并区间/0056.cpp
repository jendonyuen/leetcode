class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < intervals.size(); i++) {
            int beg = intervals[i][0];
            int end = intervals[i][1];
            while (i+1 < intervals.size() && end >= intervals[i+1][0]) {
                end = max(end, intervals[i+1][1]);
                i++;
            }
            v.push_back({beg, end});
        }
        return v;
    }
};