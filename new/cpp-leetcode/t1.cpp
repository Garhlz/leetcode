#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int val = it->first;
            if (mp.find(target - val) != mp.end()) {
                if (target == val + val) {
                    return {it->second[0], it->second[1]};
                }
                return {it->second[0], mp[target - val][0]};
            }
        }
        return {};
    }
};
