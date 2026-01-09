#include <bits/stdc++.h>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        s = " " + s;
        std::unordered_map<char, int> last;
        int cur = 0, ans = 0, st = 1;
        // st表示当前最长字串的开始位置
        for (int i = 1; i < s.size(); i++)
        {

            char c = s[i];
            if (last[c] == 0)
            {
                cur++;
                last[c] = i;
                ans = std::max(ans, cur);
                continue;
            }

            if (last[c] < st)
            {
                cur++;
                last[c] = i;
            }
            else
            {
                cur = i - last[c];
                st = last[c] + 1;
                last[c] = i;
            }
            ans = std::max(ans, cur);
        }
        return ans;
    }
};