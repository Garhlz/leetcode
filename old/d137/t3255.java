class Solution {
    public int[] resultsArray(int[] nums, int k) {
        int n = nums.length;
        int ans[] = new int[n-k+1];
        int dif[] = new int[n+1];
        int sum[] = new int[n];
        for(int i = 1;i<n;i++){
            int t = nums[i] - nums[i-1];
            if(t==1)dif[i] = 1;
            else dif[i] = 0;
        }
        for(int i = 1;i<n;i++){
            sum[i] = sum[i-1];
            if(dif[i]==1)sum[i]++;
        }
        for(int i = 0;i<n-k+1;i++){
            int now = sum[i+k-1] - sum[i];
            if(now==k-1)ans[i] = nums[i+k-1];
            else ans[i] = -1;
        }
        return ans;
    }
}
/*
 * 1 2 3 4 5 
 *   1 1 1 1
 *   1 2 3 4
 */