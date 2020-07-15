class Solution {
    double getDist(vector<vector<int>>& positions, double x, double y) {
        double d = 0;
        for (auto &p: positions) {
            d += sqrt(pow((p[0] - x), 2) + pow((p[1]- y), 2));
        }
        return d;
    }
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double x, y, stride = 1, n = positions.size();
        for (auto &p: positions) {
            x += p[0];
            y += p[1];
        }
        x /= n;
        y /= n;
        
        double curDist, prevDist = getDist(positions, x, y);
        // 向四个方向搜索, 搜索到距离更小的点就采用该点
        // 若搜索不到则步长减半 
        while (stride > 0.00000001) {
            curDist = getDist(positions, x + stride, y);
            if (curDist < prevDist) {
                x = x + stride;
                prevDist = curDist;
                continue;
            } 

            curDist = getDist(positions, x - stride, y);
            if (curDist < prevDist) {
                x = x - stride;
                prevDist = curDist;
                continue;
            } 

            curDist = getDist(positions, x, y + stride);
            if (curDist < prevDist) {
                y = y + stride;
                prevDist = curDist;
                continue;
            } 

            curDist = getDist(positions, x, y - stride);
            if (curDist < prevDist) {
                y = y - stride;
                prevDist = curDist;
                continue;
            } 

            // 没有找到更小的, 步长减半
            stride /= 2;
        }

        return getDist(positions, x, y);

    }
};