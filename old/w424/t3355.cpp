#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> a(n+1),b(n);
        for(auto h : queries){
            a[h[0]]++;
            a[h[1] + 1]--;
        }
        b[0] = a[0];
        for(int i = 1;i<n;i++){
            b[i] = b[i-1] + a[i];
        }
        for(int i = 0;i<n;i++){
            if(b[i] < nums[i])return false;
        }
        return true;
    }
};