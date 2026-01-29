#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int specialNodes(int n, vector<vector<int>> &edges, int x, int y, int z) {
    vector<vector<int>> v(n, vector<int>());
    for (const auto &vec : edges) {
      int x = vec[0], y = vec[1];
      v[x].push_back(y);
      v[y].push_back(x);
    }
    vector<vector<int>> dis(3, vector<int>(n));
    auto dfs = [&](auto &&self, int root, int fa, int num, int dep) -> void {
      dis[num][root] = dep;
      for (int y : v[root]) {
        if (y == fa)
          continue;
        self(self, y, root, num, dep + 1);
      }
    };
    dfs(dfs, x, -1, 0, 0);
    dfs(dfs, y, -1, 1, 0);
    dfs(dfs, z, -1, 2, 0);

    int ans = 0;

    for (int i = 0; i < n; i++) {
      long long t1 = dis[0][i], t2 = dis[1][i], t3 = dis[2][i];
      if (t1 > t2)
        swap(t1, t2);
      if (t2 > t3)
        swap(t2, t3);
      if (t1 > t2)
        swap(t1, t2);
      if (t1 * t1 + t2 * t2 == t3 * t3)
        ans++;
    }
    return ans;
  }
};
