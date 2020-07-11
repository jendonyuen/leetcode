class Solution {
    // 模拟除法, 保留20位小数
    string mod(int numerator, int denominator, int n = 20) {
        if (numerator == 0) return "0";
        string res;
        if (numerator > 0 ^ denominator > 0) {
            res.push_back('-');
        }
        if (numerator < 0) numerator = -numerator;
        if (denominator < 0) denominator = -denominator;
        while (numerator >= denominator) {
            int t = numerator / denominator;
            res += to_string(t);
            numerator = numerator % denominator; 
        }
        if (res == "" or res == "-") res.push_back('0');
        if (numerator == 0) return res;
        res.push_back('.');
        for (int i = 0; i < n; ++i) {
            if (numerator == 0) break;
            numerator *= 10;
            res.push_back(numerator / denominator + '0');
            numerator = numerator % denominator;
        }
        return res;
    }
    /* 
    Ax + By + C = 0
    A = y2 - y1
    B = x1 - x2
    C = x2*y1 - x1*y2
    */
    string getLine(vector<int>& p1, vector<int>& p2) {
        long long a, b, c, x1 = p1[0], x2 = p2[0], y1 = p1[1], y2 = p2[1];
        a = y2 - y1;
        b = x1 - x2;
        c = x2 * y1 - x1 * y2;
        // 归一化
        // cout << mod((a-c), a) << "     " << mod((b-c), a) << endl;
        if (a == 0 && b == 0) return to_string(p1[0])+","+to_string(p1[1])+"0"; // 返回x,y,0 
        if (a == 0) return{mod((b-c), b)};                                      // 返回b
        return mod((a-c), a)+","+mod((b-c), a);                                 // 返回a,b
        
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // process same points
        map<vector<int>, int> same;
        for (auto &p: points) {
            same[p]++;
            if (same[p] > 1) {
                p.push_back(same[p]);
            }
        }

        int res = 1;
        map<string, set<vector<int>>> map;
        for (int i = 0; i < points.size() - 1; ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                auto line = getLine(points[i], points[j]);
                map[line].insert(points[i]);
                map[line].insert(points[j]);
                res = max(int(map[line].size()), res);
            }
        }
        return res;
    }
};