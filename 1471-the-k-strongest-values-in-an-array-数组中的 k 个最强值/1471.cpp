class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if (k == arr.size()) return arr;
        sort(arr.begin(), arr.end());
        int mid = arr[(arr.size() - 1) / 2];
        int left = 0;
        int right = arr.size() - 1;
        vector<int> res;
        // cout << "mid:" << mid << endl;
        while (res.size() < k) {
            int t1 = abs(arr[left] - mid);
            int t2 = abs(arr[right] - mid);
            // cout << t1 << " : " << t2 << endl;
            if (t1 > t2) {
                res.push_back(arr[left]);
                left++;
            } else if (t1 < t2) {
                res.push_back(arr[right]);
                right--;
            } else {
                if (left > right) {
                    res.push_back(arr[left]);
                    left++;
                } else {
                    res.push_back(arr[right]);
                    right--;
                }
            }
        }
        return res;
    }
};