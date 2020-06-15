class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> um;
        priority_queue<int, vector<int>, greater<>> pq;
        for (int i = 0; i < arr.size(); ++i) {
            um[arr[i]]++;
        }
        for (auto &a : um) {
            pq.push(a.second);
        }
        
        // cout << pq.top() << "," << pq.size() << endl;
        while(pq.size() > 0 && k - pq.top() >= 0) {
            k -= pq.top();
            pq.pop();
        }
        return pq.size();
    }
};