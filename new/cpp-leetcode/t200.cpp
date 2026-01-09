#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
  int n, m;

public:
  int numIslands(vector<vector<char>> &grid) {
    n = grid.size();
    m = grid[0].size();
    int ans = 0;

    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};

    auto dfs = [&](auto &&self, int x, int y) -> void {
      grid[x][y] = '0';
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1') {
          self(self, nx, ny);
        }
      }
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '1') {
          ans++;
          dfs(dfs, i, j);
        }
      }
    }
    return ans;
  }
};
