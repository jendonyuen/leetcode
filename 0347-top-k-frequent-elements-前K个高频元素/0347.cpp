class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto &n : nums) {
            count[n]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto it = count.begin(); it != count.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > k) pq.pop();
        }

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto &n : nums) {
            count[n]++;
        }
        multiset<pair<int, int>> ms;
        for (auto it = count.begin(); it != count.end(); ++it) {
            ms.insert(make_pair((*it).second, (*it).first));
        }

        vector<int> res;
        auto it = ms.rbegin();
        for (int i = 0; i < k; ++i) {
            res.push_back((*it++).second);
        }
        return res;
    }
};
*/