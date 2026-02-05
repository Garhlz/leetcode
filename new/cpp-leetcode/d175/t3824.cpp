#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

// 记住，向上取整可以用ceil(a,b) = (a + b - 1) / b

class Solution {
public:
  int minimumK(vector<int> &nums) {
    int mx = INT32_MAX;
    auto check = [&](int n) -> bool {
      long long ops = 0;
      for (int t : nums) {
        ops += (t + n - 1) / n;
      }
      return ops <= (long long)n * n;
    };
    int l = 1, r = mx;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (check(m)) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
