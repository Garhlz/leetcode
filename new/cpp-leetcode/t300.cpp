#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   int lengthOfLIS(vector<int>& nums) {
       if(nums.empty())return 0;
       vector<int> ans;
       for(auto x : nums){
           if(ans.empty() || ans.back() < x)ans.push_back(x);
           else{
               auto it = lower_bound(ans.begin(), ans.end(), x);
               *it = x; 
           }
       }
       return ans.size();
   }
};
