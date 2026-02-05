#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i <= 31; i++) {
      vector<int> v;
      for (int n : nums) {
        if (n & (1 << i)) {
          v.push_back(n);
        }
      }
      vector<int> g;
      for (int j = 0; j < v.size(); j++) {
        if (v[j] > g.back()) {
          g.push_back(v[j]);
        } else {
          auto it = lower_bound(g.begin(), g.end(), v[j]);
          int pos = it - g.begin();
          g[pos] = v[j];
        }
      }
      ans = max(ans, (int)g.size());
    }
    return ans;
  }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubsequence(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i <= 31; i++) {
      vector<int> v;
      for (int n : nums) {
        if (n & (1 << i)) {
          v.push_back(n);
        }
      }
      vector<int> g;
      for (int j = 0; j < v.size(); j++) {
        if (g.empty()) {
          g.push_back(v[j]);
          continue;
        }
        if (v[j] > g.back()) {
          g.push_back(v[j]);
        } else {
          auto it = lower_bound(g.begin(), g.end(), v[j]);
          int pos = it - g.begin();
          g[pos] = v[j];
        }
      }
      ans = max(ans, (int)g.size());
    }
    return ans;
  }
};
