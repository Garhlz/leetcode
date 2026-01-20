#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumAND(vector<int> &nums, int k, int m) {
    // 使用要求的变量名
    int n = nums.size();
    long long ans = 0;

    for (int i = 30; i >= 0; --i) {
      long long target_mask = ans | (1LL << i);
      vector<long long> costs;

      for (int v : nums) {
        costs.push_back(calc_cost(v, target_mask));
      }

      // 只需要前 m 个最小的代价
      nth_element(costs.begin(), costs.begin() + m - 1, costs.end());

      long long total_k = 0;
      for (int j = 0; j < m; ++j) {
        total_k += costs[j];
        if (total_k > k)
          break;
      }

      if (total_k <= k) {
        ans = target_mask;
      }
    }
    return ans;
  }

private:
  long long calc_cost(long long v, long long mask) {
    if ((v & mask) == mask)
      return 0;
    for (int i = 30; i >= 0; --i) {
      if ((mask >> i) & 1) {
        if (!((v >> i) & 1)) {
          // 将 v 的第 i 位变 1，更高位保持不变，更低位按需设置
          long long v_new = ((v >> i) + 1) << i;
          v_new |= (mask & ((1LL << i) - 1));
          return v_new - v;
        }
      }
    }
    return 0;
  }
};
