class Solution {
    // 模拟, 耗时较久
public:
    char findKthBit(int n, int k) {
        bitset<1048576> bs;
        int cur = 1;
        for(int i = 2; i <= n; ++i) {
            cur *= 2;
            int mid = cur - 1;
            bs[mid] = 1;
            for (int j = 1; j <= mid; ++j) {
                bs[mid + j] = bs[mid - j] ? 0 : 1; 
            }
            
            // for (int j = 0; j < cur * 2 - 1; ++j) {
            //     cout << bs[j];
            // } cout << endl;
        }
        return bs[k-1] + '0';
    }
};