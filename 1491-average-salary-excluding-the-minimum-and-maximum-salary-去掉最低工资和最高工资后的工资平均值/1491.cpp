// 第 29 场双周赛

class Solution {
public:
    double average(vector<int>& salary) {
        double res = 0, high = INT_MIN, low = INT_MAX;
        for (int i = 0; i < salary.size(); ++i) {
            res += salary[i];
            if (salary[i] > high) high = salary[i];
            if (salary[i] < low) low = salary[i];
        }
        int n = salary.size() - 2;
        res = (res - high - low) / n;
        return res;
    }
};