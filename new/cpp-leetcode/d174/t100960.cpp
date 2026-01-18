#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        pair<int, int> bestPos = {-1,-1};
        int bestVal = -1;
        for (const auto& x : towers) {
            int a = x[0], b = x[1], v = x[2];
            if (abs(center[0] - a) + abs(center[1] - b) <= radius) {
                if (v > bestVal) {
                    bestPos = {a, b};
                    bestVal = v;
                } else if (v == bestVal && bestVal != -1) {
                    if (a < bestPos.first || (a == bestPos.first && b < bestPos.second)) {
                        bestPos = {a, b};
                    }
                }
            }
        }
        return vector<int>{bestPos.first, bestPos.second};
    }
};
