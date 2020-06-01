// 第 191 场周赛
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int maxH = 0;
        int prev = 0;
        for (auto &y: horizontalCuts) {
           if (y - prev > maxH) maxH = y - prev;
            prev = y;
        }
        if (h - prev > maxH) maxH = h - prev;
        
        prev = 0;
        int maxW = 0;
        for (auto &x: verticalCuts) {
            if (x - prev > maxW) maxW = x - prev;
            prev = x;
        }
        if (w - prev > maxW) maxW = w - prev;
        // cout << maxW << "," << maxH << endl;
        double res = (double)maxW * (double)maxH;
        return fmod(res, 1000000007);
    }
};