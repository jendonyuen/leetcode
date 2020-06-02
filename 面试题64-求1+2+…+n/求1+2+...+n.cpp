class Solution {
    int res;
public:
    int sumNums(int n) {
        res += n;
        if (n == 1) return res;
        return sumNums(n-1);
    }
};