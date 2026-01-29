#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string lexSmallestAfterDeletion(string s) {
    int left[26]{};
    for (char c : s) {
      left[c - 'a']++;
    }
    int top = -1;
    for (char c : s) {
      while (top >= 0 && c < s[top] && left[s[top] - 'a'] > 1) {
        left[s[top] - 'a']--;
        top--; // 出栈
      }
      s[++top] = c;
    }

    while (top >= 0 && left[s[top] - 'a'] > 1) {
      left[s[top] - 'a']--;
      top--;
    }

    s.resize(top + 1);
    return s;
  }
};
