class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<pair<int, int>> v;
        for (int i = 0; i < T.size(); ++i) {
            while(!v.empty() && T[i] > v.top().first) {
                int j = v.top().second;
                res[j] = i - j;
                v.pop();
            }
            v.push(make_pair(T[i], i));
        }
        return res;
    }
};