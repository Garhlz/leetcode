#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minimumPrefixLength(vector<int> &nums) {
    int n = nums.size();
    vector<int> dif(n);
    for (int i = 1; i < n; i++) {
      dif[i] = nums[i] - nums[i - 1];
    }
    int ans = 0;
    for (int i = n - 1; i >= 1; i--) {
      if (dif[i] > 0)
        ans++;
      else
        break;
    }

    ans++;
    return n - ans;
  }
};
