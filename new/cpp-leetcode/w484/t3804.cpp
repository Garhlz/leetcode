#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int centeredSubarrays(vector<int> &nums) {
    int n = nums.size();
    vector<unordered_map<int, int>> mps;
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
      if (i != 0) {
        for (auto [k, v] : mps[i - 1]) {
          mps[i][k] = v;
        }
      }
      mps[i][nums[i]]++;
      pre[i] = nums[i];
      if (i != 0)
        pre[i] += pre[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int s;
        if (i == 0)
          s = pre[j];
        else
          s = pre[j] - pre[i - 1];

        if (i == 0) {
          if (mps[j][s] != 0)
            ans++;
        } else {
          if (mps[j][s] - mps[i - 1][s] != 0)
            ans++;
        }
      }
    }
    return ans;
  }
};
