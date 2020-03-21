using std::pair;
using std::make_pair;

class Solution {
    map<pair<int, int>, bool> status;
    int x, y;
public:
    bool canMeasureWater(int x, int y, int z) {
        /*
        this->x = x;
        this->y = y;
        if (x+y < z) return false;
        return pourWater(0, 0, z);
        */
        return solution2(x, y, z);

    }
    bool solution2(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return x + y == z || z == 0;
        cout << gcd(x, y) << endl;
        return z % gcd(x, y) == 0;
    }

    // 辗转相除法求最大公因数
    int gcd(int a, int b) {
        if (a < b) std::swap(a, b);
        return b == 0 ? a : gcd(b, a % b);
    }

    /*
    // 递归调用, 次数较多是栈空间溢出 
    // 测试用例通过21/34;
    // 最后x=22003, y=31237, z=123时溢出
    bool pourWater(int curX, int curY, int z) {
        if (curX == z || curY == z || curX + curY == z) return true;
        auto current = make_pair(curX, curY);
        if (status.find(current) != status.end()) return false; // 若出现相同状态则已进入循环, 返回false
        status[current] = false;
        bool r1 = pourWater(0, curY, z);    // 把x倒空
        bool r2 = pourWater(curX, 0, z);    // 把y倒空
        bool r3 = pourWater(x, curY, z);    // 把x倒满
        bool r4 = pourWater(curX, y, z);    // 把y倒满
        // 将x中的水倒入y中
        auto newX = curX - (y - curY) < 0 ? 0 : curX - (y - curY);
        auto newY = curY + curX > y ? y : curY + curX;
        // cout << curX << ":" << curY << " ==> " << newX << ":" << newY << endl;
        bool r5 = pourWater(newX, newY, z);
        // 将y中的水倒入x中
        newY = curY - (x - curX) < 0 ? 0 : curY - (x - curX);   // 新的y中的水 = 当前y中的水 - (x能装的水)
        newX = curX + curY > x ? x : curX + curY;               // 新的x中的水 = 当前x中的水 + y能倒过来的水
        // cout << curX << ":" << curY << " ==> " << newX << ":" << newY << endl;
        bool r6 = pourWater(newX, newY, z);
        return r1 || r2 || r3 || r4 || r5 || r6;
    }
    */
};