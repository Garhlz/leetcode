#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int residuePrefixes(string s) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      mp[c]++;
      if (mp.size() == ((i + 1) % 3))
        ans++;
    }
    return ans;
  }
};
