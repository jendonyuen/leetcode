class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long high = 0, low = INT_MIN;
        for (auto &n : nums) {
            low = n > low ? n : low;
            high += n;
        }

        while(low < high) {
            long mid = (low + high) / 2;
            long count = 1, t = 0;
            for (auto &n : nums) {
                if (t + n > mid) {
                    count++;
                    t = n;
                } else {
                    t += n;
                }
            }
            if (count > m) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};