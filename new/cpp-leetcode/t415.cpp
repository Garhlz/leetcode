#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        auto vec1 = read(num1);
        auto vec2 = read(num2);
        return add_vec(vec1, vec2);
    }

    vector<int> read(const string& s) {
        vector<int> ret;
        ret.push_back(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            ret.push_back(s[i] - '0');
        }
        ret.push_back(0);
        return ret;
    }

    string add_vec(vector<int>& x, vector<int>& y) {
        if (x[0] < y[0]) swap(x, y);
        for (int i = 1; i <= y[0] + 1; i++) {
            x[i] += y[i];
        }
        for (int i = 1; i < x.size() - 1; i++) {
            x[i + 1] += x[i] / 10;
            x[i] %= 10;
        }
        while (x.back() == 0) x.pop_back();
        if (x.size() == 1) return "0";
        string s = "";
        for (int i = x.size() - 1; i >= 1; i--) {
            s += x[i] + '0';
        }
        return s;
    }
};
