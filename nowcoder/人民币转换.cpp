#include <bits/stdc++.h>
 
using namespace std;
 
class Solution {
    vector<string> table = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    vector<string> follow = {"元", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿"};
public:
    string print(double in) {
        string input = to_string(in);
        string res;
        bool bZero = false;
        int pointPos = input.find('.');
        if (pointPos == -1) pointPos = input.size();
        for (int i = 0; i < pointPos; ++i) {
            string cur;
            if (bZero) cur += "零";
            cur += table[input[i] - '0'];
            if (input[i] == '0') {
                bZero = true;
                continue;    // TODO 五百万零二十元
            }
            int d = pointPos - i;
            cur += follow[d-1];
            res += cur;
        }
        string t;
        int i = pointPos;
        if (input.size() - pointPos > 1) {
            if (input[i+1]!= '0') t += table[input[i+1] - '0'] + "角";
        }
        if (input.size() - pointPos > 2) {
            if (input[i+2]!= '0') t += table[input[i+2] - '0'] + "分";
        }
        if (t.empty()) t = "整";
        res += t;
         
        t = res.substr(0, 6);
        //cout << t << ", ";
        if (t == "壹拾") res = res.substr(3, res.size() - 3);
        return "人民币" + res;
    }
};
 
int main() {
    Solution solution;
    double n;
    while(cin >> n) {
        cout << solution.print(n) << endl;
    }
    return 0;
}


/*
链接：https://www.nowcoder.com/questionTerminal/00ffd656b9604d1998e966d555005a4b
来源：牛客网

1、中文大写金额数字前应标明“人民币”字样。中文大写金额数字应用壹、贰、叁、肆、伍、陆、柒、捌、玖、拾、佰、仟、万、亿、元、角、分、零、整等字样填写。（30分）

2、中文大写金额数字到“元”为止的，在“元”之后，应写“整字，如￥ 532.00应写成“人民币伍佰叁拾贰元整”。在”角“和”分“后面不写”整字。（30分）

3、阿拉伯数字中间有“0”时，中文大写要写“零”字，阿拉伯数字中间连续有几个“0”时，中文大写金额中间只写一个“零”字，如￥6007.14，应写成“人民币陆仟零柒元壹角肆分“。（40分）
*/


