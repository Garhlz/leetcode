#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<vector<pair<int,int>>> g(n);
        for(int i = 0;i < edges.size();i++){
            int x = edges[i][0], y = edges[i][1];
            g[x].emplace_back(y, i);
            g[y].emplace_back(x, i);
        }

        vector<int> ans;

        auto dfs = [&](auto&& self, int x, int fa) -> bool {
            bool is_reverse = (start[x] != target[x]);
            for(auto& [y,i] : g[x]){
                if(y == fa)continue;
                if(self(self, y, x)){
                    ans.push_back(i);
                    is_reverse = !is_reverse;
                }
            }
            return is_reverse;
        };

        if(dfs(dfs, 0, -1)){
            return {-1};
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
