#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(nums.size());
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> cur(n);
        auto dfs = [&](auto&& self, int index) {
            if (index == n) {
                ans.push_back(cur);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    cur[index] = nums[i];
                    vis[i] = 1;
                    self(self, index + 1);
                    vis[i] = 0;
                }
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};
