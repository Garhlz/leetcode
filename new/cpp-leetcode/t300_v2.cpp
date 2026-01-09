
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> ans;
        for (auto x : nums) {
            if (ans.empty() || ans.back() < x)
                ans.push_back(x);
            else {
                int l = 0, r = ans.size() - 1;
                while (l <= r) {
                    int m = l + (r - l) / 2;
                    if (x <= ans[m]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
                ans[l] = x;
            }
        }
        return ans.size();
    }
};
