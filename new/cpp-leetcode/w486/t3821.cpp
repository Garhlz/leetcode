constexpr int MX = 50;
long long comb[MX][MX + 1];
// lambda表达式初始化之后立即调用
auto init = [] {
  for (int i = 0; i < MX; i++) {
    comb[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
  }
  return 0;
}();

class Solution {
public:
  long long nthSmallest(long long n, int k) {
    long long ans = 0;
    for (int i = MX - 1; k > 0; i--) {
      long long c = comb[i][k];
      if (n > c) { // n 比较大，第 i 位必须填 1
        n -= c;
        ans |= (1ll << i);
        k--;
      }
    }
    return ans;
  }
};
