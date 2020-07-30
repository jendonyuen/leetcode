#include <bits/stdc++.h>

using namespace std;

bool solution(string &input) {
    if (input.size() < 7 || input.size() > 15) {
        return false;
    }
    vector<string> cols;
    string cur;
    int pointCount = 3;
    int n = input.size();
    for (int i = 0; i < n; ++i) {
        if (input[i] == '.') {
            if (pointCount-- <= 0 || cur.size() > 3 || cur.empty()) return false;
            cols.push_back(cur);
            cur.clear();
        } else if (input[i] < '0' || input[i] > '9') {
            return false;
        } else {
            cur.push_back(input[i]);
        }
    }
    if (cur.size() > 3 || cur.empty()) return false;
    cols.push_back(cur);
    if (cols.size() != 4) return false;
    for (auto &col : cols) {
        if (stoi(col) > 255) return false;
    }
    return true;
}

int main() {
    string input;
    while (getline(cin, input)) {
        if (solution(input)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" <<endl;
        }
    }
}