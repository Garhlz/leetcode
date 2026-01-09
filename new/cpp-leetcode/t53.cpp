#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int mn = 0, now = 0, ans = nums[0];
    for(int i = 0;i < nums.size();i++){
      now += nums[i];
      ans = max(ans, now - mn);
      mn = min(mn, now);
    }
    return ans;
  }
};
