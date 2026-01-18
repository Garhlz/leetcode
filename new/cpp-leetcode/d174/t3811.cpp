#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        unordered_map<int, int> mp1, mp2;
        int sum = 0;
        mp1[0] = 0, mp2[0] = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            int x = nums[i];
            sum ^= x;
            int tmp1 = (mp1[sum] + mp2[sum ^ target1]) % MOD;
            int tmp2 = (mp2[sum] + mp1[sum ^ target2]) % MOD;
            mp1[sum] = tmp1;
            mp2[sum] = tmp2;
        }
        sum ^= nums.back();
        return mp1[sum ^ target2] + mp2[sum ^ target1];
    }
};
