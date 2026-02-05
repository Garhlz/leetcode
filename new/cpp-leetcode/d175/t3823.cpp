#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string reverseByType(string s) {
    vector<int> pos1, pos2;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        pos1.push_back(i);
      } else
        pos2.push_back(i);
    }
    for (int i = 0; i < pos1.size() / 2; i++) {
      swap(s[pos1[i]], s[pos1[pos1.size() - 1 - i]]);
    }
    for (int i = 0; i < pos2.size() / 2; i++) {
      swap(s[pos2[i]], s[pos2[pos2.size() - 1 - i]]);
    }
    return s;
  }
};
