#include <bits/stdc++.h>

#include <cstdint>
using namespace std;

class Solution {
public:
    auto maxProfit(vector<int>& arr) -> int {
        int mn = INT32_MAX;
        int mx = INT32_MIN;
        for (int x : arr) {
            mn = min(mn, x);
            mx = max(mx, x - mn);
        }
        return mx;
    }
};
