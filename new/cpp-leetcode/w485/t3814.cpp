#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget) {
    int n = costs.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
      if (costs[i] < budget)
        arr.emplace_back(costs[i], capacity[i]);
    }
    n = arr.size();
    sort(arr.begin(), arr.end(),
         [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });
    vector<int> mx(n + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      mx[i] = max(mx[i - 1], arr[i - 1].second);
    }
    for (int i = 0; i < n; i++) {
      if (arr[i].first < budget) {
        ans = max(ans, arr[i].second);
      }
    }
    int l = 0;
    for (int r = n - 1; r >= 0; r--) {
      while (l < r && arr[l].first + arr[r].first < budget)
        l++;
      ans = max(ans, mx[min(r, l)] + arr[r].second);
    }
    return ans;
  }
};
