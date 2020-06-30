/* 动态规划
unordered_map<int, int> mp;         // 记录前缀和
vector<int> v(arr.size(), INT_MAX); // 记录截至当前位置, 和为target的最小长度(动态规划)
若子数组[i, j]满足条件, 检查v[i]是否有满足条件的长度(同时避免了重叠), 若有则必有满足条件的两个数组

*/
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        unordered_map<int, int> mp;         // [prefixSum] = index
        vector<int> v(arr.size(), INT_MAX); // 记录当前位置的最小长度
        int res = INT_MAX;
        int sum = arr[0];
        mp[0] = -1;                         // 用于sum正好为target时的计算
        mp[sum] = 0;
        if (sum == target) v[0] = 1;
        for (int i = 1; i < arr.size(); ++i) {
            sum += arr[i];
            v[i] = v[i-1];
            mp[sum] = i;
            int t = sum - target;
            if (mp.count(t)) {
                v[i] =  min(v[i], i - mp[t]);
                if (mp[t] > 0 && v[mp[t]] != INT_MAX) {
                    res = min(res, v[mp[t]] + i - mp[t]);
                }
            } 
        }

        return res == INT_MAX ? -1 : res;
    }
};


/* 周赛-超时
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int> v(arr.size(), -1);
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) {
                // pq.push(1);
                v[i] = 1;
                continue;
            }
            int t = arr[i];
            for (int j = i + 1; j < arr.size(); ++j) {
                t += arr[j];
                if (t == target) {
                    int len = j - i + 1;
                    // pq.push(len);
                    v[i] = len;
                    break;
                }
            }
        }
        
        int res = INT_MAX;
        for (int i = 0; i < arr.size() - 1; ++i) {
            // cout << v[i] << endl;
            if (v[i] > 0) {
                for (int j = i + v[i]; j < arr.size(); ++j) {
                    if (v[j] > 0) {
                        // cout << "find:" << v[j] << endl;
                        res = v[i] + v[j] < res ? v[i] + v[j] : res;
                    }
                }
            }
        }
        if (res == INT_MAX) return -1;
        
        return res;
    }
};
*/