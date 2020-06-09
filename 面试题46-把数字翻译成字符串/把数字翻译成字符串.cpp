class Solution {
    int res = 1;
public:
    int translateNum(int num) {
        if (num < 10) {
            return res;
        } 
        
        int t = num;
        int i = 0;
        while(t >= 100) {
            t /= 10;
            i++;
        }
        if (t < 26) {
            res++;
            translateNum(num - t * pow(10, i));
        } 
        t /= 10;
        translateNum(num - t * pow(10, i+1));

        return res;
    }
};