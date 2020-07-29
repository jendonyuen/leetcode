#include <bits/stdc++.h>
 
using namespace std;
 
class Solution {
    vector<int> v = {1};
public:
    int calc(int n) {
        for (int i = v.size(); i <= n; ++i) {
            int sq = i * i;
            string sqStr = to_string(sq);
            string iStr = to_string(i);
            sqStr = sqStr.substr(sqStr.size() - iStr.size(), iStr.size());
            int cur = v[i-1];
            if (sqStr == iStr) cur++;
            v.push_back(cur);
        }
        return v[n];
    }
};
 
int main() {
    int n;
    Solution solution;
    while(cin >> n) {
        cout << solution.calc(n) << endl;
    }
    return 0;
}

/*
https://www.nowcoder.com/questionTerminal/88ddd31618f04514ae3a689e83f3ab8e
自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n以内的自守数的个数
接口说明
功能: 求出n以内的自守数的个数


输入参数：
int n

返回值：
n以内自守数的数量。
*/
