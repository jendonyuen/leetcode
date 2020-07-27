// 解法1: 结果为前缀和中奇数个数+偶数个数*奇数个数
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long sum = 0;
        vector<long long> v(2, 0);
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum & 1) {
                v[1]++;
            } else {
                v[0]++;
            }
        }
        return fmod(v[0] * v[1] + v[1], 1e9+7);

    }
};

// 解法2
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long sum = 0;
        int odd = 0, even = 1;
        long long res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum % 2) {
                res += even;
                odd++;
            } else {
                res += odd;
                even++;
            }
        }
        return fmod(res, 1e9+7);
    }
};