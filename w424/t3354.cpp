#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n);
        a[0] = nums[0];
        for(int i = 1;i<n;i++){
            a[i] = a[i-1] + nums[i];
        }
        int s = a[n-1];
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                int t = abs(a[i] - s + a[i]);
                if(t==0)ans+=2;
                else if(t==1)ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> a = {16,13,10,0,0,0,10,6,7,8,7};
    cout<<s.countValidSelections(a);

}