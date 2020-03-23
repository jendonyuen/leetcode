class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n-1)) == 0;
    }
    /*
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        bool one = false;
        while(n != 0) {
            if (n & 1 == 1) {
                if (!one) one = true;
                else return false;
            } 
            n >>= 1;
        }
        return true;
    }
    */
};