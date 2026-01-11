#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> heights(100005);
        vector<pair<int, int>> bounds(100005, (pair<int, int>){n, -1});
        int mx = 0;
        for (int i = 0; i < n; i++) {
            heights[height[i]]++;
            mx = max(mx, height[i]);
            bounds[height[i]].first = min(bounds[height[i]].first, i);
            bounds[height[i]].second = max(bounds[height[i]].second, i);
        }
        int ans = 0;
        for (int i = mx; i >= 0; i--) {
            if (i < mx) {
                heights[i] += heights[i + 1];
                bounds[i].first = min(bounds[i].first, bounds[i + 1].first);
                bounds[i].second = max(bounds[i].second, bounds[i + 1].second);
            }
            ans += bounds[i].second - bounds[i].first + 1 - heights[i];
        }
        return ans;
    }
};

// int main(){
//     auto s = new Solution();
//     vector<int> input = {4,2,0,3,2,5};
//     cout<<s->trap(input)<<endl;
//     return 0;
// }
