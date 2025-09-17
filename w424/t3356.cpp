#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int chk(vector<int>& nums,vector<vector<int>>& queries,int x){
        int n = nums.size(),k = queries.size();
        vector<int> a(n+1);
        for(int i = 0;i<x;i++){
            int val = queries[i][2];
            a[queries[i][0]] += val;
            a[queries[i][1]+1] -= val;
        }
        for(int i = 1;i<n;i++){
            a[i]+=a[i-1];
        }
        for(int i = 0;i<n;i++)if(a[i] < nums[i])return 0;
        return 1;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(),k = queries.size();
        int l = 0,r = k;
        while(l+1 < r){
            int m = l+r>>1;
            if(chk(nums,queries,m)){
                r = m;
            }
            else l = m;
        }
        if(chk(nums,queries,l))return l;
        else if(chk(nums,queries,r))return r ;
        else return -1;
    }
};


int main()
{
    // vector<int> a = {2,0,2};
    // vector<vector<int>> b = {{0,2,1},{0,2,1},{1,1,3}};
    vector<int> a = {4,3,2,1};
    vector<vector<int>> b = {{1,3,2},{0,2,1}};
    Solution s;
    cout<<s.minZeroArray(a,b)<<'\n';
}