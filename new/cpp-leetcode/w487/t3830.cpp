#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestAlternating(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, 0)));
        // 以i为结尾的最长的交替子数组的长度, j=0表示当前使用了0次删除，1表示用了1次
        // k=0 上一个较小
        dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = 1;
        for (int i = 1; i < n; i++)
        {
            // j = 0;
            if (nums[i - 1] < nums[i])
            {
                dp[i][0][0] = dp[i - 1][0][1] + 1;
                dp[i][0][1] = 1;
            }
            else if (nums[i - 1] > nums[i])
            {
                dp[i][0][1] = dp[i - 1][0][0] + 1;
                dp[i][0][0] = 1;
            }
            else
            {
                dp[i][0][0] = dp[i][0][1] = 1;
            }

            // j = 1
            // 继承i - 1;
            if (nums[i - 1] < nums[i])
            {
                dp[i][1][0] = max(max(dp[i - 1][0][1], dp[i - 1][1][1]) + 1, dp[i][1][0]);
                dp[i][1][1] = max(1, dp[i][1][1]);
            }
            else if (nums[i - 1] > nums[i])
            {
                dp[i][1][1] = max(max(dp[i - 1][0][0], dp[i - 1][1][0]) + 1, dp[i][1][1]);
                dp[i][1][0] = max(1, dp[i][1][0]);
            }
            else
            {
                dp[i][1][1] = max(1, dp[i][1][1]);
                dp[i][1][0] = max(1, dp[i][1][0]);
            }

            // 继承i - 2, 在此处使用一次机会
            if (i - 2 >= 0)
            {
                if (nums[i - 2] < nums[i])
                {
                    dp[i][1][0] = max(dp[i - 2][0][1] + 1, dp[i][1][0]);
                }
                else if (nums[i - 1] > nums[i])
                {
                    dp[i][1][1] = max(dp[i - 2][0][0] + 1, dp[i][1][1]);
                }
            }
        }
        return max(max(dp[n - 1][0][0], dp[n - 1][0][1]), max(dp[n - 1][1][0], dp[n - 1][1][1]));
    }
};