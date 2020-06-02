class Solution {
    int res;
public:
    int sumNums(int n) {
        res += n;
        n && sumNums(n-1);
        return res;
    }
};