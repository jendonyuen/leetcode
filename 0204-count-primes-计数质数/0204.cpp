class Solution {
public:
    int countPrimes(int n) {
        if (n == 0) return 0;
        bool arr[n];
        for (int i = 0; i < n; ++i) arr[i] = true;
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i] == true) {
                count += 1;
            }
            for (int j = 0; i * j < n; ++j) {
                arr[i * j] = false;
            }
        }
        return count;
    }
};