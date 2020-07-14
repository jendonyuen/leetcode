// 字符串除法, 保留20位小数
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

// 求过两点的直线
// Ax + By + C = 0
// A = y2 - y1
// B = x1 - x2
// C = x2*y1 - x1*y2
string getLine(vector<int>& p1, vector<int>& p2) {
    long long a, b, c, x1 = p1[0], x2 = p2[0], y1 = p1[1], y2 = p2[1];
    a = y2 - y1;
    b = x1 - x2;
    c = x2 * y1 - x1 * y2;
    // 归一化
    // cout << mod((a-c), a) << "     " << mod((b-c), a) << endl;
    if (a == 0 && b == 0) return to_string(p1[0])+","+to_string(p1[1])+"0"; // 两点相等, 返回x,y,0 
    if (a == 0) return{mod((b-c), b)};                                      // 直线水平, 返回b
    return mod((a-c), a)+","+mod((b-c), a);                                 // 返回a,b
    
}

// 对10^9 + 7 取模
fmod(res, 1000000007);
/*
const int kMOD = 1e9 + 7;
res %= kMOD;
*/


// 辗转相除法求最大公因数
int gcd(int a, int b) {
    if (a < b) std::swap(a, b);
    return b == 0 ? a : gcd(b, a % b);
}