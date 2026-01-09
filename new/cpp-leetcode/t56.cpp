#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        vector<vector<int>> ans;

        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            const auto& cur = intervals[i];
            if (cur[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], cur[1]);
            } else {
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
