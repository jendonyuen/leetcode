class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (k == 0) break;
            n++;
            if (arr[i] - n >= k) {
                return n + k - 1;
            } else if (arr[i] - n > 0) {
                k -= arr[i] - n;
                n = arr[i];
            }
        }
        return n + k;
    }
};