#include<bits/stdc++.h>
using namespace std;

using pii = array<int,2>;
class Solution {
public:
    int chk(vector<pii>& a,vector<pii>& b,int x){
        int n = a.size();
        int l = 1e9,r = 0;
        for(auto h : a){
            if()
        }
    }

    int minDifference(vector<int>& nums) {
        int n = nums.size();
        vector<pii> a,b;
        int l,r,flag = 0;
        for(int i = 1;i<n;i++){
            if(nums[i]==-1 && nums[i-1]!=-1 && flag){
                l = i-1;flag = 1;
            }
            else if(flag && nums[i]!=-1 && nums[i-1]==-1){
                r = i;flag = 0;
                if(r-l==2)a.push_back({l,r});
                else b.push_back({l,r});
            }
        }
        int mx = 0;
        for(int i = 0;i<n-1;i++){
            mx = max(mx,abs(nums[i+1] - nums[i]));
        }
        int l = mx,r = 2e9;
        while(l+1<r){
            int m = (l+r)/2;
            if(chk(a,b,m))r = m;
            else l = m;
        }
        
    }
};