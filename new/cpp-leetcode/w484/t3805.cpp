#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
  string func(string s) {
    int diff = s[0] - 'a';
    for (int i = 0; i < s.size(); i++) {
      s[i] -= diff;
      s[i] -= 'a';
      s[i] = (s[i] + 26) % 26;
      s[i] += 'a';
    }
    return s;
  }
  long long countPairs(vector<string> &words) {
    unordered_map<string, ll> mp;
    ll ans = 0;
    for (const string &s : words) {
      string t = func(s);
      ans += mp[t];
      mp[t]++;
    }
    return ans;
  }
};
