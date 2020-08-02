class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k >= arr.size()) return *max_element(arr.begin(), arr.end());
        int c = 0;
        int p = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (c >= k) return arr[p];
            if (arr[p] > arr[i]) {
                c++;
            } else {
                p = i;
                c = 1;
            }
        }
        return arr[p];
    }
};