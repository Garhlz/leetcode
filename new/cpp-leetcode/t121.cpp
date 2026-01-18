#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> diff(n), dp(n);
        for(int i = 1;i < n;i++){
            diff[i] = prices[i] - prices[i-1];
        }
        int ans = 0;
        for(int i = 1;i < n;i++){
            dp[i] = max(diff[i], diff[i] + dp[i-1]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
