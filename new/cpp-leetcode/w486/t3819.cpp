#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> rotateElements(vector<int> &nums, int k) {
    vector<int> pos;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] >= 0)
        pos.push_back(i);
    }
    if (pos.empty()) {
      return nums;
    }
    vector<int> ans = nums;
    int cnt = pos.size();
    k %= cnt;
    for (int i = 0; i < cnt; i++) {
      ans[pos[i]] = nums[pos[(i + k) % cnt]];
    }
    return ans;
  }
};
