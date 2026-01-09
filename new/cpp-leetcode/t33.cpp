#include <bits/stdc++.h>
using namespace std;
// 因为有一半一定是有序的，只需要通过这一半查看需要查找的目标是否在其中。
// 如果在，就进入这一半。否则去另一半查找
// 
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if(nums[m] == target){
        return m;
      }
      if (nums[l] <= nums[m]) { // 左侧是单调的
        if (nums[l] <= target && target <= nums[m]) {
          r = m - 1;
        } else
          l = m + 1;
      } else {
        if (nums[m] <= target && target <= nums[r]) {
          l = m + 1;
        } else
          r = m - 1;
      }
    }
    return -1; 
  }
};
